#include "particles/pidt/mappings/RandomParticleDistribution.h"
#include "particles/pidt/mappings/MoveParticles.h"
#include "peano/grid/aspects/VertexStateAnalysis.h"
#include "tarch/multicore/MulticoreDefinitions.h"



peano::MappingSpecification   particles::pidt::mappings::RandomParticleDistribution::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::RandomParticleDistribution::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}
peano::MappingSpecification   particles::pidt::mappings::RandomParticleDistribution::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::RandomParticleDistribution::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::RandomParticleDistribution::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::RandomParticleDistribution::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pidt::mappings::RandomParticleDistribution::_log( "particles::pidt::mappings::RandomParticleDistribution" ); 


void particles::pidt::mappings::RandomParticleDistribution::initVertex(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h
) {
  int NumberOfParticles = getNumberOfParticles(
    h,
    _state.getMaximalNumberOfInitialParticlesPerUnitVolume()
  );
  const int vertexIndex =
      fineGridVertex.getRefinementControl()==Vertex::Records::Unrefined ?
      ParticleHeap::getInstance().createData(0,NumberOfParticles) :
      ParticleHeap::getInstance().createData();
  fineGridVertex.init(vertexIndex);

  const bool placeParticlesHere =
    fineGridVertex.getRefinementControl() == Vertex::Records::Unrefined
    &&
    controlPointIsInsideParticleDomain( x, _state.getBreakingDamWidth() );

  const double velocityScaling = _state.getMaximalInitialVelocity() / std::sqrt( static_cast<double>(DIMENSIONS) );
  if (placeParticlesHere) {
    NumberOfParticles = NumberOfParticles==0 ? 1 : NumberOfParticles;

    for (int i=0; i<NumberOfParticles; i++) {
      particles::pidt::records::Particle newParticle;
      for (int d=0; d<DIMENSIONS; d++) {
        newParticle._persistentRecords._x(d) = (static_cast<double>(rand())/static_cast<double>(RAND_MAX) - 0.5) * h(d) + x(d);
        newParticle._persistentRecords._v(d) = (static_cast<double>(rand())/static_cast<double>(RAND_MAX) * 2.0 - 1.0) * velocityScaling;
        newParticle.setMovedParticle( particles::pidt::records::Particle::New );
      }

      #ifdef Parallel
      const int  whichAdjacentCellWouldHoldParticle =
        peano::utils::dLinearised(Vertex::getDualCellOfParticle(x,newParticle._persistentRecords._x),2);

      const bool particleBelongsToLocalDomain = fineGridVertex.getAdjacentRanks()(whichAdjacentCellWouldHoldParticle)==tarch::parallel::Node::getInstance().getRank();
      #else
      const bool particleBelongsToLocalDomain = true;
      #endif

      if (
        controlPointIsInsideParticleDomain( newParticle._persistentRecords._x, _state.getBreakingDamWidth() )
        &&
        particleBelongsToLocalDomain
      ) {
        ParticleHeap::getInstance().getData(vertexIndex).push_back(newParticle);
      }
    }
  }

  #ifdef Asserts
  for (
    ParticleHeap::HeapEntries::const_iterator p = ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex()).begin();
    p != ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex()).end();
    p++
  ) {
    assertion5(
      Vertex::isContainedInDualCell(x,h,p->_persistentRecords._x),
      x,h,p->toString(),p->_persistentRecords._x - x,
      fineGridVertex.toString()
    );
  }
  #endif

}


void particles::pidt::mappings::RandomParticleDistribution::touchVertexFirstTime(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "touchVertexFirstTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  initVertex(fineGridVertex,fineGridX,fineGridH);

  logTraceOutWith1Argument( "touchVertexFirstTime(...)", fineGridVertex );
}





void particles::pidt::mappings::RandomParticleDistribution::beginIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  _state = solverState;

  ParticleHeap::getInstance().setName( "particles" );
  ParticleHeap::getInstance().startToSendBoundaryData(solverState.isTraversalInverted());

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pidt::mappings::RandomParticleDistribution::endIteration(
  particles::pidt::State&  solverState
) {
  ParticleHeap::getInstance().finishedToSendBoundaryData(solverState.isTraversalInverted());
}


