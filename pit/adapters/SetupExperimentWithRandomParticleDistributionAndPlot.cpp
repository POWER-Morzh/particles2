#include "particles/pit/adapters/SetupExperimentWithRandomParticleDistributionAndPlot.h"



peano::MappingSpecification   particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::RandomParticleDistribution::touchVertexLastTimeSpecification()
   & particles::pit::mappings::InitGrid::touchVertexLastTimeSpecification()
   & particles::pit::mappings::PlotParticles::touchVertexLastTimeSpecification()
   & particles::pit::mappings::Redistribute::touchVertexLastTimeSpecification()

   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::touchVertexLastTimeSpecification()
   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::touchVertexLastTimeSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::RandomParticleDistribution::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::InitGrid::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::PlotParticles::touchVertexFirstTimeSpecification()
   & particles::pit::mappings::Redistribute::touchVertexFirstTimeSpecification()

   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::touchVertexFirstTimeSpecification()
   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::touchVertexFirstTimeSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::enterCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::RandomParticleDistribution::enterCellSpecification()
   & particles::pit::mappings::InitGrid::enterCellSpecification()
   & particles::pit::mappings::PlotParticles::enterCellSpecification()
   & particles::pit::mappings::Redistribute::enterCellSpecification()

   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::enterCellSpecification()
   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::enterCellSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::leaveCellSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::RandomParticleDistribution::leaveCellSpecification()
   & particles::pit::mappings::InitGrid::leaveCellSpecification()
   & particles::pit::mappings::PlotParticles::leaveCellSpecification()
   & particles::pit::mappings::Redistribute::leaveCellSpecification()

   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::leaveCellSpecification()
   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::leaveCellSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::ascendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::RandomParticleDistribution::ascendSpecification()
   & particles::pit::mappings::InitGrid::ascendSpecification()
   & particles::pit::mappings::PlotParticles::ascendSpecification()
   & particles::pit::mappings::Redistribute::ascendSpecification()

   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::ascendSpecification()
   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::ascendSpecification()

;
}


peano::MappingSpecification   particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::descendSpecification() {
  return peano::MappingSpecification::getMostGeneralSpecification()
   & particles::pit::mappings::RandomParticleDistribution::descendSpecification()
   & particles::pit::mappings::InitGrid::descendSpecification()
   & particles::pit::mappings::PlotParticles::descendSpecification()
   & particles::pit::mappings::Redistribute::descendSpecification()

   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0::descendSpecification()
   & particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1::descendSpecification()

;
}


particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::SetupExperimentWithRandomParticleDistributionAndPlot() {
}


particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::~SetupExperimentWithRandomParticleDistributionAndPlot() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::SetupExperimentWithRandomParticleDistributionAndPlot(const SetupExperimentWithRandomParticleDistributionAndPlot&  masterThread):
  _map2RandomParticleDistribution(masterThread._map2RandomParticleDistribution) , 
  _map2InitGrid(masterThread._map2InitGrid) , 
  _map2PlotParticles(masterThread._map2PlotParticles) , 
  _map2Redistribute(masterThread._map2Redistribute) 

 ,
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0(masterThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0) , 
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1(masterThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1) 

