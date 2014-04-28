// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIT_STATE_H_ 
#define _PARTICLES_PIT_STATE_H_

#include "particles/pit/records/State.h"
#include "particles/State.h"

#include "peano/grid/Checkpoint.h"

namespace particles { 
  namespace pit { 
    class State;
    /**
     * Forward declaration
     */
    class Vertex;
    /**
     * Forward declaration
     */
    class Cell;

    namespace repositories {
      /**
       * Forward declaration
       */
      class RepositoryArrayStack;
      class RepositorySTDStack;
    }
  }
}


/**
 * PIT Solver State.
 * 
 * @author Tobias Weinzierl
 */
class particles::pit::State: public particles::State< particles::pit::records::State > {
  private: 
    /**
     * Needed for checkpointing.
     */
    friend class particles::pit::repositories::RepositoryArrayStack;
    friend class particles::pit::repositories::RepositorySTDStack;
  
    void writeToCheckpoint( peano::grid::Checkpoint<Vertex,Cell>&  checkpoint ) const;    
    void readFromCheckpoint( const peano::grid::Checkpoint<Vertex,Cell>&  checkpoint );    
  
  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    State();

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
    State(const particles::State< particles::pit::records::State >::PersistentState& argument);
};


#endif