#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::RandomParticleDistribution::RandomParticleDistribution(const RandomParticleDistribution&  masterThread):
  _state( masterThread._state ) {
}


void particles::pidt::mappings::RandomParticleDistribution::mergeWithWorkerThread(const RandomParticleDistribution& workerThread) {
}
#endif


#ifdef Parallel
void particles::pidt::mappings::RandomParticleDistribution::prepareSendToNeighbour(
  particles::pidt::Vertex&                      vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith3Arguments( "prepareSendToNeighbour(...)", vertex, toRank, level );

  const MoveParticles::ParticleContainer  emptyParticles;

  ParticleHeap::getInstance().sendData(
    emptyParticles,
    toRank,
    x,
    level,
    peano::heap::NeighbourCommunication
  );

  logTraceOut( "prepareSendToNeighbour(...)" );
}
#endif

//
// Nop
// ===
//
particles::pidt::mappings::RandomParticleDistribution::RandomParticleDistribution() {
}


particles::pidt::mappings::RandomParticleDistribution::~RandomParticleDistribution() {
}


void particles::pidt::mappings::RandomParticleDistribution::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::RandomParticleDistribution::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "destroyHangingVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "destroyHangingVertex(...)", fineGridVertex );
}


void particles::pidt::mappings::RandomParticleDistribution::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createInnerVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "createInnerVertex(...)", fineGridVertex );
}


void particles::pidt::mappings::RandomParticleDistribution::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createBoundaryVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "createBoundaryVertex(...)", fineGridVertex );
}


void particles::pidt::mappings::RandomParticleDistribution::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "destroyVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );
  // @todo Insert your code here
  logTraceOutWith1Argument( "destroyVertex(...)", fineGridVertex );
}


void particles::pidt::mappings::RandomParticleDistribution::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "createCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );
  // @todo Insert your code here
  logTraceOutWith1Argument( "createCell(...)", fineGridCell );
}


void particles::pidt::mappings::RandomParticleDistribution::destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "destroyCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );
  // @todo Insert your code here
  logTraceOutWith1Argument( "destroyCell(...)", fineGridCell );
}

#ifdef Parallel
void particles::pidt::mappings::RandomParticleDistribution::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pidt::mappings::RandomParticleDistribution::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}

void particles::pidt::mappings::RandomParticleDistribution::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}

void particles::pidt::mappings::RandomParticleDistribution::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}

void particles::pidt::mappings::RandomParticleDistribution::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}

bool particles::pidt::mappings::RandomParticleDistribution::prepareSendToWorker(
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

void particles::pidt::mappings::RandomParticleDistribution::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceInWith2Arguments( "prepareSendToMaster(...)", localCell, verticesEnumerator.toString() );
  // @todo Insert your code here
  logTraceOut( "prepareSendToMaster(...)" );
}


void particles::pidt::mappings::RandomParticleDistribution::mergeWithMaster(
  const particles::pidt::Cell&           workerGridCell,
  particles::pidt::Vertex * const        workerGridVertices,
 const peano::grid::VertexEnumerator& workerEnumerator,
  particles::pidt::Cell&                 fineGridCell,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker,
  const particles::pidt::State&          workerState,
  particles::pidt::State&                masterState
) {
}


void particles::pidt::mappings::RandomParticleDistribution::receiveDataFromMaster(
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


void particles::pidt::mappings::RandomParticleDistribution::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pidt::mappings::RandomParticleDistribution::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith2Arguments( "mergeWithWorker(...)", localVertex.toString(), receivedMasterVertex.toString() );
  // @todo Insert your code here
  logTraceOutWith1Argument( "mergeWithWorker(...)", localVertex.toString() );
}
#endif


void particles::pidt::mappings::RandomParticleDistribution::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::RandomParticleDistribution::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::RandomParticleDistribution::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pidt::mappings::RandomParticleDistribution::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}


void particles::pidt::mappings::RandomParticleDistribution::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
