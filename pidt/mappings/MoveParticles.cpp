#include "particles/pidt/mappings/MoveParticles.h"
#include "particles/Particles.h"
#include "peano/utils/Loop.h"
#include "tarch/multicore/Loop.h"
#include "tarch/multicore/BooleanSemaphore.h"
#include "tarch/multicore/Lock.h"


#ifdef Asserts
peano::MappingSpecification   particles::pidt::mappings::MoveParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
#else
peano::MappingSpecification   particles::pidt::mappings::MoveParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
#endif

peano::MappingSpecification   particles::pidt::mappings::MoveParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::OnlyLeaves,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::MoveParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::OnlyLeaves,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::MoveParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::MoveParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::MoveParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pidt::mappings::MoveParticles::_log( "particles::pidt::mappings::MoveParticles" ); 




void particles::pidt::mappings::MoveParticles::reflectParticle( particles::pidt::records::Particle& particle ) {
  const double lowerBound = SizeOfHaloLayer;
  const double upperBound = 1.0-SizeOfHaloLayer;

  for (int d=0; d<DIMENSIONS; d++) {
    if (particle._persistentRecords._x(d)<lowerBound) {
      logDebug( "reflectParticle(...)", "reflected " << particle.toString() );
      particle._persistentRecords._x(d) = lowerBound + (lowerBound - particle._persistentRecords._x(d));
      particle._persistentRecords._v(d) = -particle._persistentRecords._v(d);
      logDebug( "reflectParticle(...)", "   into " << particle.toString() );
    }
    if (particle._persistentRecords._x(d)>upperBound) {
      logDebug( "reflectParticle(...)", "reflected " << particle.toString() );
      particle._persistentRecords._x(d) = upperBound - (particle._persistentRecords._x(d) - upperBound);
      particle._persistentRecords._v(d) = -particle._persistentRecords._v(d);
      logDebug( "reflectParticle(...)", "   into " << particle.toString() );
    }
  }
}


void particles::pidt::mappings::MoveParticles::beginIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  _state = solverState;
  _state.clearStatistics();
  ParticleHeap::getInstance().startToSendBoundaryData(solverState.isTraversalInverted());

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pidt::mappings::MoveParticles::endIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "endIteration(State)", solverState );

  logInfo( "endIteration(State)", "particles-local=" << _state.getNumberOfParticles() );

  solverState.reduceStateStatistics( _state );
  ParticleHeap::getInstance().finishedToSendBoundaryData(solverState.isTraversalInverted());

  logTraceOutWith1Argument( "endIteration(State)", solverState);
}


#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::MoveParticles::MoveParticles(const MoveParticles&  masterThread):
  _state(masterThread._state) {
  _state.clearStatistics();
}


void particles::pidt::mappings::MoveParticles::mergeWithWorkerThread(const MoveParticles& workerThread) {
  _state.reduceStateStatistics(workerThread._state);
}
#endif



void particles::pidt::mappings::MoveParticles::touchVertexFirstTime(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "touchVertexFirstTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  #ifdef Parallel
  if (fineGridVertex.isAdjacentToRemoteRank()) {
    fineGridVertex.particlesWereAddedToThisVertex();
  }
  else {
    fineGridVertex.noParticlesWereAddedToThisVertex();
  }
  #else
  fineGridVertex.noParticlesWereAddedToThisVertex();
  #endif

  const int vertexIndex = fineGridVertex.getVertexIndex();
  typedef std::vector<particles::pidt::records::Particle>  ParticleContainer;
  ParticleContainer& sourceVertexParticles = ParticleHeap::getInstance().getData(vertexIndex);

  pfor(i,0,static_cast<int>(sourceVertexParticles.size()),100)
    particles::pidt::records::Particle& currentParticle = sourceVertexParticles.at(i);
    assertion(
      currentParticle.getMovedParticle() == particles::pidt::records::Particle::New ||
      currentParticle.getMovedParticle() == particles::pidt::records::Particle::Moved
    );
    assertion1(
      tarch::la::allGreaterEquals(currentParticle._persistentRecords._x,0.0),
      currentParticle.toString()
    );
    assertion1(
      tarch::la::allSmallerEquals(currentParticle._persistentRecords._x,1.0),
      currentParticle.toString()
    );

    currentParticle.setMovedParticle( particles::pidt::records::Particle::NotMovedYet );
  endpfor

  logTraceOutWith1Argument( "touchVertexFirstTime(...)", fineGridVertex );
}




