// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIDT_VERTEX_H_ 
#define _PARTICLES_PIDT_VERTEX_H_


#include "particles/pidt/records/Vertex.h"
#include "peano/grid/Vertex.h"
#include "peano/grid/VertexEnumerator.h"
#include "peano/utils/Globals.h"
#include "peano/heap/Heap.h"
#include "particles/pidt/records/Particle.h"



/**
 * Results seem to be pretty invariant of this one, i.e. the higher concurrency
 * is almost exactly compensated by the semaphore overhead.
 */
#define LIFT_PARTICLE_USES_SEMAPHORE
#define MOVE_USES_SORTED_PARTICLES


namespace particles { 
  namespace pidt { 
    class Vertex;

    // @todo hab ich noch nicht getestet
    typedef peano::heap::RLEHeap<particles::pidt::records::Particle>  ParticleHeap;
//    typedef peano::heap::PlainHeap<particles::pidt::records::Particle>  ParticleHeap;
  }
}


/**
 * Blueprint for grid vertex.
 * 
 * This file has originally been created by the PDT and may be manually extended to 
 * the needs of your application. We do not recommend to remove anything!
 */
class particles::pidt::Vertex: public peano::grid::Vertex< particles::pidt::records::Vertex > { 
  private: 
    typedef class peano::grid::Vertex< particles::pidt::records::Vertex >  Base;

  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    Vertex();
    
    /**
     * This constructor should not set any attributes. It is used by the 
     * traversal algorithm whenever it allocates an array whose elements 
     * will be overwritten later anyway.  
     */
    Vertex(const Base::DoNotCallStandardConstructor&);
    
    /**
     * Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it. It is kind of a copy constructor that converts an object which 
     * comprises solely persistent attributes into a full attribute. This very 
     * functionality is implemented within the super type, i.e. this constructor 
     * has to invoke the correponsing super type's constructor and not the super 
     * type standard constructor.
     */
    Vertex(const Base::PersistentVertex& argument);
    
    void clearNumberOfEraseTiggers();
    void incNumberOfEraseTriggers();
    void eraseIfAllAdjacentCellsWoldTriggeredErase();


    void noParticlesWereAddedToThisVertex();
    void particlesWereAddedToThisVertex();
    bool wereParticlesAddedToThisVertex() const;


    /**
     * Assign the vertex an index
     */
    void init(int vertexIndex);

    /**
     * @return Vertex index for the heap. Has to be set before due to init().
     */
    int getVertexIndex() const;

    /**
     * Test whether test point is in dual cell.
     *
     * @param x Center of dual cell
     * @param h Size of dual cell
     */
    static bool isContainedInDualCell(
      const tarch::la::Vector<DIMENSIONS,double>&  x,
      const tarch::la::Vector<DIMENSIONS,double>&  h,
      const tarch::la::Vector<DIMENSIONS,double>&  testPoint
    );

    /**
     * Get the dual cell of a particle
     *
     * Assumes that the particle is held by a cell identified by
     * verticesEnumerator. The operation returns a d-dimensional integer
     * vector holding zeros and ones that says which of the cell's adjacent
     * vertices identifies the containing dual cell.
     */
    static tarch::la::Vector<DIMENSIONS,int> getDualCellOfParticle(
      const peano::grid::VertexEnumerator&         verticesEnumerator,
      const tarch::la::Vector<DIMENSIONS,double>&  p
    );

    static tarch::la::Vector<DIMENSIONS,int> getDualCellOfParticle(
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  p
    );

    static tarch::la::Vector<DIMENSIONS,int> getDualCellOfParticleWithinNextFinerLevel(
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      const tarch::la::Vector<DIMENSIONS,double>&  p
    );
};


#endif
