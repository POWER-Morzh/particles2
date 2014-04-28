// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIDT_STATE_H_ 
#define _PARTICLES_PIDT_STATE_H_

#include "particles/pidt/records/State.h"
#include "peano/grid/State.h"
#include "particles/State.h"

#include "peano/grid/Checkpoint.h"

namespace particles { 
  namespace pidt { 
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
 * PIDT solver state
 * 
 * @author Tobias Weinzierl
 */
class particles::pidt::State: public particles::State< particles::pidt::records::State > {
  private: 
    /**
     * Needed for checkpointing.
     */
    friend class particles::pidt::repositories::RepositoryArrayStack;
    friend class particles::pidt::repositories::RepositorySTDStack;
  
    void writeToCheckpoint( peano::grid::Checkpoint<Vertex,Cell>&  checkpoint ) const;    
    void readFromCheckpoint( const peano::grid::Checkpoint<Vertex,Cell>&  checkpoint );    
  
  public:
    static bool AlwaysReduceAlongMasterWorkers;

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
    State(const particles::State< particles::pidt::records::State >::PersistentState& argument);

    /**
     * @see LiftParticles::beginIteration()
     */
    void copyTimeStepSize( const State&  argument);

};


#endif