void particles::pidt::mappings::MoveParticles::leaveCell(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "leaveCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  double maxVComponentInCell = 0.0;

  dfor2(k)
    const int sourceVertexIndex = fineGridVertices[ fineGridVerticesEnumerator(k) ].getVertexIndex();

    ParticleHeap::HeapEntries& sourceVertexParticles = ParticleHeap::getInstance().getData(sourceVertexIndex);

    for (
      ParticleHeap::HeapEntries::iterator p = sourceVertexParticles.begin();
      p!=sourceVertexParticles.end();
    ) {
      const tarch::la::Vector<DIMENSIONS,int> newDualCellOfParticle = Vertex::getDualCellOfParticle(
        fineGridVerticesEnumerator,
        p->_persistentRecords._x
      );

      const double maxVComponentOfParticle = tarch::la::maxAbs(p->_persistentRecords._v);
      maxVComponentInCell = maxVComponentInCell > maxVComponentOfParticle ? maxVComponentInCell : maxVComponentOfParticle;

      const bool MoveParticleToDifferentDualCell = newDualCellOfParticle!=k;
      if (MoveParticleToDifferentDualCell) {
        Vertex& newVertexOfParticles = fineGridVertices[ fineGridVerticesEnumerator(newDualCellOfParticle) ];
        newVertexOfParticles.particlesWereAddedToThisVertex();
        const int destinationVertexIndex = newVertexOfParticles.getVertexIndex();
        ParticleHeap::getInstance().getData(destinationVertexIndex).push_back(*p);
        p = ParticleHeap::getInstance().getData(sourceVertexIndex).erase(p);
        logDebug( "leaveCell(...)", "reassign particle " << p->toString() << " to vertex " << newDualCellOfParticle );
      }
      else {
        p++;
      }
    }
  enddforx

  if (!fineGridCell.isRefined()) {
    fineGridCell.setMaxVComponent( maxVComponentInCell );
  }

  logTraceOut( "leaveCell(...)" );
}


int particles::pidt::mappings::MoveParticles::moveParticlesOfOneVertexWithinCell(
  int                                   vertexIndex,
  const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator
) {
  #if defined(SharedTBB) && !defined(__WIN32__)
  tbb::atomic<int>     numberOfParticlesMoved;
  #elif SharedOMP
    #error not implemented yet
  #else
  int    numberOfParticlesMoved;
  #endif

  numberOfParticlesMoved = 0;

  ParticleHeap::HeapEntries& sourceVertexParticles = ParticleHeap::getInstance().getData(vertexIndex);
  pfor(i,0,static_cast<int>(sourceVertexParticles.size()),200)
    particles::pidt::records::Particle& currentParticle = sourceVertexParticles.at(i);

    const bool particleHasNotBeenMovedYet =
      currentParticle.getMovedParticle() != particles::pidt::records::Particle::Moved;

    const bool particleIsContainedInCell = fineGridVerticesEnumerator.overlaps(
      currentParticle._persistentRecords._x,
      0.0
    );

    if (particleHasNotBeenMovedYet && particleIsContainedInCell) {
      currentParticle._persistentRecords._x             += (_state.getTimeStepSize() * currentParticle._persistentRecords._v);
      currentParticle.setMovedParticle( particles::pidt::records::Particle::Moved );

      reflectParticle(currentParticle);

      numberOfParticlesMoved++;
    }
  endpfor

  return numberOfParticlesMoved;
}



