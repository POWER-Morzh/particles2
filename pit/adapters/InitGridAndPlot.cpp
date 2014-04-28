#include "particles/pit/adapters/InitGridAndPlot.h"



peano::MappingSpecification   particles::pit::adapters::InitGridAndPlot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::touchVertexLastTimeSpecification()

   & particles::pit::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexLastTimeSpecification()
   & particles::pit::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::InitGridAndPlot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::touchVertexFirstTimeSpecification()

   & particles::pit::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexFirstTimeSpecification()
   & particles::pit::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::InitGridAndPlot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::enterCellSpecification()

   & particles::pit::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::enterCellSpecification()
   & particles::pit::adapters::InitGridAndPlot2VTKGridVisualiser_1::enterCellSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::InitGridAndPlot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::leaveCellSpecification()

   & particles::pit::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::leaveCellSpecification()
   & particles::pit::adapters::InitGridAndPlot2VTKGridVisualiser_1::leaveCellSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::InitGridAndPlot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::ascendSpecification()

   & particles::pit::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::ascendSpecification()
   & particles::pit::adapters::InitGridAndPlot2VTKGridVisualiser_1::ascendSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::InitGridAndPlot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::InitGrid::descendSpecification()

   & particles::pit::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::descendSpecification()
   & particles::pit::adapters::InitGridAndPlot2VTKGridVisualiser_1::descendSpecification()

;
}


particles::pit::adapters::InitGridAndPlot::InitGridAndPlot() {
}


particles::pit::adapters::InitGridAndPlot::~InitGridAndPlot() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::adapters::InitGridAndPlot::InitGridAndPlot(const InitGridAndPlot&  masterThread):
  _map2InitGrid(masterThread._map2InitGrid) 

 ,
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0(masterThread._map2InitGridAndPlot2VTKMultilevelGridVisualiser_0) , 
  _map2InitGridAndPlot2VTKGridVisualiser_1(masterThread._map2InitGridAndPlot2VTKGridVisualiser_1) 

{
}


void particles::pit::adapters::InitGridAndPlot::mergeWithWorkerThread(const InitGridAndPlot& workerThread) {

  _map2InitGrid.mergeWithWorkerThread(workerThread._map2InitGrid);

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithWorkerThread(workerThread._map2InitGridAndPlot2VTKMultilevelGridVisualiser_0);
  _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithWorkerThread(workerThread._map2InitGridAndPlot2VTKGridVisualiser_1);

}
#endif


void particles::pit::adapters::InitGridAndPlot::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pit::adapters::InitGridAndPlot::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  _map2InitGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGridAndPlot::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGridAndPlot::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGridAndPlot::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2InitGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGridAndPlot::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2InitGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGridAndPlot::destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2InitGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void particles::pit::adapters::InitGridAndPlot::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );


   _map2InitGrid.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void particles::pit::adapters::InitGridAndPlot::prepareSendToNeighbour(
  particles::pit::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2InitGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void particles::pit::adapters::InitGridAndPlot::prepareCopyToRemoteNode(
  particles::pit::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2InitGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void particles::pit::adapters::InitGridAndPlot::prepareCopyToRemoteNode(
  particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
   _map2InitGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void particles::pit::adapters::InitGridAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );


   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void particles::pit::adapters::InitGridAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );


   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

bool particles::pit::adapters::InitGridAndPlot::prepareSendToWorker(
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

   result |= _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2InitGridAndPlot2VTKGridVisualiser_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

  return result;
}

void particles::pit::adapters::InitGridAndPlot::prepareSendToMaster(
  particles::pit::Cell&                       localCell,
  particles::pit::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2InitGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void particles::pit::adapters::InitGridAndPlot::mergeWithMaster(
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
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );


   _map2InitGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void particles::pit::adapters::InitGridAndPlot::receiveDataFromMaster(
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
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2InitGridAndPlot2VTKGridVisualiser_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );


   _map2InitGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGridAndPlot::mergeWithWorker(
  particles::pit::Cell&           localCell, 
  const particles::pit::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );


   _map2InitGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void particles::pit::adapters::InitGridAndPlot::mergeWithWorker(
  particles::pit::Vertex&        localVertex,
  const particles::pit::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2InitGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void particles::pit::adapters::InitGridAndPlot::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGridAndPlot::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2InitGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::InitGridAndPlot::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2InitGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGridAndPlot::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2InitGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::InitGridAndPlot::beginIteration(
  particles::pit::State&  solverState
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.beginIteration( solverState );
  _map2InitGridAndPlot2VTKGridVisualiser_1.beginIteration( solverState );


  _map2InitGrid.beginIteration( solverState );

}


void particles::pit::adapters::InitGridAndPlot::endIteration(
  particles::pit::State&  solverState
) {

  _map2InitGrid.endIteration( solverState );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.endIteration( solverState );
  _map2InitGridAndPlot2VTKGridVisualiser_1.endIteration( solverState );

}




void particles::pit::adapters::InitGridAndPlot::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );


  _map2InitGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void particles::pit::adapters::InitGridAndPlot::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {

  _map2InitGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
