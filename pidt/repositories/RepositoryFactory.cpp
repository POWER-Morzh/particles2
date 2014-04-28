#include "particles/pidt/repositories/RepositoryFactory.h"

#include "particles/pidt/repositories/RepositoryArrayStack.h"
#include "particles/pidt/repositories/RepositorySTDStack.h"

#include "particles/pidt/records/RepositoryState.h"

#ifdef Parallel
#include "tarch/parallel/NodePool.h"
#include "peano/parallel/Partitioner.h"
#endif


particles::pidt::repositories::RepositoryFactory::RepositoryFactory() {
  #ifdef Parallel
  peano::parallel::Partitioner::initDatatypes();

  particles::pidt::State::initDatatype();
  particles::pidt::Vertex::initDatatype();
  particles::pidt::Cell::initDatatype();

  if (particles::pidt::records::RepositoryState::Datatype==0) {
    particles::pidt::records::RepositoryState::initDatatype();
  }
  #endif
}


particles::pidt::repositories::RepositoryFactory::~RepositoryFactory() {
}


void particles::pidt::repositories::RepositoryFactory::shutdownAllParallelDatatypes() {
  #ifdef Parallel
  peano::parallel::Partitioner::shutdownDatatypes();

  particles::pidt::State::shutdownDatatype();
  particles::pidt::Vertex::shutdownDatatype();
  particles::pidt::Cell::shutdownDatatype();

  if (particles::pidt::records::RepositoryState::Datatype!=0) {
    particles::pidt::records::RepositoryState::shutdownDatatype();
    particles::pidt::records::RepositoryState::Datatype = 0;
  }
  #endif
}


particles::pidt::repositories::RepositoryFactory& particles::pidt::repositories::RepositoryFactory::getInstance() {
  static particles::pidt::repositories::RepositoryFactory singleton;
  return singleton;
}

    
particles::pidt::repositories::Repository* 
particles::pidt::repositories::RepositoryFactory::createWithArrayStackImplementation(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset,
  int                                          maxCellStackSize,    
  int                                          maxVertexStackSize,    
  int                                          maxTemporaryVertexStackSize    
) {
  #ifdef Parallel
  if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
    return new particles::pidt::repositories::RepositoryArrayStack(geometry, domainSize, computationalDomainOffset,maxCellStackSize,maxVertexStackSize,maxTemporaryVertexStackSize);
  }
  else
  #endif
  return new particles::pidt::repositories::RepositoryArrayStack(geometry, domainSize, computationalDomainOffset,maxCellStackSize,maxVertexStackSize,maxTemporaryVertexStackSize);
}    


particles::pidt::repositories::Repository* 
particles::pidt::repositories::RepositoryFactory::createWithSTDStackImplementation(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset
) {
  #ifdef Parallel
  if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
    return new particles::pidt::repositories::RepositorySTDStack(geometry);
  }
  else
  #endif
  return new particles::pidt::repositories::RepositorySTDStack(geometry, domainSize, computationalDomainOffset);
}
