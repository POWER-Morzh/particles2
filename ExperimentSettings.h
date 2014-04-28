#ifndef __PARTICLES_EXPERIMENT_SETTINGS__
#define __PARTICLES_EXPERIMENT_SETTINGS__


#include <string>


namespace particles {
  class ExperimentSettings;
  class ExperimentSettingsRunTests;
  class ExperimentSettingsProduceVideo;
  class ExperimentSettingsMemoryBenchmark;
  class ExperimentSettingsPureGrid;
  class ExperimentSettingsStationaryParticles;
  class ExperimentSettingsHomogeneousParticles;
}



class particles::ExperimentSettings {
  public:
    enum TimeStepAdapter {
      PureGrid, ExplicitEulerWithPlot, ExplicitEuler
    };

    enum RunnerVariant {
      UnitTests, Simulation, MemoryBenchmark
    };

    // Set in constructor
    int     numberOfTimeSteps;
    // Set in constructor
    double  maximalInitialVelocity;
    double  particleDensity;
    int     ppc;
    double  dt;
    double  breakingDamWidth;

    RunnerVariant   runnerVariant;
    TimeStepAdapter timeSteppingAdapter;

    static ExperimentSettings* chosenConfiguration;
    static void configure(
      const std::string& id,
      const double       particleDensity,
      const int          ppc,
      const double       dt,
      const double       breakingDamWidth
    );
    static std::string getListOfAvailableExperiments();

    virtual ~ExperimentSettings() {};
};


class particles::ExperimentSettingsRunTests: public particles::ExperimentSettings {
  public:
    static const std::string ID;
    ExperimentSettingsRunTests();
};

class particles::ExperimentSettingsProduceVideo: public particles::ExperimentSettings {
  public:
    static const std::string ID;
    ExperimentSettingsProduceVideo(double dt);
};

class particles::ExperimentSettingsMemoryBenchmark: public particles::ExperimentSettings {
  public:
    static const std::string ID;
    ExperimentSettingsMemoryBenchmark();
};

class particles::ExperimentSettingsPureGrid: public particles::ExperimentSettings {
  public:
    static const std::string ID;
    ExperimentSettingsPureGrid();
};

class particles::ExperimentSettingsStationaryParticles: public particles::ExperimentSettings {
  public:
    static const std::string ID;
    ExperimentSettingsStationaryParticles();
};

class particles::ExperimentSettingsHomogeneousParticles: public particles::ExperimentSettings {
  public:
    static const std::string ID;
    ExperimentSettingsHomogeneousParticles(bool splitTree, bool pipeline, bool alwaysReduce);
};


#endif
