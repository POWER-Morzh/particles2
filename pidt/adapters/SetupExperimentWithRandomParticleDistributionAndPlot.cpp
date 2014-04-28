#include "particles/pidt/adapters/SetupExperimentWithRandomParticleDistributionAndPlot.h"



peano::MappingSpecification   particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::RandomParticleDistribution::touchVertexLastTimeSpecification()
   & particles::pidt::mappings::InitGrid::touchVertexLastTimeSpecification()
   & particles::pidt::mappings::PlotParticles::touchVertexLastTimeSpecification()
   & particles::pidt::mappings::PlotDualGrid::touchVertexLastTimeSpecification()
   & particles::pidt::mappings::Redistribute::touchVertexLastTimeSpecification()

   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::touchVertexLastTimeSpecification()
   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::RandomParticleDistribution::touchVertexFirstTimeSpecification()
   & particles::pidt::mappings::InitGrid::touchVertexFirstTimeSpecification()
   & particles::pidt::mappings::PlotParticles::touchVertexFirstTimeSpecification()
   & particles::pidt::mappings::PlotDualGrid::touchVertexFirstTimeSpecification()
   & particles::pidt::mappings::Redistribute::touchVertexFirstTimeSpecification()

   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::touchVertexFirstTimeSpecification()
   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::RandomParticleDistribution::enterCellSpecification()
   & particles::pidt::mappings::InitGrid::enterCellSpecification()
   & particles::pidt::mappings::PlotParticles::enterCellSpecification()
   & particles::pidt::mappings::PlotDualGrid::enterCellSpecification()
   & particles::pidt::mappings::Redistribute::enterCellSpecification()

   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::enterCellSpecification()
   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::enterCellSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::RandomParticleDistribution::leaveCellSpecification()
   & particles::pidt::mappings::InitGrid::leaveCellSpecification()
   & particles::pidt::mappings::PlotParticles::leaveCellSpecification()
   & particles::pidt::mappings::PlotDualGrid::leaveCellSpecification()
   & particles::pidt::mappings::Redistribute::leaveCellSpecification()

   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::leaveCellSpecification()
   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::leaveCellSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::RandomParticleDistribution::ascendSpecification()
   & particles::pidt::mappings::InitGrid::ascendSpecification()
   & particles::pidt::mappings::PlotParticles::ascendSpecification()
   & particles::pidt::mappings::PlotDualGrid::ascendSpecification()
   & particles::pidt::mappings::Redistribute::ascendSpecification()

   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::ascendSpecification()
   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::ascendSpecification()

;
}


peano::MappingSpecification   particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pidt::mappings::RandomParticleDistribution::descendSpecification()
   & particles::pidt::mappings::InitGrid::descendSpecification()
   & particles::pidt::mappings::PlotParticles::descendSpecification()
   & particles::pidt::mappings::PlotDualGrid::descendSpecification()
   & particles::pidt::mappings::Redistribute::descendSpecification()

   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::descendSpecification()
   & particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::descendSpecification()

;
}


particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::SetupExperimentWithRandomParticleDistributionAndPlot() {
}


particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::~SetupExperimentWithRandomParticleDistributionAndPlot() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::SetupExperimentWithRandomParticleDistributionAndPlot(const SetupExperimentWithRandomParticleDistributionAndPlot&  masterThread):
  _map2RandomParticleDistribution(masterThread._map2RandomParticleDistribution) , 
  _map2InitGrid(masterThread._map2InitGrid) , 
  _map2PlotParticles(masterThread._map2PlotParticles) , 
  _map2PlotDualGrid(masterThread._map2PlotDualGrid) , 
  _map2Redistribute(masterThread._map2Redistribute) 

 ,
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0(masterThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0) , 
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1(masterThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1) 

{
}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithWorkerThread(const SetupExperimentWithRandomParticleDistributionAndPlot& workerThread) {

  _map2RandomParticleDistribution.mergeWithWorkerThread(workerThread._map2RandomParticleDistribution);
  _map2InitGrid.mergeWithWorkerThread(workerThread._map2InitGrid);
  _map2PlotParticles.mergeWithWorkerThread(workerThread._map2PlotParticles);
  _map2PlotDualGrid.mergeWithWorkerThread(workerThread._map2PlotDualGrid);
  _map2Redistribute.mergeWithWorkerThread(workerThread._map2Redistribute);

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithWorkerThread(workerThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0);
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorkerThread(workerThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1);

}
#endif


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  _map2RandomParticleDistribution.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2RandomParticleDistribution.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2RandomParticleDistribution.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotDualGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2RandomParticleDistribution.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotDualGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );


   _map2RandomParticleDistribution.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2InitGrid.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2PlotParticles.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2PlotDualGrid.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );
   _map2Redistribute.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2RandomParticleDistribution.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2InitGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2PlotParticles.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2PlotDualGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2Redistribute.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2RandomParticleDistribution.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2InitGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2PlotParticles.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2PlotDualGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2Redistribute.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
   _map2RandomParticleDistribution.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2InitGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2PlotParticles.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2PlotDualGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2Redistribute.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );


   _map2RandomParticleDistribution.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2PlotParticles.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2PlotDualGrid.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );
   _map2Redistribute.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );


   _map2RandomParticleDistribution.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2InitGrid.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2PlotParticles.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2PlotDualGrid.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );
   _map2Redistribute.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

bool particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareSendToWorker(
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
   result |= _map2RandomParticleDistribution.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2InitGrid.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2PlotParticles.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2PlotDualGrid.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2Redistribute.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

   result |= _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

  return result;
}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2RandomParticleDistribution.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2InitGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2PlotParticles.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2PlotDualGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2Redistribute.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithMaster(
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
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );


   _map2RandomParticleDistribution.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2InitGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2PlotParticles.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2PlotDualGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2Redistribute.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::receiveDataFromMaster(
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
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );


   _map2RandomParticleDistribution.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2InitGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2PlotParticles.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2PlotDualGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2Redistribute.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );


   _map2RandomParticleDistribution.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2InitGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2PlotParticles.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2PlotDualGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2Redistribute.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2RandomParticleDistribution.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2InitGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2PlotParticles.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2PlotDualGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2Redistribute.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2RandomParticleDistribution.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotDualGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2RandomParticleDistribution.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotDualGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2RandomParticleDistribution.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotDualGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::beginIteration(
  particles::pidt::State&  solverState
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.beginIteration( solverState );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.beginIteration( solverState );


  _map2RandomParticleDistribution.beginIteration( solverState );
  _map2InitGrid.beginIteration( solverState );
  _map2PlotParticles.beginIteration( solverState );
  _map2PlotDualGrid.beginIteration( solverState );
  _map2Redistribute.beginIteration( solverState );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::endIteration(
  particles::pidt::State&  solverState
) {

  _map2RandomParticleDistribution.endIteration( solverState );
  _map2InitGrid.endIteration( solverState );
  _map2PlotParticles.endIteration( solverState );
  _map2PlotDualGrid.endIteration( solverState );
  _map2Redistribute.endIteration( solverState );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.endIteration( solverState );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.endIteration( solverState );

}




void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );


  _map2RandomParticleDistribution.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotParticles.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotDualGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Redistribute.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {

  _map2RandomParticleDistribution.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotParticles.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotDualGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Redistribute.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
