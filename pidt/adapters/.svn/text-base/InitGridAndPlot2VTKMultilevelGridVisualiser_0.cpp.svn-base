#include "particles/pidt/adapters/InitGridAndPlot2VTKMultilevelGridVisualiser_0.h"

#include <sstream>

#include "peano/utils/Loop.h"
#include "peano/grid/CellFlags.h"

#ifdef Parallel
#include "tarch/parallel/Node.h"
#endif


int particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::_snapshotCounter = 0;


std::map<int,particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::LevelDataset>  particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::_dataset;


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


peano::MappingSpecification   particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::InitGridAndPlot2VTKMultilevelGridVisualiser_0::LevelDataset::LevelDataset():
  _vtkWriter(0),
  _vertexWriter(0),
  _cellWriter(0),
  _vertexTypeWriter(0),
  _vertexRefinementControlWriter(0),
  _vertexAdjacentCellsHeight(0),
  _vertexHangingNodeWriter(0),
  _cellStateWriter(0),
  _cellLocalWorkloadWriter(0),
  _cellTotalWorkloadWriter(0), 
  _cellMaxWorkloadWriter(0),
  _cellMinWorkloadWriter(0) {
  _vtkWriter = new tarch::plotter::griddata::unstructured::vtk::VTKTextFileWriter();
  assertion( _vtkWriter != 0 );
  
  _vertexWriter     = _vtkWriter->createVertexWriter();
  _cellWriter       = _vtkWriter->createCellWriter();
  
  _vertexTypeWriter               = _vtkWriter->createVertexDataWriter(particles::pidt::Vertex::Records::getInsideOutsideDomainMapping() ,1);
  _vertexRefinementControlWriter  = _vtkWriter->createVertexDataWriter(particles::pidt::Vertex::Records::getRefinementControlMapping() ,1);
  _vertexAdjacentCellsHeight      = _vtkWriter->createVertexDataWriter( peano::grid::getCellFlagsLegend(),1);
  _vertexHangingNodeWriter        = _vtkWriter->createVertexDataWriter( "is-hanging-node" ,1);
  
  _cellStateWriter                = _vtkWriter->createCellDataWriter( "cell-flag(>=-1=stationary,-1=parallel-boundary,<=-2=not-stationary" ,1);
  #ifdef Parallel
  _cellLocalWorkloadWriter        = _vtkWriter->createCellDataWriter( "local-workload" ,1);
  _cellTotalWorkloadWriter        = _vtkWriter->createCellDataWriter( "total-workload" ,1);
  _cellMaxWorkloadWriter          = _vtkWriter->createCellDataWriter( "max-workload" ,1);
  _cellMinWorkloadWriter          = _vtkWriter->createCellDataWriter( "min-workload" ,1);
  #endif

  assertion( _vertexWriter != 0 );
  assertion( _cellWriter != 0 );
  assertion( _vertexTypeWriter != 0 );
  assertion( _vertexRefinementControlWriter != 0 );
  assertion( _vertexAdjacentCellsHeight != 0 );  
  assertion( _vertexHangingNodeWriter != 0 );
  assertion( _cellStateWriter != 0 );
  
  #ifdef Parallel
  assertion( _cellLocalWorkloadWriter != 0 );
  assertion( _cellTotalWorkloadWriter != 0 );
  assertion( _cellMaxWorkloadWriter != 0 );
  assertion( _cellMinWorkloadWriter != 0 );
  #else
  assertion( _cellLocalWorkloadWriter == 0 );
  assertion( _cellTotalWorkloadWriter == 0 );
  assertion( _cellMaxWorkloadWriter == 0 );
  assertion( _cellMinWorkloadWriter == 0 );
  #endif
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::LevelDataset::close(const std::string& filename) {
  assertion( _vertexWriter != 0 );
  assertion( _cellWriter != 0 );
  assertion( _vertexTypeWriter != 0 );
  assertion( _vertexRefinementControlWriter != 0 );
  assertion( _vertexAdjacentCellsHeight != 0 );  
  assertion( _vertexHangingNodeWriter != 0 );  
  #ifdef Parallel
  assertion( _cellLocalWorkloadWriter != 0 );
  assertion( _cellTotalWorkloadWriter != 0 );
  assertion( _cellMaxWorkloadWriter != 0 );
  assertion( _cellMinWorkloadWriter != 0 );
  #else
  assertion( _cellLocalWorkloadWriter == 0 );
  assertion( _cellTotalWorkloadWriter == 0 );
  assertion( _cellMaxWorkloadWriter == 0 );
  assertion( _cellMinWorkloadWriter == 0 );
  #endif

  _vertexWriter->close();
  _cellWriter->close();
  
  _vertexTypeWriter->close();
  _vertexRefinementControlWriter->close();
  _vertexAdjacentCellsHeight->close();
  _vertexHangingNodeWriter->close();
  _cellStateWriter->close();
  #ifdef Parallel
  _cellLocalWorkloadWriter->close();
  _cellTotalWorkloadWriter->close();
  #endif
    
  delete _vertexWriter;
  delete _cellWriter;
  delete _vertexTypeWriter;
  delete _vertexRefinementControlWriter;
  delete _vertexAdjacentCellsHeight;
  delete _vertexHangingNodeWriter;
  delete _cellStateWriter;
  
  #ifdef Parallel
  delete _cellLocalWorkloadWriter;
  delete _cellTotalWorkloadWriter;
  delete _cellMaxWorkloadWriter;
  delete _cellMinWorkloadWriter;
  #endif
  
  _vertexWriter                  = 0;
  _cellWriter                    = 0;
  _vertexTypeWriter              = 0;
  _vertexRefinementControlWriter = 0;
  _vertexAdjacentCellsHeight     = 0;
  _vertexHangingNodeWriter       = 0;
  _cellStateWriter               = 0;
  _cellLocalWorkloadWriter       = 0;
  _cellTotalWorkloadWriter       = 0;  
  
  _vtkWriter->writeToFile( filename );
  
  delete _vtkWriter;
  _vtkWriter = 0;

  _vertex2IndexMap.clear(); 
}


particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::InitGridAndPlot2VTKMultilevelGridVisualiser_0() {
}


particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::~InitGridAndPlot2VTKMultilevelGridVisualiser_0() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::InitGridAndPlot2VTKMultilevelGridVisualiser_0(const InitGridAndPlot2VTKMultilevelGridVisualiser_0&  masterThread) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithWorkerThread(const InitGridAndPlot2VTKMultilevelGridVisualiser_0& workerThread) {
}
#endif


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::plotVertex(
  const particles::pidt::Vertex&                 fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  int                                          level
) {
  if ( _dataset.count(level)==0 ) {
    _dataset.insert( std::pair<int,LevelDataset>(level,LevelDataset()) );
  }

  if ( _dataset[level]._vertex2IndexMap.find(fineGridX) == _dataset[level]._vertex2IndexMap.end() ) {  
    #if defined(Dim2) || defined(Dim3)
    _dataset[level]._vertex2IndexMap[fineGridX] = _dataset[level]._vertexWriter->plotVertex(fineGridX);
    #else
    _dataset[level]._vertex2IndexMap[fineGridX] = _dataset[level]._vertexWriter->plotVertex(tarch::la::Vector<3,double>(fineGridX.data()));
    #endif
    _dataset[level]._vertexTypeWriter->plotVertex             (_dataset[level]._vertex2IndexMap[fineGridX],fineGridVertex.isBoundary() );
    _dataset[level]._vertexRefinementControlWriter->plotVertex(_dataset[level]._vertex2IndexMap[fineGridX],fineGridVertex.getRefinementControl() );
    _dataset[level]._vertexAdjacentCellsHeight->plotVertex    (_dataset[level]._vertex2IndexMap[fineGridX],fineGridVertex.getAdjacentCellsHeightOfPreviousIteration() );
    _dataset[level]._vertexHangingNodeWriter->plotVertex      (_dataset[level]._vertex2IndexMap[fineGridX],fineGridVertex.isHangingNode() );
  }
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX, coarseGridVerticesEnumerator.getLevel()+1 ); 
}



