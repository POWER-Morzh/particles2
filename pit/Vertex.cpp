#include "particles/pit/Vertex.h"
#include "peano/utils/Loop.h"
#include "peano/grid/Checkpoint.h"


particles::pit::Vertex::Vertex():
  Base() { 
  _vertexData.setNumberOfAdjacentEraseTriggers(0);
}


particles::pit::Vertex::Vertex(const Base::DoNotCallStandardConstructor& value):
  Base(value) { 
  // Please do not insert anything here
}


particles::pit::Vertex::Vertex(const Base::PersistentVertex& argument):
  Base(argument) {
}


void particles::pit::Vertex::clearNumberOfEraseTiggers() {
  _vertexData.setNumberOfAdjacentEraseTriggers(0);
}


void particles::pit::Vertex::incNumberOfEraseTriggers() {
  assertion1( _vertexData.getNumberOfAdjacentEraseTriggers()>=0,           toString() );
  assertion1( _vertexData.getNumberOfAdjacentEraseTriggers()< TWO_POWER_D, toString() );
  _vertexData.setNumberOfAdjacentEraseTriggers( _vertexData.getNumberOfAdjacentEraseTriggers()+1 );
}


void particles::pit::Vertex::eraseIfAllAdjacentCellsWoldTriggeredErase() {
  assertion1( _vertexData.getNumberOfAdjacentEraseTriggers()>=0,           toString() );
  assertion1( _vertexData.getNumberOfAdjacentEraseTriggers()<=TWO_POWER_D, toString() );
  if (
    getRefinementControl() == Records::Refined &&
    _vertexData.getNumberOfAdjacentEraseTriggers()==TWO_POWER_D
  ) {
    erase();
  }
}
