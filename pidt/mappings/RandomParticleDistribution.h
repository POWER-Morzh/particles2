// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIDT_MAPPINGS_RandomParticleDistribution_H_
#define PARTICLES_PIDT_MAPPINGS_RandomParticleDistribution_H_


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
      class RandomParticleDistribution;
    }
  }
}


/**
 * Add random particles
 * 
 *
 * @author Bart Verleye, Tobias Weinzierl
 * @version $Revision: 1.10 $
 */
class particles::pidt::mappings::RandomParticleDistribution {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    State   _state;

    /**
     * Initialise vertices of vertex
     *
     * Add particles to a vertex if this vertex is within the control domain,
     * if the vertex is unrefined (i.e. add vertices to finest level only),
     * and if the vertex is not a boundary vertex.
     *
     * If we added particles to the boundary vertices, we would get particles
     * outside of the unit square in the serial mode, i.e. if there is no
     * halo layer.
     *
     * !!! Parallelisation
     *
     * In the distributed memory mode, initialising local vertices is more
     * complicated than in the serial variant. We may only create particles
     * that are held by the local domain. If they'd fall into a neighbouring
     * subdomain, we skip it as it is the responsibility of the neighbour to
     * create these particles. The initialisation is non-overlapping.
     */
    void initVertex(
      particles::pidt::Vertex&                     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  x,
      const tarch::la::Vector<DIMENSIONS,double>&  h
    );
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
    RandomParticleDistribution();