{
}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithWorkerThread(const SetupExperimentWithRandomParticleDistributionAndPlot& workerThread) {

  _map2RandomParticleDistribution.mergeWithWorkerThread(workerThread._map2RandomParticleDistribution);
  _map2InitGrid.mergeWithWorkerThread(workerThread._map2InitGrid);
  _map2PlotParticles.mergeWithWorkerThread(workerThread._map2PlotParticles);
  _map2Redistribute.mergeWithWorkerThread(workerThread._map2Redistribute);

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithWorkerThread(workerThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0);
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorkerThread(workerThread._map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1);

}
#endif


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  _map2RandomParticleDistribution.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.destroyHangingVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createInnerVertex(fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.createBoundaryVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2RandomParticleDistribution.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.destroyVertex( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2RandomParticleDistribution.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.createCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {

  _map2RandomParticleDistribution.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.destroyCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

#ifdef Parallel
void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
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
   _map2Redistribute.mergeWithNeighbour( vertex, neighbour, fromRank, fineGridX, fineGridH, level );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareSendToNeighbour(
  particles::pit::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2RandomParticleDistribution.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2InitGrid.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2PlotParticles.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2Redistribute.prepareSendToNeighbour( vertex, toRank, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareSendToNeighbour( vertex, toRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToNeighbour( vertex, toRank, x, h, level );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareCopyToRemoteNode(
  particles::pit::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
   _map2RandomParticleDistribution.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2InitGrid.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2PlotParticles.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2Redistribute.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareCopyToRemoteNode( localVertex, toRank, x, h, level );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareCopyToRemoteNode(
  particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
   _map2RandomParticleDistribution.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2InitGrid.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2PlotParticles.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2Redistribute.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareCopyToRemoteNode( localCell, toRank, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareCopyToRemoteNode( localCell, toRank, x, h, level );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
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
   _map2Redistribute.mergeWithRemoteDataDueToForkOrJoin( localVertex, masterOrWorkerVertex, fromRank, x, h, level );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
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
   _map2Redistribute.mergeWithRemoteDataDueToForkOrJoin( localCell, masterOrWorkerCell, fromRank, x, h, level );

}

bool particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareSendToWorker(
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
   result |= _map2RandomParticleDistribution.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2InitGrid.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2PlotParticles.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2Redistribute.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

   result |= _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );
   result |= _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToWorker( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker );

  return result;
}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::prepareSendToMaster(
  particles::pit::Cell&                       localCell,
  particles::pit::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {

   _map2RandomParticleDistribution.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2InitGrid.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2PlotParticles.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2Redistribute.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.prepareSendToMaster( localCell, vertices, verticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithMaster(
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
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );


   _map2RandomParticleDistribution.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2InitGrid.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2PlotParticles.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );
   _map2Redistribute.mergeWithMaster( workerGridCell, workerGridVertices, workerEnumerator, fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell, worker, workerState, masterState );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::receiveDataFromMaster(
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
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );


   _map2RandomParticleDistribution.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2InitGrid.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2PlotParticles.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );
   _map2Redistribute.receiveDataFromMaster( receivedCell, receivedVertices, receivedVerticesEnumerator, receivedCoarseGridVertices, receivedCoarseGridVerticesEnumerator, receivedCoarseGridCell, workersCoarseGridVertices, workersCoarseGridVerticesEnumerator, workersCoarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithWorker(
  particles::pit::Cell&           localCell, 
  const particles::pit::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );


   _map2RandomParticleDistribution.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2InitGrid.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2PlotParticles.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );
   _map2Redistribute.mergeWithWorker( localCell, receivedMasterCell, cellCentre, cellSize, level );

}

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::mergeWithWorker(
  particles::pit::Vertex&        localVertex,
  const particles::pit::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {

   _map2RandomParticleDistribution.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2InitGrid.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2PlotParticles.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2Redistribute.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );
   _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.mergeWithWorker( localVertex, receivedMasterVertex, x, h, level );

}
#endif

void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );


  _map2RandomParticleDistribution.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.touchVertexFirstTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {

  _map2RandomParticleDistribution.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2InitGrid.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2PlotParticles.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2Redistribute.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.touchVertexLastTime( fineGridVertex, fineGridX, fineGridH, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfVertex );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );


  _map2RandomParticleDistribution.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.enterCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {

  _map2RandomParticleDistribution.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2InitGrid.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2PlotParticles.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2Redistribute.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.leaveCell( fineGridCell, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell, fineGridPositionOfCell );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::beginIteration(
  particles::pit::State&  solverState
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.beginIteration( solverState );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.beginIteration( solverState );


  _map2RandomParticleDistribution.beginIteration( solverState );
  _map2InitGrid.beginIteration( solverState );
  _map2PlotParticles.beginIteration( solverState );
  _map2Redistribute.beginIteration( solverState );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::endIteration(
  particles::pit::State&  solverState
) {

  _map2RandomParticleDistribution.endIteration( solverState );
  _map2InitGrid.endIteration( solverState );
  _map2PlotParticles.endIteration( solverState );
  _map2Redistribute.endIteration( solverState );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.endIteration( solverState );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.endIteration( solverState );

}




void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );


  _map2RandomParticleDistribution.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGrid.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotParticles.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Redistribute.descend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}


void particles::pit::adapters::SetupExperimentWithRandomParticleDistributionAndPlot::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {

  _map2RandomParticleDistribution.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2InitGrid.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2PlotParticles.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2Redistribute.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKGridVisualiser_0.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );
  _map2SetupExperimentWithRandomParticleDistributionAndPlot2VTKMultilevelGridVisualiser_1.ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

}
