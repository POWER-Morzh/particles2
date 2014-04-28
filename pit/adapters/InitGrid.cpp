#include "particles/pit/adapters/InitGrid.h"



peano::MappingSpecification   particles::pit::adapters::InitGrid::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::touchVertexLastTimeSpecification()


;
}


peano::MappingSpecification   particles::pit::adapters::InitGrid::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::touchVertexFirstTimeSpecification()


;
}


peano::MappingSpecification   particles::pit::adapters::InitGrid::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::enterCellSpecification()


;
}


peano::MappingSpecification   particles::pit::adapters::InitGrid::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::leaveCellSpecification()


;
}


peano::MappingSpecification   particles::pit::adapters::InitGrid::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::ascendSpecification()


;
}


peano::MappingSpecification   particles::pit::adapters::InitGrid::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::descendSpecification()


;
}


particles::pit::adapters::InitGrid::InitGrid() {
}


particles::pit::adapters::InitGrid::~InitGrid() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::adapters::InitGrid::InitGrid(const InitGrid&  masterThread):
  _map2InitGrid(masterThread._map2InitGrid) 

 

{
}


void particles::pit::adapters::InitGrid::mergeWithWorkerThread(const InitGrid& workerThread) {

  _map2InitGrid.mergeWithWorkerThread(workerThread._map2InitGrid);


}
#endif


void particles::pit::adapters::InitGrid::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {


  _map2InitGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pit::adapters::InitGrid::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  _map2InitGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );



}


void particles::pit::adapters::InitGrid::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {


  _map2InitGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGrid::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {


  _map2InitGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGrid::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2InitGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pit::adapters::InitGrid::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {


  _map2InitGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGrid::destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2InitGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


}

#ifdef Parallel
void particles::pit::adapters::InitGrid::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {


   _map2InitGrid.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void particles::pit::adapters::InitGrid::prepareSendToNeighbour(
  particles::pit::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2InitGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );


}

void particles::pit::adapters::InitGrid::prepareCopyToRemoteNode(
  particles::pit::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2InitGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );


}

void particles::pit::adapters::InitGrid::prepareCopyToRemoteNode(
  particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
   _map2InitGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );


}

void particles::pit::adapters::InitGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {


   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void particles::pit::adapters::InitGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {


   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

bool particles::pit::adapters::InitGrid::prepareSendToWorker(
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  bool result = false;
   result |= _map2InitGrid.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );


  return result;
}

void particles::pit::adapters::InitGrid::prepareSendToMaster(
  particles::pit::Cell&                       localCell,
  particles::pit::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2InitGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


}

void particles::pit::adapters::InitGrid::mergeWithMaster(
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


   _map2InitGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void particles::pit::adapters::InitGrid::receiveDataFromMaster(
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


   _map2InitGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGrid::mergeWithWorker(
  particles::pit::Cell&           localCell, 
  const particles::pit::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {


   _map2InitGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void particles::pit::adapters::InitGrid::mergeWithWorker(
  particles::pit::Vertex&        localVertex,
  const particles::pit::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2InitGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );


}
#endif

void particles::pit::adapters::InitGrid::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {


  _map2InitGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGrid::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2InitGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pit::adapters::InitGrid::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {


  _map2InitGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGrid::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2InitGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


}


void particles::pit::adapters::InitGrid::beginIteration(
  particles::pit::State&  solverState
) {


  _map2InitGrid.beginIteration( solverState );

}


void particles::pit::adapters::InitGrid::endIteration(
  particles::pit::State&  solverState
) {

  _map2InitGrid.endIteration( solverState );


}




void particles::pit::adapters::InitGrid::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {


  _map2InitGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void particles::pit::adapters::InitGrid::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {

  _map2InitGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );


}