    #if defined(SharedMemoryParallelisation)
    /**
     * Copy the state attribute
     */
    RandomParticleDistribution(const RandomParticleDistribution& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~RandomParticleDistribution();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */
    void mergeWithWorkerThread(const RandomParticleDistribution& workerThread);
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
     * Nop
     */
    void destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
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
     * Merge vertex with the incoming vertex from a neighbouring computation node.
     * 
     * When Peano is running in parallel the data exchange is done vertex-wise 
     * between two grid iterations. Thus, before the touchVertexFirstTime-event
     * the vertex, sent by the computation node, which shares this vertex, is 
     * merged with the local copy of this vertex.
     *
     * !!! Heap data
     *
     * If you are working with a heap data structure, your vertices or cells, 
     * respectively, hold pointers to the heap. The received records hold 
     * pointer indices as well. However, these pointers are copies from the 
     * remote ranks, i.e. the pointers are invalid though seem to be set.
     * Receive heap data instead separately without taking the pointers in 
     * the arguments into account. 
     *
     * @param vertex    Local copy of the vertex.
     * @param neighbour Remote copy of the vertex.
     * @param fromRank  See prepareSendToNeighbour()
     * @param isForkOrJoin See preareSendToNeighbour()
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
     * Prepare a vertex to be sent to neighbour
     * 
     * The random mapping just initialises the grid. As this means basically
     * inserting particles into the mesh, there's no reason to communicate.
     * However, Peano realises a Jacobi-type communication along the
     * boundaries. Everytime a vertex is read for the first time, we merge its
     * data with all data sent from other adjacent partitions. Obviously, such
     * a scheme does not work in the very first traversal, as noone has sent
     * data before. This observation leads to ifdefs in the MoveParticle
     * mapping.
     *
     * A different fix than the ifdefs is to make the initialisation, i.e. this
     * mapping, send dummy messages. So no particles are moved around, but the
     * communication channels are created. There's no receive required, but the
     * first move mapping execution can rely on emty messages from each
     * communciation partner, merge these empty messages into local data
     * structures, and then continue.
     *
     * @param vertex        Local vertex.
     * @param toRank        Rank of the neighbour if isForkOrJoin is unset.  
     *                      Otherwise, it is the rank of the master.
     */
    void prepareSendToNeighbour(
      particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Move data to neighbour
     *
     * Throughout the joins or forks of subdomains, data has to be moved 
     * between the nodes. This operation allows the user to plug into these 
     * movements. Different to the neighbour communciation, a move always 
     * implies that Peano is copying the data structure bit-wise to the 
     * remote node. However, if you have heap data and pointers, e.g., 
     * associated to your vertices/cells you have to take care yourself that 
     * this data is moved as well.
     *
     * If data is inside your computational domain, you fork, and this data 
     * now is located at the new boundary, Peano moves the data as well, i.e.
     * the move also can be a (global) copy operation.
     *
     * @param localVertex The local vertex. This is not a copy, i.e. you may 
     *                    modify the vertex before a copy of it is sent away.  
     */
    void prepareCopyToRemoteNode(
      particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    

    /**
     * @see other prepareCopyToRemoteNode() operation for the vertices.
     */
    void prepareCopyToRemoteNode(
      particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
    );


    /**
     * Merge with remote data due to fork or join
     *
     * This operation takes remote data and merges it into the local copy, as  
     * data is moved from one rank to another, e.g. Do not use an assignment 
     * operator on the whole record, as you may overwrite only PDE-specific 
     * fields in localVertex.
     *
     * @param localVertex  Local vertex data. Some information here is already 
     *                     set: Adjacency information from the master, e.g., 
     *                     already is merged. Thus, do not overwrite 
     *                     non-PDE-specific data.
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
     * Merge with remote data due to fork or join
     *
     * This operation takes remote data and merges it into the local copy, as  
     * data is moved from one rank to another, e.g. Do not use an assignment 
     * operator on the whole record, as you may overwrite only PDE-specific 
     * fields in localVertex.
     *
     * @param localCell  Local cell data. Some information here is already 
     *                   set: Adjacency information from the master, e.g., 
     *                   already is merged. Thus, do not overwrite 
     *                   non-PDE-specific data.
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
     * Perpare startup send to worker
     *
     * This operation is called always when we send data to a worker. It is not 
     * called when we are right in a join or fork. The operation is kind of the 
     * replacement of enterCell() on the master, i.e. called for this one instead 
     * of.
     *
     * @see peano::kernel::spacetreegrid::nodes::Node::updateCellsParallelStateAfterLoad()
     */
    bool prepareSendToWorker(
      particles::pidt::Cell&                       fineGridCell,
      particles::pidt::Vertex * const              fineGridVertices,
      const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell,
      int                                        worker
    );
    
    
    /**
     * Merge data from the worker into the master records. This operation is 
     * called on the master, i.e. the const arguments are received copies from 
     * the worker.
     *
     * !!! Heap data
     *
     * If you are working with a heap data structure, your vertices or cells, 
     * respectively, hold pointers to the heap. The received records hold 
     * pointer indices as well. However, these pointers are copies from the 
     * remote ranks, i.e. the pointers are invalid though seem to be set.
     * Receive heap data instead separately without taking the pointers in 
     * the arguments into account.      
     *
     * @param workerGridCell      Valid object iff data reduction is switched on. See State::reduceDataToMaster().
     * @param workerGridVertices  Valid object iff data reduction is switched on. See State::reduceDataToMaster().
     * @param workerEnumerator    Valid object iff data reduction is switched on. See State::reduceDataToMaster().
     * @param workerState         Valid object iff data reduction is switched on. See State::reduceDataToMaster().
     */
    void mergeWithMaster(
      const particles::pidt::Cell&                       workerGridCell,
      particles::pidt::Vertex * const                    workerGridVertices,
      const peano::grid::VertexEnumerator&             workerEnumerator,
      particles::pidt::Cell&                             fineGridCell,
      particles::pidt::Vertex * const                    fineGridVertices,
      const peano::grid::VertexEnumerator&             fineGridVerticesEnumerator,
      particles::pidt::Vertex * const                    coarseGridVertices,
      const peano::grid::VertexEnumerator&             coarseGridVerticesEnumerator,
      particles::pidt::Cell&                             coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&         fineGridPositionOfCell,
      int                                              worker,
      const particles::pidt::State&                      workerState,
      particles::pidt::State&                            masterState
    );


    /**
     * Prepare send to master
     *
     * Counterpart of prepareSendToWorker() that is called at the end of each 
     * iteration if data reduction is switched on. At the moment this function 
     * is called, all the data on the local worker are already streamed to the 
     * stacks, i.e. you basically receive copies of the local cell and the 
     * local vertices. If you modify them, these changes will become undone in 
     * the subsequent iteration.
     *
     * !!! Data Consistency
     *
     * Multilevel data consistency in Peano can be tricky. Most codes thus 
     * introduce a rigorous master-owns pattern. In this case, always the 
     * vertex and cell state on the master is valid, i.e. prepareSendToMaster() 
     * informs the master about state changes. In return, prepareSendToWorker() 
     * feeds the worker withe the new valid state of vertices and cells. 
     * Receive from master operations thus overwrite the worker's local 
     * records with the master's data, as the master always rules.  
     *
     * The coarse data is a copy from the master and may not be modified.
     *
     * !!! Special case: Fork process
     * 
     * In the very first iteration on the worker, the receive process accepting 
     * data from the master is not followed by the corresponding send back even 
     * if the reduction is switched on. Hence, you have two times receive data 
     * from master before this operation is invoked for the first time. See 
     * Node::updateCellsParallelStateBeforeStore() for details on the technical 
     * reasons for this assymetry.
     *
     * !!! Skip sends to master
     *
     * If you switch off the global reduction, i.e. if you call iterate() on 
     * the repository with the parameter false, Peano does not send any data 
     * up along the spacetree. It does not reduce the cell, state, and vertex 
     * data. See State::reduceDataToMaster(). However, this operation is called 
     * nevertheless. This allows you to send data to the master (heap data, 
     * e.g.) even though Peano's kernel does not reduce. If you wanna pick up 
     * the reduction behaviour of Peano, you can still store the result of 
     * reduceDataToMaster() from beginIteration() in your mapping and wrap your 
     * implementation of this routine into an if. 
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
     * Counterpart of prepareSendToWorker(). This operation is called once when 
     * we receive data from the master node. You can manipulate the received 
     * records - get additional data from the heap, e.g. Afterwards, the 
     * received records are merged into the worker's local data due to 
     * mergeWithWorker(). While this operation gives you access to both the 
     * cell and its adjacent vertices in the same order as prepareSendToWorker(),
     * the mergeWithWorker() operations are called on-the-fly in a (probably) 
     * different order, as their order depends on the global space-filling curve.
     *
     * If you manipulate receivedCell or receivedVertices(), respectively, 
     * these modified values will be passed to mergeWithWorker(). The classical 
     * use case is that prepareSendToWorker() sends away some heap data. This 
     * heap data then should be received in this operation, as you have all data 
     * available here in the same order as prepareSendToWorker(). Distribute the 
     * received heap data among the @f$ 2^d +1 @f$ out arguments you have 
     * available. The modified arguments then are forwarded by Peano to 
     * mergeWithWorker().
     *
     * !!! Rationale
     * 
     * The split of the receive process into two stages seems to be artificial 
     * and not very much straightforward. However, two constraints make it 
     * necessary:
     * - Some applications need a single receive point where the data received 
     *   has the same order as prepareSendToWorker().
     * - Some applications need well-initialised vertices when they descend 
     *   somewhere in the worker tree. This descend usually not in the central 
     *   element but an outer part of the tree, i.e. some vertices have to be 
     *   merged before we can also merge the cell and all other vertices.
     *
     * !!! Heap data
     *
     * If you are working with a heap data structure, your vertices or cells, 
     * respectively, hold pointers to the heap. The received records hold 
     * pointer indices as well. However, these pointers are copies from the 
     * remote ranks, i.e. the pointers are invalid though seem to be set.
     * Receive heap data instead separately without taking the pointers in 
     * the arguments into account. 
     *
     * If you receive heap data and need it in the actual merge operation, 
     * i.e. in mergeWithWorker(), we recommend to follow the subsequent steps: 
     * 
     * - Create an entry on the heap here for each vertex.
     * - Store the received data within these heap entries.
     * - Merge the heap data within mergeWithWorker().
     *
     * - Remove the heap entries created in this operation within mergeWithWorker().
     * @param coarseGridVertices  Copy of the coarse vertices of the master 
     *                            node as well worker's records. As you receive 
     *                            the copy, you can alter the local ones, but 
     *                            any change to this data will remain local on this 
     *                            worker, i.e. changes are not committed back to the 
     *                            master. Also, the changes might be lost from adapter
     *                            run to adapter run, i.e. if you switch the adapter
     *                            you wanna use, Peano might come up with different
     *                            coarse vertices and you have to reset data there 
     *                            again. 
     * @param coarseGridCell      Copy fo the coarse cell of the master.
     * @param fineGridPositionOfCell Position of receivedCell relative to coarse 
     *                            cell on master.
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
     * Touch vertex for the first time
     *
     * Calls initVertex().
     *
     * !!! Shared memory parallelisation
     *
     * initVertex() is asking the heap for new indices. As the heap is not
     * thread-safe itself, we make this adapter working serially only.
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
     * Nop
     */
    void touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );
    

    /**
     * Nop
     */
    void enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void leaveCell(
      particles::pidt::Cell&                          fineGridCell,
      particles::pidt::Vertex * const                 fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const                 coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&                          coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfCell
    );


    /**
     * Begin an iteration
     * 
     * Copy solver state into the attribute and assign the heap a name. Also,
     * we have to inform the heap that we'll gonna send data around.
     *
     * @see prepareSendToNeighbour()
     */
    void beginIteration(
      particles::pidt::State&  solverState
    );


    /**
     * End iteration and close communication channels.
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
     * Nop
     */
    void ascend(
      particles::pidt::Cell * const    fineGridCells,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell
    );    
};


#endif
