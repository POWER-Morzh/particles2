#include "particles/pidt/State.h"
#include "particles/pidt/Cell.h"
#include "particles/pidt/Vertex.h"

#include "peano/grid/Checkpoint.h"


bool particles::pidt::State::AlwaysReduceAlongMasterWorkers = false;


particles::pidt::State::State():
  particles::State< particles::pidt::records::State >() {
}


particles::pidt::State::State(const particles::State< particles::pidt::records::State >::PersistentState& argument):
  particles::State< particles::pidt::records::State >(argument) {
}


void particles::pidt::State::writeToCheckpoint( peano::grid::Checkpoint<particles::pidt::Vertex,particles::pidt::Cell>& checkpoint ) const {
  // @todo Insert your code here
}

    
void particles::pidt::State::readFromCheckpoint( const peano::grid::Checkpoint<particles::pidt::Vertex,particles::pidt::Cell>& checkpoint ) {
  // @todo Insert your code here
}


void particles::pidt::State::copyTimeStepSize( const State&  argument) {
  _stateData.setTimeStepSize( argument._stateData.getTimeStepSize() );
}