void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::destroyCell(
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
void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::prepareSendToNeighbour(
      particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::prepareCopyToRemoteNode(
      particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::prepareCopyToRemoteNode(
      particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


bool particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::prepareSendToWorker(
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


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::prepareSendToMaster(
      particles::pidt::Cell&                       localCell,
      particles::pidt::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithMaster(
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


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::receiveDataFromMaster(
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


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithWorker(
      particles::pidt::Cell&           localCell, 
      const particles::pidt::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::mergeWithWorker(
      particles::pidt::Vertex&        localVertex,
      const particles::pidt::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}
#endif


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX, coarseGridVerticesEnumerator.getLevel()+1 ); 
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
  #ifdef Parallel
  if (!fineGridCell.isAssignedToRemoteRank()) {
  #endif

  assertion( DIMENSIONS==2 || DIMENSIONS==3 );
  int vertexIndex[TWO_POWER_D];
   dfor2(i)
    tarch::la::Vector<DIMENSIONS,double> currentVertexPosition = fineGridVerticesEnumerator.getVertexPosition(i);
    assertion4 ( 
      _dataset[coarseGridVerticesEnumerator.getLevel()+1]._vertex2IndexMap.find(currentVertexPosition) != _dataset[coarseGridVerticesEnumerator.getLevel()+1]._vertex2IndexMap.end(), 
      currentVertexPosition, 
      coarseGridVerticesEnumerator.toString(),
      fineGridVertices[fineGridVerticesEnumerator(i)].toString(),
      fineGridCell.toString()
    );
    vertexIndex[iScalar] = _dataset[coarseGridVerticesEnumerator.getLevel()+1]._vertex2IndexMap[currentVertexPosition];
  enddforx
  
  int cellIndex;
  if (DIMENSIONS==2) {
    cellIndex = _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellWriter->plotQuadrangle(vertexIndex);
  }
  if (DIMENSIONS==3) {
    cellIndex = _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellWriter->plotHexahedron(vertexIndex);
  }
  
  _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellStateWriter->plotCell(cellIndex,fineGridVerticesEnumerator.getCellFlags());

  #ifdef Parallel
  _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellLocalWorkloadWriter->plotCell( cellIndex, fineGridCell.getLocalWorkload() );
  _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellTotalWorkloadWriter->plotCell( cellIndex, fineGridCell.getTotalWorkload() );
  _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellMaxWorkloadWriter->plotCell( cellIndex, fineGridCell.getMaxWorkload() );
  _dataset[coarseGridVerticesEnumerator.getLevel()+1]._cellMinWorkloadWriter->plotCell( cellIndex, fineGridCell.getMinWorkload() );
  }
  #endif
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::beginIteration(
  particles::pidt::State&  solverState
) {
  _dataset.clear();
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::endIteration(
  particles::pidt::State&  solverState
) {
  for (std::map<int,LevelDataset>::iterator p=_dataset.begin(); p!=_dataset.end(); p++) {
    std::ostringstream snapshotFileName;
    snapshotFileName << "multilevelinitgrid"
                     #ifdef Parallel
                     << "-rank-" << tarch::parallel::Node::getInstance().getRank()
                     #endif
                     << "-level-" << p->first 
                     << "-" << _snapshotCounter
                     << ".vtk";
    p->second.close( snapshotFileName.str() );
  }
  
  _snapshotCounter++;                  
}




void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}


void particles::pidt::adapters::InitGridAndPlot2VTKMultilevelGridVisualiser_0::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
