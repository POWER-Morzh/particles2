#include "particles/pit/mappings/DropParticles.h"
#include "peano/utils/Loop.h"
#include "tarch/Assertions.h"



peano::MappingSpecification   particles::pit::mappings::DropParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}



peano::MappingSpecification   particles::pit::mappings::DropParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}


peano::MappingSpecification   particles::pit::mappings::DropParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


peano::MappingSpecification   particles::pit::mappings::DropParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}


peano::MappingSpecification   particles::pit::mappings::DropParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


peano::MappingSpecification   particles::pit::mappings::DropParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pit::mappings::DropParticles::_log( "particles::pit::mappings::DropParticles" ); 



//
// Implemented Events
// ==================
//
void particles::pit::mappings::DropParticles::reflectParticle( particles::pit::records::Particle& particle ) {
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



void particles::pit::mappings::DropParticles::enterCell(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceIn( "enterCell(...)" );

  const bool ReflectParticles =
    (SizeOfHaloLayer!=0.0 && tarch::la::greaterEquals(
      fineGridVerticesEnumerator.getCellSize()(0),
      3.0 * SizeOfHaloLayer
    )) ||
    (SizeOfHaloLayer==0.0 && coarseGridCell.isRoot());

  if ( ReflectParticles ) {
    const int fineCellIndex       = fineGridCell.getCellIndex();
    for (int i=0; i<static_cast<int>(ParticleHeap::getInstance().getData(fineCellIndex).size()); i++) {
      reflectParticle(ParticleHeap::getInstance().getData(fineCellIndex).at(i));
    }
  }
  logTraceOut( "enterCell(...)" );
}


particles::pit::ParticleHeap::HeapEntries particles::pit::mappings::DropParticles::extractParticlesToBeDroppedIntoChildCell(
  const particles::pit::Cell&                  coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridCellOffset,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridCellH
) const {
  ParticleHeap::HeapEntries result;

  const int coarseCellIndex = coarseGridCell.getCellIndex();

  for (
    ParticleHeap::HeapEntries::iterator p = ParticleHeap::getInstance().getData(coarseCellIndex).begin();
    p != ParticleHeap::getInstance().getData(coarseCellIndex).end();
  ) {
    bool drop = true;
    for (int d=0; d<DIMENSIONS; d++) {
      drop &= p->_persistentRecords._x(d) >= fineGridCellOffset(d);
      drop &= p->_persistentRecords._x(d) <= fineGridCellOffset(d) + fineGridCellH(d);
    }

    if (drop) {
      result.push_back(*p);
      p = ParticleHeap::getInstance().getData(coarseCellIndex).erase(p);
    }
    else {
      p++;
    }
  }

  return result;
}


void particles::pit::mappings::DropParticles::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&  fineGridEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
  logTraceIn( "descend(...)" );

  dfor3(k)
    ParticleHeap::HeapEntries droppedParticles = extractParticlesToBeDroppedIntoChildCell(
      coarseGridCell,
      fineGridEnumerator.getVertexPosition(k),
      fineGridEnumerator.getCellSize()
    );

    if (!droppedParticles.empty()) {
      // This assertion is too restrictive: If we do dynamic load-balancing, it
      // can happen that a subcell already is assigned to another rank as the
      // fork just has been triggered while the actual deployment is waiting for
      // the next iteration. So we should use is remote here. As a remote test
      // requires the state however, I stick with this variant. If the grid
      // is not rebalanced, this variant is equivalent.
      assertion4(
        !fineGridCells[ fineGridEnumerator.cell(k) ].isAssignedToRemoteRank(),
        fineGridEnumerator.toString(),
        droppedParticles.size(),
        droppedParticles.at(0).toString(),
        fineGridCells[ fineGridEnumerator.cell(k) ].toString()
      );

      const int fineGridIndex = fineGridCells[ fineGridEnumerator.cell(k) ].getCellIndex();

      ParticleHeap::getInstance().addData(fineGridIndex,droppedParticles);
    }
  enddforx

  logTraceOut( "descend(...)" );
}


#ifdef Parallel
bool particles::pit::mappings::DropParticles::prepareSendToWorker(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker
) {
  logTraceInWith6Arguments( "prepareSendToWorker(...)", fineGridCell.toString(), fineGridVerticesEnumerator.toString(), coarseGridCell.toString(), coarseGridVerticesEnumerator.toString(), fineGridPositionOfCell, worker );

  ParticleHeap::HeapEntries particlesToSend;

  if (!coarseGridCell.isRoot()) {
    particlesToSend = extractParticlesToBeDroppedIntoChildCell(
        coarseGridCell,
        fineGridVerticesEnumerator.getVertexPosition(),
        fineGridVerticesEnumerator.getCellSize()
      );
  }

  ParticleHeap::getInstance().sendData(
    particlesToSend,
    worker,
    fineGridVerticesEnumerator.getCellCenter(),fineGridVerticesEnumerator.getLevel(),
    peano::heap::MasterWorkerCommunication
  );

  logTraceOut( "prepareSendToWorker(...)" );

  return true;
}


