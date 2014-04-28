// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIDT_MAPPINGS_AdoptGrid_H_
#define PARTICLES_PIDT_MAPPINGS_AdoptGrid_H_


#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"

#include "peano/grid/VertexEnumerator.h"
#include "peano/MappingSpecification.h"

#include "tarch/multicore/MulticoreDefinitions.h"

#include "particles/pidt/Vertex.h"
#include "particles/pidt/Cell.h"
#include "particles/pidt/State.h"


namespace particles { 
  namespace pidt {
    namespace mappings {
      class AdoptGrid;
    }
  }
}


/**
 * Adopt the grid to particles within the cells.
 *
 * This class is basically the same as in the pit code. However, the enterCell
 * on the finest grid is slightly different: We analyse how many particles are
 * contained within the tree. This requires to check how many particles are
 * held by a fine grid cell by running through the 2^d intersecting dual cells.
 * This check basically is done already by the mover, so we could reuse this
 * properity. However, I wanna separate the grid adoption from the remaining
 * code part as clearly as possible. I hence store the average particle number
 * within the cells.
 *
 * Another difference yet a difference that's pure technical is destroyVertex.
 * It is the counterpart of pit's destroyCell and moves all associated
 * particles up in the tree. For this, it first has to determine the dual
 * coarse cell.
 *
 * !!! Parallelisation
 *
 * Please note in destroyVertex that the coarsest vertices of a worker spacetree
 * never ever are erased.
 *
 * @author Tobias Weinzierl
 */
