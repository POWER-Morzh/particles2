#include "particles/pidt/Cell.h"


tarch::la::Vector<DIMENSIONS,int>  particles::pidt::getDualVertexOfParticle(
  const tarch::la::Vector<DIMENSIONS,double>&  cellOffset,
  const tarch::la::Vector<DIMENSIONS,double>&  cellWidth,
  const tarch::la::Vector<DIMENSIONS,double>&  particlePosition
) {
  const tarch::la::Vector<DIMENSIONS,double> relativePositionToCenter = particlePosition - cellOffset - cellWidth / 2.0;
  tarch::la::Vector<DIMENSIONS,int> result;
  for (int d=0; d<DIMENSIONS; d++) {
    result(d) = relativePositionToCenter(d) > 0.0 ? 1 : 0;
  }
  return result;
}


particles::pidt::Cell::Cell():
  Base() { 
  #ifdef Asserts
  _cellData.setNumberOfParticlesInChildren(0);
  #endif
}


particles::pidt::Cell::Cell(const Base::DoNotCallStandardConstructor& value):
  Base(value) { 
}

particles::pidt::Cell::Cell(const Base::PersistentCell& argument):
  Base(argument) {
}

void particles::pidt::Cell::clearNumberOfParticlesInChildren(int particles) {
  assertion2(particles>=0, particles, toString());
  _cellData.setNumberOfParticlesInChildren(particles);
}


void particles::pidt::Cell::incNumberOfParticlesInChildren(const Cell& childCell) {
  assertion2(childCell._cellData.getNumberOfParticlesInChildren()>=0, childCell.toString(), toString());
  assertion2(_cellData.getNumberOfParticlesInChildren()>=0, childCell.toString(), toString());
  _cellData.setNumberOfParticlesInChildren(
    _cellData.getNumberOfParticlesInChildren() +
    childCell._cellData.getNumberOfParticlesInChildren()
  );
}


int particles::pidt::Cell::getNumberOfParticlesInChildren() const {
  assertion1(_cellData.getNumberOfParticlesInChildren()>=0, toString());
  return _cellData.getNumberOfParticlesInChildren();
}


void particles::pidt::Cell::setMaxVComponent( double value ) {
  assertion1( !isRefined(), toString() );

  _cellData.setMaxVComponent( value );
}


void particles::pidt::Cell::clearMaxVComponent() {
  assertion1( isRefined(), toString() );

  _cellData.setMaxVComponent( 0.0 );
}


void particles::pidt::Cell::restrictMaxVComponent(const Cell& childCell) {
  _cellData.setMaxVComponent(
    _cellData.getMaxVComponent() > childCell._cellData.getMaxVComponent() ? _cellData.getMaxVComponent() : childCell._cellData.getMaxVComponent()
  );
}


void particles::pidt::Cell::updateMaxVComponentDueToDrop( double value ) {
  assertion( value>=0.0 );
  _cellData.setMaxVComponent(
    _cellData.getMaxVComponent() > value ? _cellData.getMaxVComponent() : value
  );
}


bool particles::pidt::Cell::getThresholdVelocityForReductionSkip( double t, const tarch::la::Vector<DIMENSIONS,double>&  h ) const {
  assertion3( t>0.0, h, t, toString() );
  return tarch::la::min(h) / t;
}


void particles::pidt::Cell::updateMaxVComponentDueToReductionSkip(double t, const tarch::la::Vector<DIMENSIONS,double>&  h) {
  if (cellWillLiftParticleInNextTimeStep(t,h) ) {
    const double newVValue = getThresholdVelocityForReductionSkip(t,h);
    assertion( newVValue >= _cellData.getMaxVComponent() );
    _cellData.setMaxVComponent( newVValue );
  }
}


bool particles::pidt::Cell::cellWillLiftParticleInNextTimeStep( double t, const tarch::la::Vector<DIMENSIONS,double>&  h ) const {
  return _cellData.getMaxVComponent() >= getThresholdVelocityForReductionSkip(t,h);
}
