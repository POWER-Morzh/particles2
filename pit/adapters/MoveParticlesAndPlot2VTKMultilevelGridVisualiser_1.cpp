#include "particles/pit/adapters/MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1.h"

#include <sstream>

#include "peano/utils/Loop.h"
#include "peano/grid/CellFlags.h"

#ifdef Parallel
#include "tarch/parallel/Node.h"
#endif


int particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::_snapshotCounter = 0;


std::map<int,particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::LevelDataset>  particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::_dataset;


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::Serial,false);
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,true);
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


peano::MappingSpecification   particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,true);
}


particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::LevelDataset::LevelDataset():
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
  
  _vertexTypeWriter               = _vtkWriter->createVertexDataWriter(particles::pit::Vertex::Records::getInsideOutsideDomainMapping() ,1);
  _vertexRefinementControlWriter  = _vtkWriter->createVertexDataWriter(particles::pit::Vertex::Records::getRefinementControlMapping() ,1);
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


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::LevelDataset::close(const std::string& filename) {
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


particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1() {
}


particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::~MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1(const MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1&  masterThread) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithWorkerThread(const MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1& workerThread) {
}
#endif


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::plotVertex(
  const particles::pit::Vertex&                 fineGridVertex,
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


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX, coarseGridVerticesEnumerator.getLevel()+1 ); 
}



void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::destroyCell(
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
void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::prepareSendToNeighbour(
      particles::pit::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::prepareCopyToRemoteNode(
      particles::pit::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::prepareCopyToRemoteNode(
      particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


bool particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::prepareSendToWorker(
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  return false;
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::prepareSendToMaster(
      particles::pit::Cell&                       localCell,
      particles::pit::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithMaster(
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


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::receiveDataFromMaster(
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


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithWorker(
      particles::pit::Cell&           localCell, 
      const particles::pit::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::mergeWithWorker(
      particles::pit::Vertex&        localVertex,
      const particles::pit::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}
#endif


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
  plotVertex( fineGridVertex, fineGridX, coarseGridVerticesEnumerator.getLevel()+1 ); 
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
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


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::beginIteration(
  particles::pit::State&  solverState
) {
  _dataset.clear();
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::endIteration(
  particles::pit::State&  solverState
) {
  for (std::map<int,LevelDataset>::iterator p=_dataset.begin(); p!=_dataset.end(); p++) {
    std::ostringstream snapshotFileName;
    snapshotFileName << "multilevelgrid"
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




void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
}


void particles::pit::adapters::MoveParticlesAndPlot2VTKMultilevelGridVisualiser_1::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
}