int particles::pidt::mappings::MoveParticles::moveParticlesOfOneVertexWithinCellIfTheyAreSorted(
  int                                   vertexIndex,
  const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator
) {
  ParticleHeap::HeapEntries& sourceVertexParticles = ParticleHeap::getInstance().getData(vertexIndex);

  int numberOfParticlesMoved = 0;

  int biggestIndexPointingToUnmovedParticle  = static_cast<int>(sourceVertexParticles.size())-1;
  int smallestIndexPointingToUnmovedParticle = 0;

  while (
    biggestIndexPointingToUnmovedParticle>=0 &&
    sourceVertexParticles.at(biggestIndexPointingToUnmovedParticle).getMovedParticle() == particles::pidt::records::Particle::Moved
  ) {
    biggestIndexPointingToUnmovedParticle--;
  }

  #ifdef Asserts
  for (int i=0; i<biggestIndexPointingToUnmovedParticle; i++) {
    assertion3(
      sourceVertexParticles.at(i).getMovedParticle() != particles::pidt::records::Particle::Moved,
      i,
      biggestIndexPointingToUnmovedParticle,
      sourceVertexParticles.at(i).toString()
    );
  }
  #endif

  logDebug(
    "moveParticlesOfOneVertexWithinCellIfTheyAreSorted(...)",
    "moved index from " << static_cast<int>(sourceVertexParticles.size())-1 <<
    " to " << biggestIndexPointingToUnmovedParticle <<
    ": " << sourceVertexParticles.at(biggestIndexPointingToUnmovedParticle).toString() <<
    " with first element " << sourceVertexParticles.at(smallestIndexPointingToUnmovedParticle).toString()
  );

  // has to be equals as the two might just have been exchanged
  while (biggestIndexPointingToUnmovedParticle >= smallestIndexPointingToUnmovedParticle) {
    particles::pidt::records::Particle& currentParticle = sourceVertexParticles.at(smallestIndexPointingToUnmovedParticle);

    assertion( biggestIndexPointingToUnmovedParticle>=0 );
    assertion( smallestIndexPointingToUnmovedParticle>=0 );
    assertion( biggestIndexPointingToUnmovedParticle<static_cast<int>(sourceVertexParticles.size()) );
    assertion( smallestIndexPointingToUnmovedParticle<static_cast<int>(sourceVertexParticles.size()) );

    assertion4(
      currentParticle.getMovedParticle() != particles::pidt::records::Particle::Moved ||
      (smallestIndexPointingToUnmovedParticle==biggestIndexPointingToUnmovedParticle),
      smallestIndexPointingToUnmovedParticle,
      biggestIndexPointingToUnmovedParticle,
      sourceVertexParticles.at(smallestIndexPointingToUnmovedParticle).toString(),
      sourceVertexParticles.at(biggestIndexPointingToUnmovedParticle).toString()
    );

    const bool particleIsContainedInCell = fineGridVerticesEnumerator.overlaps(
      currentParticle._persistentRecords._x,
      0.0
    );

    if (particleIsContainedInCell) {
      currentParticle._persistentRecords._x             += (_state.getTimeStepSize() * currentParticle._persistentRecords._v);
      currentParticle.setMovedParticle( particles::pidt::records::Particle::Moved );
      reflectParticle(currentParticle);

      if (smallestIndexPointingToUnmovedParticle!=biggestIndexPointingToUnmovedParticle) {
        particles::pidt::records::Particle tmp                        =  currentParticle;
        currentParticle                                               =  sourceVertexParticles.at(biggestIndexPointingToUnmovedParticle);
        sourceVertexParticles[biggestIndexPointingToUnmovedParticle]  =  tmp;
      }

      numberOfParticlesMoved++;
      biggestIndexPointingToUnmovedParticle--;
    }
    else {
      smallestIndexPointingToUnmovedParticle++;
    }
  }

  return numberOfParticlesMoved;
}


