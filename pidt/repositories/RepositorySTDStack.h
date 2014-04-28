// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIDT_REPOSITORIES_REPOSITORY_ARRAY_STD_H_ 
#define _PARTICLES_PIDT_REPOSITORIES_REPOSITORY_ARRAY_STD_H_ 


#include "particles/pidt/repositories/Repository.h"
#include "particles/pidt/records/RepositoryState.h"

#include "particles/pidt/State.h"
#include "particles/pidt/Vertex.h"
#include "particles/pidt/Cell.h"

#include "peano/grid/Grid.h"
#include "peano/stacks/CellSTDStack.h"
#include "peano/stacks/VertexSTDStack.h"


 #include "particles/pidt/adapters/Nop.h" 
 #include "particles/pidt/adapters/InitGrid.h" 
 #include "particles/pidt/adapters/InitGridAndPlot.h" 
 #include "particles/pidt/adapters/SetupExperimentWithRandomParticleDistribution.h" 
 #include "particles/pidt/adapters/SetupExperimentWithRandomParticleDistributionAndPlot.h" 
 #include "particles/pidt/adapters/MoveParticles.h" 
 #include "particles/pidt/adapters/MoveParticlesAndPlot.h" 



namespace particles { 
  namespace pidt {
      namespace repositories {
        class RepositorySTDStack;  
      }
}
}


class particles::pidt::repositories::RepositorySTDStack: public particles::pidt::repositories::Repository {
  private:
    static tarch::logging::Log _log;
  
    peano::geometry::Geometry& _geometry;
    
    typedef peano::stacks::CellSTDStack<particles::pidt::Cell>       CellStack;
    typedef peano::stacks::VertexSTDStack<particles::pidt::Vertex>   VertexStack;

    CellStack    _cellStack;
    VertexStack  _vertexStack;
    particles::pidt::State          _solverState;
    peano::grid::RegularGridContainer<particles::pidt::Vertex,particles::pidt::Cell>  _regularGridContainer;
    peano::grid::TraversalOrderOnTopLevel                                         _traversalOrderOnTopLevel;

    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::Nop> _gridWithNop;
    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::InitGrid> _gridWithInitGrid;
    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::InitGridAndPlot> _gridWithInitGridAndPlot;
    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::SetupExperimentWithRandomParticleDistribution> _gridWithSetupExperimentWithRandomParticleDistribution;
    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::SetupExperimentWithRandomParticleDistributionAndPlot> _gridWithSetupExperimentWithRandomParticleDistributionAndPlot;
    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::MoveParticles> _gridWithMoveParticles;
    peano::grid::Grid<particles::pidt::Vertex,particles::pidt::Cell,particles::pidt::State,VertexStack,CellStack,particles::pidt::adapters::MoveParticlesAndPlot> _gridWithMoveParticlesAndPlot;

     
   particles::pidt::records::RepositoryState               _repositoryState;
   
    tarch::timing::Measurement _measureNopCPUTime;
    tarch::timing::Measurement _measureInitGridCPUTime;
    tarch::timing::Measurement _measureInitGridAndPlotCPUTime;
    tarch::timing::Measurement _measureSetupExperimentWithRandomParticleDistributionCPUTime;
    tarch::timing::Measurement _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime;
    tarch::timing::Measurement _measureMoveParticlesCPUTime;
    tarch::timing::Measurement _measureMoveParticlesAndPlotCPUTime;

    tarch::timing::Measurement _measureNopCalendarTime;
    tarch::timing::Measurement _measureInitGridCalendarTime;
    tarch::timing::Measurement _measureInitGridAndPlotCalendarTime;
    tarch::timing::Measurement _measureSetupExperimentWithRandomParticleDistributionCalendarTime;
    tarch::timing::Measurement _measureSetupExperimentWithRandomParticleDistributionAndPlotCalendarTime;
    tarch::timing::Measurement _measureMoveParticlesCalendarTime;
    tarch::timing::Measurement _measureMoveParticlesAndPlotCalendarTime;

   
  public:
    RepositorySTDStack(
      peano::geometry::Geometry&                   geometry,
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset
    );
    
    /**
     * Parallel Constructor
     *
     * Used in parallel mode only where the size of the domain is not known 
     * when the type of repository is determined.  
     */
    RepositorySTDStack(
      peano::geometry::Geometry&                   geometry
    );
    
    virtual ~RepositorySTDStack();

    virtual void restart(
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  domainOffset,
      int                                          domainLevel,
      const tarch::la::Vector<DIMENSIONS,int>&     positionOfCentralElementWithRespectToCoarserRemoteLevel
    );
         
    virtual void terminate();
        
    virtual particles::pidt::State& getState();
    virtual const particles::pidt::State& getState() const;
	
    virtual void iterate();

    virtual void writeCheckpoint(peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell> * const checkpoint); 
    virtual void readCheckpoint( peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell> const * const checkpoint );
    virtual peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell>* createEmptyCheckpoint(); 

    virtual void switchToNop();    
    virtual void switchToInitGrid();    
    virtual void switchToInitGridAndPlot();    
    virtual void switchToSetupExperimentWithRandomParticleDistribution();    
    virtual void switchToSetupExperimentWithRandomParticleDistributionAndPlot();    
    virtual void switchToMoveParticles();    
    virtual void switchToMoveParticlesAndPlot();    

    virtual bool isActiveAdapterNop() const;
    virtual bool isActiveAdapterInitGrid() const;
    virtual bool isActiveAdapterInitGridAndPlot() const;
    virtual bool isActiveAdapterSetupExperimentWithRandomParticleDistribution() const;
    virtual bool isActiveAdapterSetupExperimentWithRandomParticleDistributionAndPlot() const;
    virtual bool isActiveAdapterMoveParticles() const;
    virtual bool isActiveAdapterMoveParticlesAndPlot() const;

   
    #ifdef Parallel
    virtual ContinueCommand continueToIterate();
    virtual void runGlobalStep();
    #endif

    virtual void setMaximumMemoryFootprintForTemporaryRegularGrids(double value);
    virtual void logIterationStatistics() const;
    virtual void clearIterationStatistics();
};


#endif
