#include "particles/pidt/adapters/InitGridAndPlot.h"



peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::InitGrid::touchVertexLastTimeSpecification()

   & particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexLastTimeSpecification()
   & particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::InitGrid::touchVertexFirstTimeSpecification()

   & particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexFirstTimeSpecification()
   & particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::InitGrid::enterCellSpecification()

   & particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::enterCellSpecification()
   & particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::enterCellSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::InitGrid::leaveCellSpecification()

   & particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::leaveCellSpecification()
   & particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::leaveCellSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::InitGrid::ascendSpecification()

   & particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::ascendSpecification()
   & particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::ascendSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::InitGrid::descendSpecification()

   & particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::descendSpecification()
   & particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::descendSpecification()

;
}


particles::pidt::adapters::InitGridAndPlot::InitGridAndPlot() {
}


particles::pidt::adapters::InitGridAndPlot::~InitGridAndPlot() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::adapters::InitGridAndPlot::InitGridAndPlot(const InitGridAndPlot&  masterThread):
  _map2InitGrid(masterThread._map2InitGrid) 

 ,
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0(masterThread._map2InitGridAndPlot2VTKMultilevelGridVisualiser_0) , 
  _map2InitGridAndPlot2VTKGridVisualiser_1(masterThread._map2InitGridAndPlot2VTKGridVisualiser_1) 

{
}


void particles::pidt::adapters::InitGridAndPlot::mergeWithWorkerThread(const InitGridAndPlot& workerThread) {

  _map2InitGrid.mergeWithWorkerThread(workerThread._map2InitGrid);

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithWorkerThread(workerThread._map2InitGridAndPlot2VTKMultilevelGridVisualiser_0);
  _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithWorkerThread(workerThread._map2InitGridAndPlot2VTKGridVisualiser_1);

}
#endif


void particles::pidt::adapters::InitGridAndPlot::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pidt::adapters::InitGridAndPlot::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  _map2InitGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::InitGridAndPlot::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::InitGridAndPlot::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::InitGridAndPlot::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2InitGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::InitGridAndPlot::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2InitGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::InitGridAndPlot::destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2InitGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void particles::pidt::adapters::InitGridAndPlot::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );


   _map2InitGrid.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void particles::pidt::adapters::InitGridAndPlot::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2InitGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void particles::pidt::adapters::InitGridAndPlot::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2InitGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void particles::pidt::adapters::InitGridAndPlot::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
   _map2InitGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void particles::pidt::adapters::InitGridAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );


   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void particles::pidt::adapters::InitGridAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );


   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

bool particles::pidt::adapters::InitGridAndPlot::prepareSendToWorker(
  particles::pidt::Cell&                 fineGridCell,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  bool result = false;
   result |= _map2InitGrid.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

   result |= _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2InitGridAndPlot2VTKGridVisualiser_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

  return result;
}

void particles::pidt::adapters::InitGridAndPlot::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2InitGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2InitGridAndPlot2VTKGridVisualiser_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void particles::pidt::adapters::InitGridAndPlot::mergeWithMaster(
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
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );


   _map2InitGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void particles::pidt::adapters::InitGridAndPlot::receiveDataFromMaster(
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
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2InitGridAndPlot2VTKGridVisualiser_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );


   _map2InitGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::InitGridAndPlot::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );


   _map2InitGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void particles::pidt::adapters::InitGridAndPlot::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2InitGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2InitGridAndPlot2VTKGridVisualiser_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void particles::pidt::adapters::InitGridAndPlot::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2InitGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::InitGridAndPlot::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2InitGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGridAndPlot2VTKGridVisualiser_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::InitGridAndPlot::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2InitGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::InitGridAndPlot::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2InitGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::InitGridAndPlot::beginIteration(
  particles::pidt::State&  solverState
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.beginIteration( solverState );
  _map2InitGridAndPlot2VTKGridVisualiser_1.beginIteration( solverState );


  _map2InitGrid.beginIteration( solverState );

}


void particles::pidt::adapters::InitGridAndPlot::endIteration(
  particles::pidt::State&  solverState
) {

  _map2InitGrid.endIteration( solverState );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.endIteration( solverState );
  _map2InitGridAndPlot2VTKGridVisualiser_1.endIteration( solverState );

}




void particles::pidt::adapters::InitGridAndPlot::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );


  _map2InitGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void particles::pidt::adapters::InitGridAndPlot::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {

  _map2InitGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2InitGridAndPlot2VTKMultilevelGridVisualiser_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGridAndPlot2VTKGridVisualiser_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
