#include "particles/pit/adapters/MoveParticlesAndPlot.h"
#include <iostream>


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::DropParticles::touchVertexLastTimeSpecification()
   & particles::pit::mappings::PlotParticles::touchVertexLastTimeSpecification()
   & particles::pit::mappings::MoveParticles::touchVertexLastTimeSpecification()
   & particles::pit::mappings::AdoptGrid::touchVertexLastTimeSpecification()
   & particles::pit::mappings::LiftParticles::touchVertexLastTimeSpecification()
   & particles::pit::mappings::Redistribute::touchVertexLastTimeSpecification()

   & particles::pit::adapters::MoveParticlesAndPlot2VTKGridVisualiser_0::touchVertexLastTimeSpecification()
   & particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::DropParticles::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::PlotParticles::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::MoveParticles::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::AdoptGrid::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::LiftParticles::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::Redistribute::touchVertexFirstTimeSpecification()

   & particles::pit::adapters::MoveParticlesAndPlot2VTKGridVisualiser_0::touchVertexFirstTimeSpecification()
   & particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::DropParticles::enterCellSpecification()
   & particles::pit::mappings::PlotParticles::enterCellSpecification()
   & particles::pit::mappings::MoveParticles::enterCellSpecification()
   & particles::pit::mappings::AdoptGrid::enterCellSpecification()
   & particles::pit::mappings::LiftParticles::enterCellSpecification()
   & particles::pit::mappings::Redistribute::enterCellSpecification()

   & particles::pit::adapters::MoveParticlesAndPlot2VTKGridVisualiser_0::enterCellSpecification()
   & particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::enterCellSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::DropParticles::leaveCellSpecification()
   & particles::pit::mappings::PlotParticles::leaveCellSpecification()
   & particles::pit::mappings::MoveParticles::leaveCellSpecification()
   & particles::pit::mappings::AdoptGrid::leaveCellSpecification()
   & particles::pit::mappings::LiftParticles::leaveCellSpecification()
   & particles::pit::mappings::Redistribute::leaveCellSpecification()

   & particles::pit::adapters::MoveParticlesAndPlot2VTKGridVisualiser_0::leaveCellSpecification()
   & particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::leaveCellSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::DropParticles::ascendSpecification()
   & particles::pit::mappings::PlotParticles::ascendSpecification()
   & particles::pit::mappings::MoveParticles::ascendSpecification()
   & particles::pit::mappings::AdoptGrid::ascendSpecification()
   & particles::pit::mappings::LiftParticles::ascendSpecification()
   & particles::pit::mappings::Redistribute::ascendSpecification()

   & particles::pit::adapters::MoveParticlesAndPlot2VTKGridVisualiser_0::ascendSpecification()
   & particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::ascendSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::DropParticles::descendSpecification()
   & particles::pit::mappings::PlotParticles::descendSpecification()
   & particles::pit::mappings::MoveParticles::descendSpecification()
   & particles::pit::mappings::AdoptGrid::descendSpecification()
   & particles::pit::mappings::LiftParticles::descendSpecification()
   & particles::pit::mappings::Redistribute::descendSpecification()

   & particles::pit::adapters::MoveParticlesAndPlot2VTKGridVisualiser_0::descendSpecification()
   & particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::descendSpecification()

;
}


particles::pit::adapters::MoveParticlesAndPlot::MoveParticlesAndPlot() {
}


particles::pit::adapters::MoveParticlesAndPlot::~MoveParticlesAndPlot() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::adapters::MoveParticlesAndPlot::MoveParticlesAndPlot(const MoveParticlesAndPlot&  masterThread):
  _map2DropParticles(masterThread._map2DropParticles) , 
  _map2PlotParticles(masterThread._map2PlotParticles) , 
  _map2MoveParticles(masterThread._map2MoveParticles) , 
  _map2AdoptGrid(masterThread._map2AdoptGrid) , 
  _map2LiftParticles(masterThread._map2LiftParticles) , 
  _map2Redistribute(masterThread._map2Redistribute) 

 ,
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0(masterThread._map2MoveParticlesAndPlot2VTKGridVisualiser_0) , 
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1(masterThread._map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1) 

{
}


void particles::pit::adapters::MoveParticlesAndPlot::mergeWithWorkerThread(const MoveParticlesAndPlot& workerThread) {

  _map2DropParticles.mergeWithWorkerThread(workerThread._map2DropParticles);
  _map2PlotParticles.mergeWithWorkerThread(workerThread._map2PlotParticles);
  _map2MoveParticles.mergeWithWorkerThread(workerThread._map2MoveParticles);
  _map2AdoptGrid.mergeWithWorkerThread(workerThread._map2AdoptGrid);
  _map2LiftParticles.mergeWithWorkerThread(workerThread._map2LiftParticles);
  _map2Redistribute.mergeWithWorkerThread(workerThread._map2Redistribute);

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithWorkerThread(workerThread._map2MoveParticlesAndPlot2VTKGridVisualiser_0);
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorkerThread(workerThread._map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1);

}
#endif