void particles::pidt::mappings::MoveParticles::enterCell(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  if (fineGridCell.isRefined()) {
    fineGridCell.clearMaxVComponent();
  }
  else {
    #if defined(SharedTBB) && !defined(__WIN32__)
    tbb::atomic<int>     numberOfParticlesMoved;
    #elif defined(SharedTBB) && defined(__WIN32__)
    static tarch::multicore::BooleanSemaphore  semaphore;
    int    numberOfParticlesMoved;
    #elif SharedOMP
      #error not implemented yet
    #else
    int    numberOfParticlesMoved;
    #endif
    numberOfParticlesMoved = 0;

    pdfor2(k)
      const int sourceVertexIndex = fineGridVertices[ fineGridVerticesEnumerator(k) ].getVertexIndex();

      #ifdef MOVE_USES_SORTED_PARTICLES
      const int resultOfOneVertex = moveParticlesOfOneVertexWithinCellIfTheyAreSorted(
        sourceVertexIndex,
        fineGridVerticesEnumerator
      );
      #else
      const int resultOfOneVertex = moveParticlesOfOneVertexWithinCell(
        sourceVertexIndex,
        fineGridVerticesEnumerator
      );
      #endif

      #if defined(SharedTBB) && defined(__WIN32__)
      tarch::multicore::Lock lock(semaphore);
      #endif
      numberOfParticlesMoved += resultOfOneVertex;
    endpdforx

    _state.updateParticleStatisticsInLeaf(numberOfParticlesMoved,fineGridVerticesEnumerator.getCellSize());
  }

  logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


void particles::pidt::mappings::MoveParticles::ascend(
  particles::pidt::Cell * const         fineGridCells,
  particles::pidt::Vertex * const       fineGridVertices,
  const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
  particles::pidt::Vertex * const       coarseGridVertices,
  const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
  particles::pidt::Cell&                coarseGridCell
) {
  logTraceIn( "ascend(...)" );

  dfor3(i)
    coarseGridCell.restrictMaxVComponent( fineGridCells[ fineGridVerticesEnumerator.cell(i) ] );
  enddforx

  logTraceOut( "ascend(...)" );
}



#ifdef Parallel
void particles::pidt::mappings::MoveParticles::mergeWithNeighbour(
  particles::pidt::Vertex&                      vertex,
  const particles::pidt::Vertex&                neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
  logTraceInWith6Arguments( "mergeWithNeighbour(...)", vertex, neighbour, fromRank, fineGridX, fineGridH, level );

  #if defined(Asserts) || defined(Asserts)
  const int receiveEntries =
  #endif
  ParticleHeap::getInstance().receiveData(
    vertex.getVertexIndex(),
    fromRank,
    fineGridX,
    level,
    peano::heap::NeighbourCommunication
  );

  #ifdef Asserts
  for (
    ParticleHeap::HeapEntries::const_iterator p = ParticleHeap::getInstance().getData(vertex.getVertexIndex()).begin();
    p != ParticleHeap::getInstance().getData(vertex.getVertexIndex()).end();
    p++
  ) {
    assertion8(
      Vertex::isContainedInDualCell(fineGridX,fineGridH,p->_persistentRecords._x),
      fineGridX,fineGridH,p->toString(),p->_persistentRecords._x - fineGridX,level,
      vertex.toString(), fromRank, receiveEntries
    );

    const int  whichAdjacentCellHoldsParticle =
      peano::utils::dLinearised(Vertex::getDualCellOfParticle(fineGridX,p->_persistentRecords._x),2);

    const bool particleIsOnLocalRank = vertex.getAdjacentRanks()(whichAdjacentCellHoldsParticle)==tarch::parallel::Node::getInstance().getRank();

    assertion8(
      particleIsOnLocalRank,
      fineGridX,fineGridH,p->toString(),p->_persistentRecords._x - fineGridX,level,
      vertex.toString(), fromRank, receiveEntries
    );
  }
  #endif

  logTraceOutWith1Argument( "mergeWithNeighbour(...)", receiveEntries );
}


particles::pidt::mappings::MoveParticles::ParticleContainer  particles::pidt::mappings::MoveParticles::extractAllParticlesFromDualCellBelongingToOneRank(
  int                                           sourceHeapIndex,
  particles::pidt::Vertex&                      vertex,
  int                                           rank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h
) {
  ParticleContainer  destinationParticles;

  ParticleContainer& localVertexParticles = ParticleHeap::getInstance().getData(sourceHeapIndex);

  for (
    ParticleContainer::iterator p = localVertexParticles.begin();
    p!=localVertexParticles.end();
  ) {
    const bool particleDoesNotTunnel = Vertex::isContainedInDualCell(x,h,p->_persistentRecords._x);

    const int  whichAdjacentCellHoldsParticle =
      peano::utils::dLinearised(Vertex::getDualCellOfParticle(x,p->_persistentRecords._x),2);

    const bool particleBelongsToNeighbouringRank = vertex.getAdjacentRanks()(whichAdjacentCellHoldsParticle)==rank;

    if (particleDoesNotTunnel && particleBelongsToNeighbouringRank) {
      destinationParticles.push_back(*p);
      p = localVertexParticles.erase(p);
    }
    else {
      p++;
    }
  }

  return destinationParticles;
}


void particles::pidt::mappings::MoveParticles::prepareSendToNeighbour(
  particles::pidt::Vertex&                      vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith5Arguments( "prepareSendToNeighbour(...)", vertex, toRank, x, h, level );

  ParticleContainer  destinationParticles = extractAllParticlesFromDualCellBelongingToOneRank(
    vertex.getVertexIndex(),
    vertex,
    toRank,
    x,
    h
  );

  for (
    ParticleContainer::iterator p = destinationParticles.begin();
    p != destinationParticles.end();
    p++
  ) {
    p->setMovedParticle( particles::pidt::records::Particle::New );

    assertion5(
      Vertex::isContainedInDualCell(x,h,p->_persistentRecords._x),
      x,h,p->toString(),p->_persistentRecords._x - x,level
    );
  }

  ParticleHeap::getInstance().sendData(
    destinationParticles,
    toRank,
    x,
    level,
    peano::heap::NeighbourCommunication
  );

  logTraceOutWith1Argument( "prepareSendToNeighbour(...)", destinationParticles.size() );
}


void particles::pidt::mappings::MoveParticles::mergeWithMaster(
  const particles::pidt::Cell&              workerGridCell,
  particles::pidt::Vertex * const           workerGridVertices,
  const peano::grid::VertexEnumerator&      workerEnumerator,
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker,
  const particles::pidt::State&             workerState,
  particles::pidt::State&                   masterState
) {
  logTraceIn( "mergeWithMaster(...)" );

  masterState.reduceStateStatistics(workerState);

  fineGridCell.clearMaxVComponent();
  fineGridCell.restrictMaxVComponent(workerGridCell);

  logTraceOut( "mergeWithMaster(...)" );
}
#endif




void particles::pidt::mappings::MoveParticles::touchVertexLastTime(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  for (
    ParticleHeap::HeapEntries::const_iterator p = ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex()).begin();
    p != ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex()).end();
    p++
  ) {
    assertion4(
      p->getMovedParticle() == particles::pidt::records::Particle::Moved,
      p->toString(), fineGridVertex.toString(),
      fineGridX, fineGridH
    );
  }
}


