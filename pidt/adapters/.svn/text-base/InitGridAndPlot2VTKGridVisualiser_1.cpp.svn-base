#include "particles/pidt/adapters/InitGridAndPlot2VTKGridVisualiser_1.h"

#include <sstream>

#include "peano/utils/Loop.h"
#include "peano/grid/CellFlags.h"

#ifdef Parallel
#include "tarch/parallel/Node.h"
#endif


int particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::_snapshotCounter = 0;


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


std::map<tarch::la::Vector<DIMENSIONS,double> , int, tarch::la::VectorCompare<DIMENSIONS> >  particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::_vertex2IndexMap;


particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::InitGridAndPlot2VTKGridVisualiser_1():
  _vtkWriter(0),
  _vertexWriter(0),
  _cellWriter(0),
  _vertexTypeWriter(0),
  _vertexRefinementControlWriter(0),
  _vertexAdjacentCellsHeight(0),
  _cellStateWriter(0) {
}


particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::~InitGridAndPlot2VTKGridVisualiser_1() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::InitGridAndPlot2VTKGridVisualiser_1(const InitGridAndPlot2VTKGridVisualiser_1&  masterThread):
  _vtkWriter(masterThread._vtkWriter),
  _vertexWriter(masterThread._vertexWriter),
  _cellWriter(masterThread._cellWriter),
  _vertexTypeWriter(masterThread._vertexTypeWriter),
  _vertexRefinementControlWriter(masterThread._vertexRefinementControlWriter),
  _vertexAdjacentCellsHeight(masterThread._vertexAdjacentCellsHeight),
  _cellStateWriter(masterThread._cellStateWriter)
{
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithWorkerThread(const InitGridAndPlot2VTKGridVisualiser_1& workerThread) {
}
#endif





void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::plotVertex(
  const particles::pidt::Vertex&                 fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX
) {
  if ( _vertex2IndexMap.find(fineGridX) == _vertex2IndexMap.end() ) {  
    #if defined(Dim2) || defined(Dim3)
    _vertex2IndexMap[fineGridX] = _vertexWriter->plotVertex(fineGridX);
    #else
    _vertex2IndexMap[fineGridX] = _vertexWriter->plotVertex(tarch::la::Vector<3,double>(fineGridX.data()));
    #endif
    const int boundaryFlag = fineGridVertex.isHangingNode() ? -1 : fineGridVertex.isBoundary() ? 1 : 0;
    _vertexTypeWriter->plotVertex             (_vertex2IndexMap[fineGridX], boundaryFlag);
    _vertexRefinementControlWriter->plotVertex(_vertex2IndexMap[fineGridX],fineGridVertex.getRefinementControl() );
    _vertexAdjacentCellsHeight->plotVertex    (_vertex2IndexMap[fineGridX],fineGridVertex.getAdjacentCellsHeightOfPreviousIteration() );
  }
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX ); 
}



void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::destroyCell(
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
void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::prepareSendToNeighbour(
      particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::prepareCopyToRemoteNode(
      particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::prepareCopyToRemoteNode(
      particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


bool particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::prepareSendToWorker(
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


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::prepareSendToMaster(
      particles::pidt::Cell&                       localCell,
      particles::pidt::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithMaster(
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


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::receiveDataFromMaster(
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


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithWorker(
      particles::pidt::Cell&           localCell, 
      const particles::pidt::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::mergeWithWorker(
      particles::pidt::Vertex&        localVertex,
      const particles::pidt::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}
#endif


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  if (
    fineGridVertex.getRefinementControl()==particles::pidt::Vertex::Records::Unrefined ||
    fineGridVertex.getRefinementControl()==particles::pidt::Vertex::Records::RefinementTriggered ||
    fineGridVertex.getRefinementControl()==particles::pidt::Vertex::Records::Erasing || 
    fineGridVertex.getRefinementControl()==particles::pidt::Vertex::Records::RefineDueToJoinThoughWorkerIsAlreadyErasing
  ) {
    plotVertex( fineGridVertex, fineGridX ); 
  }
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
  #ifdef Parallel
  if (fineGridCell.isLeaf() && !fineGridCell.isAssignedToRemoteRank()) {
  #else
  if (fineGridCell.isLeaf()) {
  #endif
    assertion( DIMENSIONS==2 || DIMENSIONS==3 );
    int vertexIndex[TWO_POWER_D];
     dfor2(i)
      tarch::la::Vector<DIMENSIONS,double> currentVertexPosition = fineGridVerticesEnumerator.getVertexPosition(i);
      assertion2 ( _vertex2IndexMap.find(currentVertexPosition) != _vertex2IndexMap.end(), currentVertexPosition, fineGridVertices[ fineGridVerticesEnumerator(i) ].toString() );
      vertexIndex[iScalar] = _vertex2IndexMap[currentVertexPosition];
    enddforx
  
    int cellIndex;
    if (DIMENSIONS==2) {
      cellIndex = _cellWriter->plotQuadrangle(vertexIndex);
    }
    if (DIMENSIONS==3) {
      cellIndex = _cellWriter->plotHexahedron(vertexIndex);
    }
    
    _cellStateWriter->plotCell(cellIndex,fineGridVerticesEnumerator.getCellFlags());
  }
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::beginIteration(
  particles::pidt::State&  solverState
) {
  assertion( _vtkWriter==0 );
  
  _vtkWriter = new tarch::plotter::griddata::unstructured::vtk::VTKTextFileWriter();
  
  _vertexWriter     = _vtkWriter->createVertexWriter();
  _cellWriter       = _vtkWriter->createCellWriter();
  
  _vertexTypeWriter               = _vtkWriter->createVertexDataWriter(particles::pidt::Vertex::Records::getInsideOutsideDomainMapping()+"/Hanging=-1" ,1);
  _vertexRefinementControlWriter  = _vtkWriter->createVertexDataWriter(particles::pidt::Vertex::Records::getRefinementControlMapping() ,1);
  _vertexAdjacentCellsHeight      = _vtkWriter->createVertexDataWriter( peano::grid::getCellFlagsLegend(),1);

  _cellStateWriter                = _vtkWriter->createCellDataWriter( "cell-flag(>=-1=stationary,-1=parallel-boundary,<=-2=not-stationary" ,1);
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::endIteration(
  particles::pidt::State&  solverState
) {
  _vertexWriter->close();
  _cellWriter->close();
  
  _vertexTypeWriter->close();
  _vertexRefinementControlWriter->close();
  _vertexAdjacentCellsHeight->close();
  _cellStateWriter->close();
  
  delete _vertexWriter;
  delete _cellWriter;
  delete _vertexTypeWriter;
  delete _vertexRefinementControlWriter;
  delete _vertexAdjacentCellsHeight;
  delete _cellStateWriter;
  
  _vertexWriter                  = 0;
  _cellWriter                    = 0;
  _vertexTypeWriter              = 0;
  _vertexRefinementControlWriter = 0;
  _vertexAdjacentCellsHeight     = 0;
  _cellStateWriter               = 0;
  
  std::ostringstream snapshotFileName;
  snapshotFileName << "initgrid"
                   #ifdef Parallel
                   << "-rank-" << tarch::parallel::Node::getInstance().getRank()
                   #endif
                   << "-" << _snapshotCounter
                   << ".vtk";
  _vtkWriter->writeToFile( snapshotFileName.str() );
  
  _snapshotCounter++;                  
  
  _vertex2IndexMap.clear();
  
  delete _vtkWriter;
  _vtkWriter = 0;
}




void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKGridVisualiser_1::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