void particles::pit::adapters::MoveParticlesAndPlot::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2DropParticles.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pit::adapters::MoveParticlesAndPlot::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  _map2DropParticles.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::MoveParticlesAndPlot::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2DropParticles.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::MoveParticlesAndPlot::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2DropParticles.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::MoveParticlesAndPlot::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2DropParticles.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::MoveParticlesAndPlot::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2DropParticles.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticles.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2AdoptGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2LiftParticles.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::MoveParticlesAndPlot::destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2DropParticles.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticles.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2AdoptGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2LiftParticles.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void particles::pit::adapters::MoveParticlesAndPlot::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );


   _map2DropParticles.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2PlotParticles.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2MoveParticles.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2AdoptGrid.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2LiftParticles.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2Redistribute.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void particles::pit::adapters::MoveParticlesAndPlot::prepareSendToNeighbour(
  particles::pit::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2DropParticles.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2PlotParticles.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2MoveParticles.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2AdoptGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2LiftParticles.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2Redistribute.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void particles::pit::adapters::MoveParticlesAndPlot::prepareCopyToRemoteNode(
  particles::pit::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2DropParticles.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2PlotParticles.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2MoveParticles.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2AdoptGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2LiftParticles.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2Redistribute.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void particles::pit::adapters::MoveParticlesAndPlot::prepareCopyToRemoteNode(
  particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
   _map2DropParticles.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2PlotParticles.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2MoveParticles.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2AdoptGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2LiftParticles.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2Redistribute.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void particles::pit::adapters::MoveParticlesAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );


   _map2DropParticles.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2PlotParticles.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2MoveParticles.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2AdoptGrid.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2LiftParticles.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2Redistribute.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void particles::pit::adapters::MoveParticlesAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );


   _map2DropParticles.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2PlotParticles.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2MoveParticles.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2AdoptGrid.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2LiftParticles.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2Redistribute.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

bool particles::pit::adapters::MoveParticlesAndPlot::prepareSendToWorker(
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
   result |= _map2DropParticles.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2PlotParticles.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2MoveParticles.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2AdoptGrid.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2LiftParticles.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2Redistribute.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

   result |= _map2MoveParticlesAndPlot2VTKGridVisualiser_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

  return result;
}

void particles::pit::adapters::MoveParticlesAndPlot::prepareSendToMaster(
  particles::pit::Cell&                       localCell,
  particles::pit::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2DropParticles.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2PlotParticles.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2MoveParticles.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2AdoptGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2LiftParticles.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2Redistribute.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void particles::pit::adapters::MoveParticlesAndPlot::mergeWithMaster(
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
   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );


   _map2DropParticles.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2PlotParticles.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2MoveParticles.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2AdoptGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2LiftParticles.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2Redistribute.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void particles::pit::adapters::MoveParticlesAndPlot::receiveDataFromMaster(
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
   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );


   _map2DropParticles.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2PlotParticles.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2MoveParticles.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2AdoptGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2LiftParticles.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2Redistribute.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::MoveParticlesAndPlot::mergeWithWorker(
  particles::pit::Cell&           localCell, 
  const particles::pit::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );


   _map2DropParticles.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2PlotParticles.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2MoveParticles.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2AdoptGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2LiftParticles.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2Redistribute.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void particles::pit::adapters::MoveParticlesAndPlot::mergeWithWorker(
  particles::pit::Vertex&        localVertex,
  const particles::pit::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2DropParticles.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2PlotParticles.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2MoveParticles.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2AdoptGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2LiftParticles.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2Redistribute.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2MoveParticlesAndPlot2VTKGridVisualiser_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void particles::pit::adapters::MoveParticlesAndPlot::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2DropParticles.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::MoveParticlesAndPlot::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2DropParticles.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticles.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2AdoptGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2LiftParticles.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::MoveParticlesAndPlot::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2DropParticles.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticles.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2AdoptGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2LiftParticles.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::MoveParticlesAndPlot::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2DropParticles.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticles.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2AdoptGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2LiftParticles.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::MoveParticlesAndPlot::beginIteration(
  particles::pit::State&  solverState
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.beginIteration( solverState );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.beginIteration( solverState );


  _map2DropParticles.beginIteration( solverState );
  _map2PlotParticles.beginIteration( solverState );
  _map2MoveParticles.beginIteration( solverState );
  _map2AdoptGrid.beginIteration( solverState );
  _map2LiftParticles.beginIteration( solverState );
  _map2Redistribute.beginIteration( solverState );

}


void particles::pit::adapters::MoveParticlesAndPlot::endIteration(
  particles::pit::State&  solverState
) {

  _map2DropParticles.endIteration( solverState );
  _map2PlotParticles.endIteration( solverState );
  _map2MoveParticles.endIteration( solverState );
  _map2AdoptGrid.endIteration( solverState );
  _map2LiftParticles.endIteration( solverState );
  _map2Redistribute.endIteration( solverState );

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.endIteration( solverState );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.endIteration( solverState );

}




void particles::pit::adapters::MoveParticlesAndPlot::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );


  _map2DropParticles.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotParticles.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2MoveParticles.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2AdoptGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2LiftParticles.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Redistribute.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void particles::pit::adapters::MoveParticlesAndPlot::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
  _map2DropParticles.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotParticles.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2MoveParticles.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2AdoptGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2LiftParticles.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Redistribute.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2MoveParticlesAndPlot2VTKGridVisualiser_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
