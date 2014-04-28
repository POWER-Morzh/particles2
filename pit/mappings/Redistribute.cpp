#include "particles/pit/mappings/Redistribute.h"


peano::MappingSpecification   particles::pit::mappings::Redistribute::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}

peano::MappingSpecification   particles::pit::mappings::Redistribute::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}

peano::MappingSpecification   particles::pit::mappings::Redistribute::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}

peano::MappingSpecification   particles::pit::mappings::Redistribute::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}

peano::MappingSpecification   particles::pit::mappings::Redistribute::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}

peano::MappingSpecification   particles::pit::mappings::Redistribute::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}




tarch::logging::Log                particles::pit::mappings::Redistribute::_log( "particles::pit::mappings::Redistribute" ); 


#ifdef Parallel
void particles::pit::mappings::Redistribute::prepareCopyToRemoteNode(
  particles::pit::Cell&                         localCell,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
  int                                           level
) {
  logTraceInWith5Arguments( "prepareCopyToRemoteNode(...)", localCell, toRank, cellCentre, cellSize, level );

  if (localCell.isInside() && localCell.getRankOfRemoteNode()==toRank) {
    const int cellIndex = localCell.getCellIndex();

    ParticleHeap::getInstance().sendData(
      cellIndex, toRank, cellCentre, level,
      peano::heap::ForkOrJoinCommunication
    );

    ParticleHeap::getInstance().getData(cellIndex).clear();
  }

  logTraceOut( "prepareCopyToRemoteNode(...)" );
}


void particles::pit::mappings::Redistribute::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&                        localCell,
  const particles::pit::Cell&                  masterOrWorkerCell,
  int                                          fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
  logTraceInWith3Arguments( "mergeWithRemoteDataDueToForkOrJoin(...)", localCell, masterOrWorkerCell, fromRank );

  if ( masterOrWorkerCell.isInside() && masterOrWorkerCell.getRankOfRemoteNode()==tarch::parallel::Node::getInstance().getRank() ) {
    const int cellIndex = localCell.getCellIndex();

    if (ParticleHeap::getInstance().getData(cellIndex).size()==0) {
      ParticleHeap::getInstance().receiveData(
        cellIndex,
        fromRank, cellCentre, level,
        peano::heap::ForkOrJoinCommunication
      );
    }
    else {
      ParticleHeap::getInstance().receiveData(
        fromRank, cellCentre, level,
        peano::heap::ForkOrJoinCommunication
      );
    }
  }

  logTraceOut( "mergeWithRemoteDataDueToForkOrJoin(...)" );
}
#endif


//
// NOP
// ===
//
void particles::pit::mappings::Redistribute::beginIteration(
  particles::pit::State&  solverState
) {
}


void particles::pit::mappings::Redistribute::endIteration(
  particles::pit::State&  solverState
) {
}


void particles::pit::mappings::Redistribute::destroyCell(
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
void particles::pit::mappings::Redistribute::prepareCopyToRemoteNode(
  particles::pit::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}
#endif


particles::pit::mappings::Redistribute::Redistribute() {
}


particles::pit::mappings::Redistribute::~Redistribute() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::mappings::Redistribute::Redistribute(const Redistribute&  masterThread) {
}


void particles::pit::mappings::Redistribute::mergeWithWorkerThread(const Redistribute& workerThread) {
}
#endif


void particles::pit::mappings::Redistribute::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


#ifdef Parallel
void particles::pit::mappings::Redistribute::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pit::mappings::Redistribute::prepareSendToNeighbour(
  particles::pit::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pit::mappings::Redistribute::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


bool particles::pit::mappings::Redistribute::prepareSendToWorker(
  particles::pit::Cell&                      fineGridCell,
  particles::pit::Vertex * const             fineGridVertices,
  const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
  particles::pit::Vertex * const             coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  particles::pit::Cell&                      coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell,
  int                                        worker
) {
  return false;
}


void particles::pit::mappings::Redistribute::prepareSendToMaster(
  particles::pit::Cell&                       localCell,
  particles::pit::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pit::mappings::Redistribute::mergeWithMaster(
  const particles::pit::Cell&           workerGridCell,
  particles::pit::Vertex * const        workerGridVertices,
 const peano::grid::VertexEnumerator& workerEnumerator,
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker,
  const particles::pit::State&          workerState,
  particles::pit::State&                masterState
) {
}


void particles::pit::mappings::Redistribute::receiveDataFromMaster(
      particles::pit::Cell&                        receivedCell, 
      particles::pit::Vertex *                     receivedVertices,
      const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
      particles::pit::Vertex * const               receivedCoarseGridVertices,
      const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
      particles::pit::Cell&                        receivedCoarseGridCell,
      particles::pit::Vertex * const               workersCoarseGridVertices,
      const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
      particles::pit::Cell&                        workersCoarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
}


void particles::pit::mappings::Redistribute::mergeWithWorker(
  particles::pit::Cell&           localCell, 
  const particles::pit::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pit::mappings::Redistribute::mergeWithWorker(
  particles::pit::Vertex&        localVertex,
  const particles::pit::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}
#endif


void particles::pit::mappings::Redistribute::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::Redistribute::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pit::mappings::Redistribute::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}



void particles::pit::mappings::Redistribute::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
}


void particles::pit::mappings::Redistribute::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
}
