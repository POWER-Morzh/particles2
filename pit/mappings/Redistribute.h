// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIT_MAPPINGS_Redistribute_H_
#define PARTICLES_PIT_MAPPINGS_Redistribute_H_


#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"

#include "peano/grid/VertexEnumerator.h"
#include "peano/MappingSpecification.h"

#include "tarch/multicore/MulticoreDefinitions.h"

#include "particles/pit/Vertex.h"
#include "particles/pit/Cell.h"
#include "particles/pit/State.h"


namespace particles { 
  namespace pit {
    namespace mappings {
      class Redistribute;
    }
  }
}


/**
 * Redistribution Mapping
 *
 * This mapping does something if and only if we have MPI switched on. In this
 * case, it is responsible to move data from one node to the other.
 * 
 * @author Tobias Weinzierl
 */
class particles::pit::mappings::Redistribute {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;
  public:
    /**
     * We do not plut into any of the standard events.
     */
    static peano::MappingSpecification   touchVertexLastTimeSpecification();
    static peano::MappingSpecification   touchVertexFirstTimeSpecification();
    static peano::MappingSpecification   enterCellSpecification();
    static peano::MappingSpecification   leaveCellSpecification();
    static peano::MappingSpecification   ascendSpecification();
    static peano::MappingSpecification   descendSpecification();


    /**
     * Nop
     */
    Redistribute();

    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */
    Redistribute(const Redistribute& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~Redistribute();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */
    void mergeWithWorkerThread(const Redistribute& workerThread);
    #endif

    /**
     * Nop
     */
    void createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createHangingVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const         fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );
        
        
    #ifdef Parallel
    /**
     * Nop
     */
    void mergeWithNeighbour(
      particles::pit::Vertex&  vertex,
      const particles::pit::Vertex&  neighbour,
      int                                           fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareSendToNeighbour(
      particles::pit::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Copy data to remote node
     *
     * If we repartition, we have to send all the local particles held by a
     * cell to the remote rank. However, we have to do this only for inner
     * cells. Outer cells do not hold data.
     *
     * There is no technical need to delete the data though, as this should
     * be done by the corresponding destroy event. However, I wanna avoid that
     * particles are resorted throughout the fork/join, i.e. I wanna put them
     * out of the game as soon as possible. So, I delete the data
     * and thus assure that data is transferred once and only once.
     *
     * Please study the destroy mechanism in AdoptGrid carefully, as it has to
     * ensure that remote nodes that are the roots of remote trees still have a
     * cell index afterwards. I need those cells to sort particles into these
     * remote entities before I stream their data to workers.
     */
    void prepareCopyToRemoteNode(
      particles::pit::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    

    /**
     * @see other prepareCopyToRemoteNode() operation for the vertices.
     */
    void prepareCopyToRemoteNode(
      particles::pit::Cell&                         localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
    );


    /**
     * Nop
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pit::Vertex&  localVertex,
      const particles::pit::Vertex&  masterOrWorkerVertex,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  x,
      const tarch::la::Vector<DIMENSIONS,double>&  h,
      int                                          level
    );


    /**
     * Counterpart of prepareCopyToRemoteNode()
     *
     * We rely on the fact that remote cells have already been initialised
     * geometrically when this operation is invoked. Hence, inner cells are
     * already set to inner and they have a valid index. We thus simply can
     * receive the particles assigned to this cell and append them to the
     * local data (which should be empty).
     *
     * If the local cell already holds data, the redistribution has been
     * called due to the the experiment setup. We only insert the new particles
     * if the local cell is empty, to avoid duplicate initialisation.
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pit::Cell&  localCell,
      const particles::pit::Cell&  masterOrWorkerCell,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Nop
     */
    bool prepareSendToWorker(
      particles::pit::Cell&                       fineGridCell,
      particles::pit::Vertex * const              fineGridVertices,
      const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
      particles::pit::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      particles::pit::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell,
      int                                        worker
    );
    
    
    /**
     * Nop
     */
    void mergeWithMaster(
      const particles::pit::Cell&                       workerGridCell,
      particles::pit::Vertex * const                    workerGridVertices,
      const peano::grid::VertexEnumerator&             workerEnumerator,
      particles::pit::Cell&                             fineGridCell,
      particles::pit::Vertex * const                    fineGridVertices,
      const peano::grid::VertexEnumerator&             fineGridVerticesEnumerator,
      particles::pit::Vertex * const                    coarseGridVertices,
      const peano::grid::VertexEnumerator&             coarseGridVerticesEnumerator,
      particles::pit::Cell&                             coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&         fineGridPositionOfCell,
      int                                              worker,
      const particles::pit::State&                      workerState,
      particles::pit::State&                            masterState
    );


    /**
     * Nop
     */
    void prepareSendToMaster(
      particles::pit::Cell&                       localCell,
      particles::pit::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void receiveDataFromMaster(
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
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pit::Cell&           localCell, 
      const particles::pit::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pit::Vertex&        localVertex,
      const particles::pit::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    #endif


    /**
     * Nop
     */
    void touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );



    /**
     * Nop
     */
    void touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );
    

    /**
     * Nop
     */
    void enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void leaveCell(
      particles::pit::Cell&                          fineGridCell,
      particles::pit::Vertex * const                 fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const                 coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&                          coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfCell
    );


    /**
     * Begin an iteration
     * 
     * We have to initialise the communication on the heap.
     *
     * @see Redistribute()
     */
    void beginIteration(
      particles::pit::State&  solverState
    );


    /**
     * Iteration is done
     * 
     * Inform the heap that the communication has finished.
     */
    void endIteration(
      particles::pit::State&  solverState
    );
    
    
    /**
     * Nop
     */
    void descend(
      particles::pit::Cell * const          fineGridCells,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell
    );


    /**
     * Nop
     */
    void ascend(
      particles::pit::Cell * const    fineGridCells,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell
    );    
};


#endif