void particles::pit::mappings::DropParticles::receiveDataFromMaster(
  particles::pit::Cell&                        receivedCell,
  particles::pit::Vertex *                     receivedVertices,
  const peano::grid::VertexEnumerator&         receivedVerticesEnumerator,
  particles::pit::Vertex * const               receivedCoarseGridVertices,
  const peano::grid::VertexEnumerator&         receivedCoarseGridVerticesEnumerator,
  particles::pit::Cell&                        receivedCoarseGridCell,
  particles::pit::Vertex * const               workersCoarseGridVertices,
  const peano::grid::VertexEnumerator&         workersCoarseGridVerticesEnumerator,
  particles::pit::Cell&                        workersCoarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfCell
) {
  logTraceIn( "receiveDataFromMaster(...)" );
  const int newCellIndex = ParticleHeap::getInstance().createData();
  receivedCell.init( newCellIndex );
  ParticleHeap::getInstance().receiveData(
    newCellIndex,
    tarch::parallel::NodePool::getInstance().getMasterRank(),
    receivedVerticesEnumerator.getCellCenter(),
    receivedVerticesEnumerator.getLevel(),
    peano::heap::MasterWorkerCommunication
  );
  logTraceOut( "receiveDataFromMaster(...)" );
}


void particles::pit::mappings::DropParticles::mergeWithWorker(
  particles::pit::Cell&                        localCell,
  const particles::pit::Cell&                  receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
  logTraceIn( "mergeWithWorker(...)" );
  const int receivedCellIndex = receivedMasterCell.getCellIndex();
  const int localCellIndex    = localCell.getCellIndex();

  ParticleHeap::getInstance().moveData(localCellIndex,receivedCellIndex);
  ParticleHeap::getInstance().deleteData(receivedCellIndex);

  logTraceOut( "mergeWithWorker(...)" );
}
#endif


void particles::pit::mappings::DropParticles::beginIteration(
  particles::pit::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  ParticleHeap::getInstance().clearStatistics();
  ParticleHeap::getInstance().startToSendSynchronousData();

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}



//
// Nop
// ===
//
particles::pit::mappings::DropParticles::DropParticles() {
}


particles::pit::mappings::DropParticles::~DropParticles() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::mappings::DropParticles::DropParticles(const DropParticles&  masterThread) {
}


void particles::pit::mappings::DropParticles::mergeWithWorkerThread(const DropParticles& workerThread) {
}
#endif


void particles::pit::mappings::DropParticles::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pit::mappings::DropParticles::destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}

#ifdef Parallel
void particles::pit::mappings::DropParticles::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}

void particles::pit::mappings::DropParticles::prepareSendToNeighbour(
    particles::pit::Vertex&  vertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}

void particles::pit::mappings::DropParticles::prepareCopyToRemoteNode(
    particles::pit::Vertex&  vertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}

void particles::pit::mappings::DropParticles::prepareCopyToRemoteNode(
    particles::pit::Cell&  localCell,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
    const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
    int                                           level
) {
}

void particles::pit::mappings::DropParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}

void particles::pit::mappings::DropParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pit::mappings::DropParticles::prepareSendToMaster(
    particles::pit::Cell&                       localCell,
    particles::pit::Vertex *                    vertices,
    const peano::grid::VertexEnumerator&       verticesEnumerator,
    const particles::pit::Vertex * const        coarseGridVertices,
    const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
    const particles::pit::Cell&                 coarseGridCell,
    const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pit::mappings::DropParticles::mergeWithMaster(
    const particles::pit::Cell&                       workerGridCell,
    particles::pit::Vertex * const                    workerGridVertices,
    const peano::grid::VertexEnumerator&             workerEnumerator,
    particles::pit::Cell&                             fineGridCell,
    particles::pit::Vertex * const                    fineGridVertices,
    const peano::grid::VertexEnumerator&             fineGridVerticesEnumerator,
    particles::pit::Vertex * const                    coarseGridVertices,
    const peano::grid::VertexEnumerator&             coarseGridVerticesEnumerator,
    particles::pit::Cell&                             coarseGridCell,
    const tarch::la::Vector<DIMENSIONS,int>&         fineGridPositionOfCell,
    int                                              worker,
    const particles::pit::State&                      workerState,
    particles::pit::State&                            masterState
) {
}


void particles::pit::mappings::DropParticles::mergeWithWorker(
    particles::pit::Vertex&        localVertex,
    const particles::pit::Vertex&  receivedMasterVertex,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}
#endif

void particles::pit::mappings::DropParticles::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::DropParticles::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pit::mappings::DropParticles::endIteration(
  particles::pit::State&  solverState
) {
}



void particles::pit::mappings::DropParticles::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
}