//
// NOP
//=====
//
particles::pidt::mappings::MoveParticles::MoveParticles() {
}


particles::pidt::mappings::MoveParticles::~MoveParticles() {
}


void particles::pidt::mappings::MoveParticles::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::MoveParticles::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::MoveParticles::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::MoveParticles::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::MoveParticles::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::MoveParticles::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::MoveParticles::destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


#ifdef Parallel
void particles::pidt::mappings::MoveParticles::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::mappings::MoveParticles::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pidt::mappings::MoveParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pidt::mappings::MoveParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


bool particles::pidt::mappings::MoveParticles::prepareSendToWorker(
  particles::pidt::Cell&                 fineGridCell,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  return false;
}


void particles::pidt::mappings::MoveParticles::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&         verticesEnumerator,
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfCell
) {
}


void particles::pidt::mappings::MoveParticles::receiveDataFromMaster(
      particles::pidt::Cell&                        receivedCell, 
      particles::pidt::Vertex *                     receivedVertices,
      const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
      particles::pidt::Vertex * const               receivedCoarseGridVertices,
      const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
      particles::pidt::Cell&                        receivedCoarseGridCell,
      particles::pidt::Vertex * const               workersCoarseGridVertices,
      const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
      particles::pidt::Cell&                        workersCoarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
}


void particles::pidt::mappings::MoveParticles::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pidt::mappings::MoveParticles::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}
#endif


void particles::pidt::mappings::MoveParticles::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}
