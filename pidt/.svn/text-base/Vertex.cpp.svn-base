#include "particles/pidt/Vertex.h"
#include "peano/utils/Loop.h"
#include "peano/grid/Checkpoint.h"


particles::pidt::Vertex::Vertex():
  Base() { 
  _vertexData.setNumberOfAdjacentEraseTriggers(0);
  _vertexData.setParticlesAddedToThisCell(false);
  #if defined(Asserts)
  _vertexData.setVertexIndex(-1);
  #endif
}


particles::pidt::Vertex::Vertex(const Base::DoNotCallStandardConstructor& value):
  Base(value) { 
}


particles::pidt::Vertex::Vertex(const Base::PersistentVertex& argument):
  Base(argument) {
}


void particles::pidt::Vertex::clearNumberOfEraseTiggers() {
  _vertexData.setNumberOfAdjacentEraseTriggers(0);
}


void particles::pidt::Vertex::noParticlesWereAddedToThisVertex() {
  _vertexData.setParticlesAddedToThisCell(false);
}


void particles::pidt::Vertex::particlesWereAddedToThisVertex() {
  _vertexData.setParticlesAddedToThisCell(true);
}


bool particles::pidt::Vertex::wereParticlesAddedToThisVertex() const {
  return _vertexData.getParticlesAddedToThisCell();
}


void particles::pidt::Vertex::incNumberOfEraseTriggers() {
  _vertexData.setNumberOfAdjacentEraseTriggers( _vertexData.getNumberOfAdjacentEraseTriggers()+1 );
}


void particles::pidt::Vertex::eraseIfAllAdjacentCellsWoldTriggeredErase() {
  if (
    getRefinementControl() == Records::Refined &&
    _vertexData.getNumberOfAdjacentEraseTriggers()==TWO_POWER_D
  ) {
    erase();
  }
}


void particles::pidt::Vertex::init(int vertexIndex) {
  assertion( vertexIndex>=0 );
  _vertexData.setVertexIndex(vertexIndex);
}


int particles::pidt::Vertex::getVertexIndex() const {
  assertion1( _vertexData.getVertexIndex()!=-1,toString() );
  return _vertexData.getVertexIndex();
}


bool particles::pidt::Vertex::isContainedInDualCell(
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  const tarch::la::Vector<DIMENSIONS,double>&  testPoint
) {
  bool result = true;
  for (int d=0; d<DIMENSIONS; d++) {
    assertion3(h(d)>=0.0,x,h,testPoint);
    result &= testPoint(d) >= x(d)-h(d)/2;
    result &= testPoint(d) <= x(d)+h(d)/2;
  }
  return result;
}


tarch::la::Vector<DIMENSIONS,int> particles::pidt::Vertex::getDualCellOfParticle(
  const peano::grid::VertexEnumerator&         verticesEnumerator,
  const tarch::la::Vector<DIMENSIONS,double>&  p
) {
  return getDualCellOfParticle(verticesEnumerator.getCellCenter(),p);
}


tarch::la::Vector<DIMENSIONS,int> particles::pidt::Vertex::getDualCellOfParticle(
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  p
) {
  tarch::la::Vector<DIMENSIONS,int> result;
  for (int d=0; d<DIMENSIONS; d++) {
    result(d) = p(d) < cellCentre(d) ? 0 : 1;
  }
  return result;
}



tarch::la::Vector<DIMENSIONS,int> particles::pidt::Vertex::getDualCellOfParticleWithinNextFinerLevel(
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  const tarch::la::Vector<DIMENSIONS,double>&  p
) {
  tarch::la::Vector<DIMENSIONS,int> result;
  for (int d=0; d<DIMENSIONS; d++) {
    const double threshold0 = coarseGridVerticesEnumerator.getVertexPosition()(d) + 0.5/3.0 * coarseGridVerticesEnumerator.getCellSize()(d);
    const double threshold1 = coarseGridVerticesEnumerator.getVertexPosition()(d) + 1.5/3.0 * coarseGridVerticesEnumerator.getCellSize()(d);
    const double threshold2 = coarseGridVerticesEnumerator.getVertexPosition()(d) + 2.5/3.0 * coarseGridVerticesEnumerator.getCellSize()(d);
    if ( p(d)<threshold0 ) {
      result(d) = 0;
    }
    else if ( p(d)<threshold1 ) {
      result(d) = 1;
    }
    else if ( p(d)<threshold2 ) {
      result(d) = 2;
    }
    else {
      result(d) = 3;
    }
  }
  return result;
}
