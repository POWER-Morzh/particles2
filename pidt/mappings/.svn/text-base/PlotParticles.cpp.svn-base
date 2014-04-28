#include "particles/pidt/mappings/PlotParticles.h"



peano::MappingSpecification   particles::pidt::mappings::PlotParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::OnlyLeaves,peano::MappingSpecification::Serial,false);
}
peano::MappingSpecification   particles::pidt::mappings::PlotParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::PlotParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::PlotParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::PlotParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::PlotParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pidt::mappings::PlotParticles::_log( "particles::pidt::mappings::PlotParticles" ); 

int  particles::pidt::mappings::PlotParticles::_plotCounter( 0 );


particles::pidt::mappings::PlotParticles::PlotParticles():
  _vtkWriter(0),
  _vertexWriter(0),
  _cellWriter(0),
  _particleVelocityWriter(0) {
}


particles::pidt::mappings::PlotParticles::~PlotParticles() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::PlotParticles::PlotParticles(const PlotParticles&  masterThread):
  _vtkWriter(masterThread._vtkWriter),
  _vertexWriter(masterThread._vertexWriter),
  _cellWriter(masterThread._cellWriter),
  _particleVelocityWriter(masterThread._particleVelocityWriter) {
}


void particles::pidt::mappings::PlotParticles::mergeWithWorkerThread(const PlotParticles& workerThread) {
}
#endif


void particles::pidt::mappings::PlotParticles::beginIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  assertion( _vtkWriter==0 );

  _vtkWriter = new tarch::plotter::griddata::unstructured::vtk::VTKTextFileWriter();

  _vertexWriter     = _vtkWriter->createVertexWriter();
  _cellWriter       = _vtkWriter->createCellWriter();

  _particleVelocityWriter = _vtkWriter->createVertexDataWriter("Velocity", DIMENSIONS);

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pidt::mappings::PlotParticles::endIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "endIteration(State)", solverState );

  _vertexWriter->close();
  _cellWriter->close();

  _particleVelocityWriter->close();

  delete _vertexWriter;
  delete _cellWriter;
  delete _particleVelocityWriter;

  _vertexWriter            = 0;
  _cellWriter              = 0;
  _particleVelocityWriter  = 0;

  std::ostringstream snapshotFileName;
  snapshotFileName << "particles"
                   #ifdef Parallel
                   << "-rank-" << tarch::parallel::Node::getInstance().getRank()
                   #endif
                   << "-" << _plotCounter
                   << ".vtk";
  _vtkWriter->writeToFile( snapshotFileName.str() );

  _plotCounter++;

  delete _vtkWriter;
  _vtkWriter = 0;

  logTraceOutWith1Argument( "endIteration(State)", solverState);
}


void particles::pidt::mappings::PlotParticles::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "touchVertexLastTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  const int vertexIndex         = fineGridVertex.getVertexIndex();
  if (vertexIndex>=0) {
    const int numberOfParticles = static_cast<int>( ParticleHeap::getInstance().getData(vertexIndex).size() );
    for (int i=0; i<numberOfParticles; i++) {
      const particles::pidt::records::Particle& currentParticle = ParticleHeap::getInstance().getData(vertexIndex).at(i);
      const int particleNumber = _vertexWriter->plotVertex(currentParticle._persistentRecords._x);
      _cellWriter->plotPoint(particleNumber);
      _particleVelocityWriter->plotVertex(particleNumber,currentParticle._persistentRecords._v);
    }
  }

  logTraceOutWith1Argument( "touchVertexLastTime(...)", fineGridVertex );
}

//
// NOP
//=====
//
void particles::pidt::mappings::PlotParticles::touchVertexFirstTime(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::PlotParticles::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::PlotParticles::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::PlotParticles::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::PlotParticles::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::PlotParticles::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::PlotParticles::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::PlotParticles::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::PlotParticles::destroyCell(
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
void particles::pidt::mappings::PlotParticles::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
  logTraceInWith6Arguments( "mergeWithNeighbour(...)", vertex, neighbour, fromRank, fineGridX, fineGridH, level );
  // @todo Insert your code here
  logTraceOut( "mergeWithNeighbour(...)" );
}

void particles::pidt::mappings::PlotParticles::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
  logTraceInWith3Arguments( "prepareSendToNeighbour(...)", vertex, toRank, level );
  // @todo Insert your code here
  logTraceOut( "prepareSendToNeighbour(...)" );
}

void particles::pidt::mappings::PlotParticles::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
  logTraceInWith5Arguments( "prepareCopyToRemoteNode(...)", localVertex, toRank, x, h, level );
  // @todo Insert your code here
  logTraceOut( "prepareCopyToRemoteNode(...)" );
}

void particles::pidt::mappings::PlotParticles::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
  logTraceInWith5Arguments( "prepareCopyToRemoteNode(...)", localCell, toRank, cellCentre, cellSize, level );
  // @todo Insert your code here
  logTraceOut( "prepareCopyToRemoteNode(...)" );
}

void particles::pidt::mappings::PlotParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
  logTraceInWith6Arguments( "mergeWithRemoteDataDueToForkOrJoin(...)", localVertex, masterOrWorkerVertex, fromRank, x, h, level );
  // @todo Insert your code here
  logTraceOut( "mergeWithRemoteDataDueToForkOrJoin(...)" );
}

void particles::pidt::mappings::PlotParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


bool particles::pidt::mappings::PlotParticles::prepareSendToWorker(
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


void particles::pidt::mappings::PlotParticles::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pidt::mappings::PlotParticles::mergeWithMaster(
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
  logTraceIn( "mergeWithMaster(...)" );
  // @todo Insert your code here
  logTraceOut( "mergeWithMaster(...)" );
}


void particles::pidt::mappings::PlotParticles::receiveDataFromMaster(
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
  logTraceIn( "receiveDataFromMaster(...)" );
  // @todo Insert your code here
  logTraceOut( "receiveDataFromMaster(...)" );
}


void particles::pidt::mappings::PlotParticles::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
  logTraceInWith2Arguments( "mergeWithWorker(...)", localCell.toString(), receivedMasterCell.toString() );
  // @todo Insert your code here
  logTraceOutWith1Argument( "mergeWithWorker(...)", localCell.toString() );
}


void particles::pidt::mappings::PlotParticles::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith2Arguments( "mergeWithWorker(...)", localVertex.toString(), receivedMasterVertex.toString() );
  // @todo Insert your code here
  logTraceOutWith1Argument( "mergeWithWorker(...)", localVertex.toString() );
}
#endif



void particles::pidt::mappings::PlotParticles::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pidt::mappings::PlotParticles::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}


void particles::pidt::mappings::PlotParticles::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
