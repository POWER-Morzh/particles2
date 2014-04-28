// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIT_MAPPINGS_AdoptGrid_H_
#define PARTICLES_PIT_MAPPINGS_AdoptGrid_H_


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
        class AdoptGrid;
      } 
}
}


/**
 * This is a mapping from the spacetree traversal events to your user-defined activities.
 * The latter are realised within the mappings. 
 * 
 * @author Peano Development Toolkit (PDT) by  Tobias Weinzierl
 * @version $Revision: 1.10 $
 */
class particles::pit::mappings::AdoptGrid {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    State     _state;
  public:
    /**
     * These flags are used to inform Peano about your operation. It tells the 
     * framework whether the operation is empty, whether it works only on the 
     * spacetree leaves, whether the operation can restart if the thread 
     * crashes (resiliency), and so forth. This information allows Peano to
     * optimise the code.
     *
     * @see peano::MappingSpecification for information on thread safety.
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
    AdoptGrid();

    #if defined(SharedMemoryParallelisation)
    /**
     * Copy fields
     */
    AdoptGrid(const AdoptGrid& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~AdoptGrid();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */
    void mergeWithWorkerThread(const AdoptGrid& workerThread);
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
     * Create an inner cell.
     *
     * As this is a new cell, create new heap entry and store this heap index
     * within the cell. There is no need to populate this one - that will
     * automatically be done by the drop mechanism.
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
     * Destroy a cell
     *
     * The destruction takes all the local particles and assigns them to the
     * parent cell. This way, no particles are lost. They first are moved up
     * in the tree before Peano throws away cells. After all particles have
     * moved, we can delete the corresponding heap index.
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
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pit::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    

    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pit::Cell&  localCell,
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
     * Nop
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
     * Prepare a send to workers.
     *
     * We could leave that operation blank. However, we have a clear call on the
     * statistics. Without that one, the assertions fail that ensure that the
     * initial number of particle statistics equals zero.
     *
     * !!! Avoid Reductions
     *
     * pit depends on a permanent reduction of all nodes, so we can return true
     * here without worrying about the performance.
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
     * Merge data received from worker with master data
     *
     * This adapter is responsible to adopt the grid. For this, it has to
     * analyse the number of particles held by cells and subtrees. Hence,
     * the mapping implements only one parallel event that takes the remote
     * number of particles and adds it to the local cell.
     */
    void mergeWithMaster(
      const particles::pit::Cell&                      workerGridCell,
      particles::pit::Vertex * const                   workerGridVertices,
      const peano::grid::VertexEnumerator&             workerEnumerator,
      particles::pit::Cell&                            fineGridCell,
      particles::pit::Vertex * const                   fineGridVertices,
      const peano::grid::VertexEnumerator&             fineGridVerticesEnumerator,
      particles::pit::Vertex * const                   coarseGridVertices,
      const peano::grid::VertexEnumerator&             coarseGridVerticesEnumerator,
      particles::pit::Cell&                            coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&         fineGridPositionOfCell,
      int                                              worker,
      const particles::pit::State&                      workerState,
      particles::pit::State&                            masterState
    );


    /**
     * Nop with an assertion
     *
     * There's nothing to do in this event. However, we ensure that the number of
     * accumulated particles is positive or equals zero. Please note that,
     * following that assertion, subdomains might not hold any particles.
     */
    void prepareSendToMaster(
      particles::pit::Cell&                      localCell,
      particles::pit::Vertex *                   vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pit::Vertex * const       coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pit::Cell&                coarseGridCell,
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
     * Read vertex the first time throughout one iteration
     *
     * Clear the counter of the vertex that keeps track how many adjacent cells
     * would call an erase.
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
     * Read vertex the last time throughout one iteration
     *
     * Invoke vertex's eraseIfAllAdjacentCellsWoldTriggeredErase().
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
     * Enter a cell
     *
     * Clear the analysed tree attribute, as this attribute then can be
     * reduced additively. If it is a leaf cell, do not reset the cell's
     * particle counter to zero but set it to the number of particles held
     * by the cell.
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
     * Leave a cell
     *
     * We can be sure that ascend has been called for this cell plus its
     * children. The cell hence knows how many particles are covered by it. If
     * the number exceeds the maximum number, trigger a refine on the adjacent
     * vertices (if they are not hanging ones). The refine will be realised
     * right in the next iteration.
     *
     * If the cell would coarse as its particle number underruns the threshold,
     * set a marker on the adjacent vertices that this cell would erase. The
     * adjacent vertex will erase if all adjacent cells would erase. If we'd
     * erase immediately, this would not be correct as erases propagate along
     * all adjacent cells (or semantic). If other adjacent cells would hold
     * more particles than the threshold, we would end up with cells having
     * more particles than allowed.
     *
     * Also the refinement has or semantics. So, this operation realises an
     * aggressive refinement but a pessimistic and cautious erase.
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
     * Set local attributes.
     */
    void beginIteration(
      particles::pit::State&  solverState
    );


    /**
     * Nop
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
     * Ascend in the spacetree
     *
     * The ascend realises the particle number reduction. It takes all the
     * particles in children, sums them up, and adds the result to the parent
     * cell. This way, the parent cell (recursively) knows how many particles
     * are held in this subtree.
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
