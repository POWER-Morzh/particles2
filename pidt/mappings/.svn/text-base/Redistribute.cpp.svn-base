#include "particles/pidt/mappings/Redistribute.h"
#include "particles/pidt/mappings/MoveParticles.h"
#include "peano/utils/Loop.h"


peano::MappingSpecification   particles::pidt::mappings::Redistribute::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::Redistribute::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::Redistribute::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::Redistribute::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::Redistribute::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::Redistribute::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pidt::mappings::Redistribute::_log( "particles::pidt::mappings::Redistribute" ); 




#ifdef Parallel
void particles::pidt::mappings::Redistribute::prepareCopyToRemoteNode(
  particles::pidt::Vertex&                      localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith5Arguments( "prepareCopyToRemoteNode(...)", localVertex, toRank, x, h, level );

  const ParticleContainer  destinationParticles = MoveParticles::extractAllParticlesFromDualCellBelongingToOneRank(
    localVertex.getVertexIndex(),
    localVertex,
    toRank,
    x,
    h
  );

  ParticleHeap::getInstance().sendData(
    destinationParticles,
    toRank,
    x,
    level,
    peano::heap::ForkOrJoinCommunication
  );

  logTraceOut( "prepareCopyToRemoteNode(...)" );
}



void particles::pidt::mappings::Redistribute::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&                     localVertex,
  const particles::pidt::Vertex&               masterOrWorkerVertex,
  int                                          fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                          level
) {
  logTraceInWith6Arguments( "mergeWithRemoteDataDueToForkOrJoin(...)", localVertex, masterOrWorkerVertex, fromRank, x, h, level );

  ParticleHeap::getInstance().receiveData(
    localVertex.getVertexIndex(),
    fromRank,
    x,
    level,
    peano::heap::ForkOrJoinCommunication
  );

  logTraceOut( "mergeWithRemoteDataDueToForkOrJoin(...)" );
}
#endif


//
//  NOP
// =====
//
void particles::pidt::mappings::Redistribute::beginIteration(
  particles::pidt::State&  solverState
) {
}


void particles::pidt::mappings::Redistribute::endIteration(
  particles::pidt::State&  solverState
) {
}


particles::pidt::mappings::Redistribute::Redistribute() {
}


particles::pidt::mappings::Redistribute::~Redistribute() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::Redistribute::Redistribute(const Redistribute&  masterThread) {
}


void particles::pidt::mappings::Redistribute::mergeWithWorkerThread(const Redistribute& workerThread) {
}
#endif


void particles::pidt::mappings::Redistribute::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::Redistribute::destroyCell(
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
void particles::pidt::mappings::Redistribute::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pidt::mappings::Redistribute::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::mappings::Redistribute::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pidt::mappings::Redistribute::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


bool particles::pidt::mappings::Redistribute::prepareSendToWorker(
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


void particles::pidt::mappings::Redistribute::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pidt::mappings::Redistribute::mergeWithMaster(
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


void particles::pidt::mappings::Redistribute::receiveDataFromMaster(
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


void particles::pidt::mappings::Redistribute::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pidt::mappings::Redistribute::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}
#endif


void particles::pidt::mappings::Redistribute::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::Redistribute::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::Redistribute::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pidt::mappings::Redistribute::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}


void particles::pidt::mappings::Redistribute::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
