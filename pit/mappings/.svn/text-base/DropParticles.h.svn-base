// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIT_MAPPINGS_DropParticles_H_
#define PARTICLES_PIT_MAPPINGS_DropParticles_H_


#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"

#include "peano/grid/VertexEnumerator.h"
#include "peano/MappingSpecification.h"

#include "tarch/multicore/MulticoreDefinitions.h"

#include "particles/pit/Vertex.h"
#include "particles/pit/Cell.h"
#include "particles/pit/State.h"


#include "particles/pit/records/Particle.h"

namespace particles { 
  namespace pit {
    namespace mappings {
      class DropParticles;
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
class particles::pit::mappings::DropParticles {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    ParticleHeap::HeapEntries extractParticlesToBeDroppedIntoChildCell(
      const particles::pit::Cell&                  coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridCellOffset,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridCellH
    ) const;
  public:
    /**
     * Realises the reflecting boundaries. If you have a proper lift mechanism,
     * the reflection has to be evaluated on the root node of the tree only, i.e.
     * on the node having root as parent.
     */
    static void reflectParticle( particles::pit::records::Particle& particle );

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
     * Mapping constructor.
     *
     * Nop
     */
    DropParticles();

    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */
    DropParticles(const DropParticles& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~DropParticles();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */

    void mergeWithWorkerThread(const DropParticles& workerThread);
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
     * Nop
     *
     * Realised in LiftParticles.
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
     *
     * Realised in LiftParticles.
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
     * Perpare startup send to worker
     *
     * Extract all particles from the coarser cell that are to be dropped into the
     * fine grid cell and send them to worker. If the coarser cell is the root
     * cell, we are running this code on the global master, and the are no
     * particles on the coarser level. Otherwise, there always is at least a
     * heap index.
     *
     * @see descend()
     */
    bool prepareSendToWorker(
      particles::pit::Cell&                       fineGridCell,
      particles::pit::Vertex * const              fineGridVertices,
      const peano::grid::VertexEnumerator&        fineGridVerticesEnumerator,
      particles::pit::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&        coarseGridVerticesEnumerator,
      particles::pit::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell,
      int                                         worker
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
     * Counterpart of prepareSendToWorker().
     * 
     * Take the data from the master and insert it into received cell. Before,
     * we have to assign the received cell and index. See mergeWithWorker()
     * for the further particles' lifecycle.
     *
     * !!! Remarks on Cell Indices
     *
     * receivedCell is a bit-wise copy from the master node. As a result, it
     * has to hold a heap index. However, this value is invalid - it refers to
     * a heap entry on the master. We hence first create a new index and
     * overwrite the received cell's property. Then, we store the received
     * particle data from the master in the heap given that brand new heap
     * index. Finally, we merge the received heap data into the local tree's
     * root and erase the newly created index from the heap. Merge and free
     * mechanism can be found in mergeWithWorker().
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
     * Merge received data with worker data
     *
     * Takes the particle (temporary) assigned to receivedMasterCell and copies
     * its particles into the local cell. Afterwards, the received cell's heap
     * index is freed. This time, we really
     */
    void mergeWithWorker(
      particles::pit::Cell&           localCell, 
      const particles::pit::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Counterpart of mergeWithMaster()
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
     * Enter a cell and apply boundary conditions
     *
     * Basically, the drop mechanism's enter cell event is empty, as there is
     * nothing to drop in a cell. However, if the cell is the root of the tree,
     * we apply reflecting boundary conditions here. Afterwards, the reflected
     * particles (and those that haven't hit the boundary) will be sorted into
     * the children due to descend().
     *
     * In parallel mode, the reflection acts if any only if we are on the rank
     * that is the only worker of the global master, i.e. the rank that is
     * responsible for the coarsest inner tree cell. There is no explicit check
     * for this situation, i.e. we apply the reflection method on each (parallel)
     * root node in the grid. As those nodes still are few, as the reflection
     * reduces to nop for those cells that are not adjacent to the global domain
     * boundary, and as the reflection is idempotent, we can do this, and we can
     * afford it.
     */
    void enterCell(
      particles::pit::Cell&                     fineGridCell,
      particles::pit::Vertex * const            fineGridVertices,
      const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
      particles::pit::Vertex * const            coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&                     coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
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
     * Nop
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
     * Descend in the spacetree
     *
     * Loop over the @f$ 3^d @f$ children and drop the particles from the
     * coarser cell into these children. Afterward, there are no particles on
     * the coarser level anymore.
     *
     * !!! Distributed memory parallelisation
     *
     * It might happen that one of the children is a remote node, i.e. the root
     * of a remote spacetree. We can be sure that no particles are to be moved
     * into a deployed cell as prepareSendToWorker() is called before descend()
     * and already has handled those particles.
     */
    void descend(
      particles::pit::Cell * const          fineGridCells,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
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