class particles::pidt::mappings::AdoptGrid {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    /**
     * Local copy of the state. It is never changed throughout the traversals.
     */
    State     _state;
  public:
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
     * Copy _state property from master thread.
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
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createHangingVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );


    /**
     * Destroy a vertex.
     *
     * This operation is exactly the same as the one for
     * destroyHangingVertex(). I hence moved the realisation to LiftParticles
     * which in same way does make sense, as it moves data from a fine grid to
     * coarser levels.
     *
     * @see LiftParticles::destroyVertex()
     * @see AdoptGrid
     */
    void destroyVertex(
      const particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const         fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );
        
        
    #ifdef Parallel
    /**
     * Nop
     */
    void mergeWithNeighbour(
      particles::pidt::Vertex&  vertex,
      const particles::pidt::Vertex&  neighbour,
      int                                           fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareSendToNeighbour(
      particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    

    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
    );


    /**
     * Nop
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pidt::Vertex&  localVertex,
      const particles::pidt::Vertex&  masterOrWorkerVertex,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  x,
      const tarch::la::Vector<DIMENSIONS,double>&  h,
      int                                          level
    );


    /**
     * Nop
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pidt::Cell&  localCell,
      const particles::pidt::Cell&  masterOrWorkerCell,
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
     * pidt's efficiency gain compared to pit results from the fact that the pidt
     * code is able to skip reductions. We don't have to worry due to reductions
     * in the adopt mapping though: If reductions are switched off, the
     * covered finer grids do not change and hence there's no need for the coarser grids
     * to refine.
     *
     * The same rationale holds when we analyse the subtrees: Usually, we
     * recompute the weights on the subtrees explicitly throughout the traversal.
     * For this, we reset the load to zero when we descend (or send away data)
     * and then reaccumulate the tree properties due to an analysed tree
     * grammar. If we do not restrict data as no particles leave a subtree
     * in this time step, we also do not have to reset the local workload.
     */
    bool prepareSendToWorker(
      particles::pidt::Cell&                     fineGridCell,
      particles::pidt::Vertex * const            fineGridVertices,
      const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
      particles::pidt::Vertex * const            coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      particles::pidt::Cell&                     coarseGridCell,
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
     *
     * !!! Validation
     *
     * In principle, we could check whether
     * cellWillLiftParticleInNextTimeStep() holds on the fine grid cell. If it
     * does not hold, reduction should be switched off and in return
     * mergeWithMaster() should not be called at all. However, the reduction
     * skips are only a recommendation of the mappings. Internally, Peano
     * decides whether to skip reductions or not. So we can't really validate
     * the skipping here.
     */
    void mergeWithMaster(
      const particles::pidt::Cell&              workerGridCell,
      particles::pidt::Vertex * const           workerGridVertices,
      const peano::grid::VertexEnumerator&      workerEnumerator,
      particles::pidt::Cell&                    fineGridCell,
      particles::pidt::Vertex * const           fineGridVertices,
      const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
      particles::pidt::Vertex * const           coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&                    coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
      int                                       worker,
      const particles::pidt::State&             workerState,
      particles::pidt::State&                   masterState
    );


    /**
     * Nop with an assertion
     *
     * There's nothing to do in this event. However, we ensure that the number of
     * accumulated particles is positive or equals zero. Please note that,
     * following that assertion, subdomains might not hold any particles.
     */
    void prepareSendToMaster(
      particles::pidt::Cell&                       localCell,
      particles::pidt::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void receiveDataFromMaster(
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
    );


    /**
     * Counterpart of mergeWithMaster()
     */
    void mergeWithWorker(
      particles::pidt::Cell&           localCell, 
      const particles::pidt::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Counterpart of mergeWithMaster()
     */
    void mergeWithWorker(
      particles::pidt::Vertex&        localVertex,
      const particles::pidt::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    #endif


    /**
     * Touch vertex for the very first time and clear counter
     *
     * For each vertex, we keep track how many of the adjacent cells would like
     * to trigger an erase. This counter is reset in touchVertexFirstTime(),
     * accumulated in leaveCell(), and evaluated in touchVertexLastTime(). The
     * operation works on the whole tree and is thread-safe since it exclusively
     * works with fineGridVertex.
     */
    void touchVertexFirstTime(
      particles::pidt::Vertex&                     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );



    /**
     * Touch vertex fo the last time and call erase if necesssary
     *
     * If all adjacent cells would like to erase their subtrees, this event
     * switches the vertex state to erase-triggered due to
     * eraseIfAllAdjacentCellsWoldTriggeredErase(). It is thread-safe and works
     * on the whole tree.
     */
    void touchVertexLastTime(
      particles::pidt::Vertex&                     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );
    

    /**
     * Enter a cell
     *
     * If we invoke enterCell on a refined cell, we clear its statistics.
     * Otherwise, we run over all adjacent vertices and compute the average
     * particle number for this cell. Hanging nodes here are skipped, as their
     * particles are moved to a coarser level next and their will contribute
     * to another cell.
     *
     * !!! Shared memory parallelisation
     *
     * This operation is thread safe if we apply red-black colouring on the
     * fine grid level.
     */
    void enterCell(
      particles::pidt::Cell&                    fineGridCell,
      particles::pidt::Vertex * const           fineGridVertices,
      const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
      particles::pidt::Vertex * const           coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&                    coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
    );


    /**
     * Leave a cell
     *
     * If we leave a cell, we know that all data from the finer grids that are
     * covered by this cell have been reduced. We now can evaluate the
     * coarsening/refinement criteria and update the vertex refinement flags.
     * This operation works on the whole tree.
     *
     * !!! Shared memory parallelisation
     *
     * The operation is thread-safe if no two adjacent fine grid cells are
     * studied at the same time. Red-black colouring on the fine grid hence does
     * the job.
     */
    void leaveCell(
      particles::pidt::Cell&                    fineGridCell,
      particles::pidt::Vertex * const           fineGridVertices,
      const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
      particles::pidt::Vertex * const           coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&                    coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void beginIteration(
      particles::pidt::State&  solverState
    );


    /**
     * Nop
     */
    void endIteration(
      particles::pidt::State&  solverState
    );
    
    
    /**
     * Nop
     */
    void descend(
      particles::pidt::Cell * const          fineGridCells,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell
    );


    /**
     * Ascend in spacetree and reduce statistics
     *
     * We sum up the weights (particle counts) from the fine grid cells into
     * the coarse grid cell. This process affects the whole tree and is
     * parallel without data races if no two adjacent coarse grid cells are
     * handled at the same time which is avoided by Peano anyway.
     */
    void ascend(
      particles::pidt::Cell * const         fineGridCells,
      particles::pidt::Vertex * const       fineGridVertices,
      const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
      particles::pidt::Vertex * const       coarseGridVertices,
      const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
      particles::pidt::Cell&                coarseGridCell
    );    
};


#endif
