#include "particles/pit/myfunctions/RepresentationChange.h"
#include "particles/pit/myfunctions/CoordinatesRepresentationChange.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>
#include <string>
#include "peano/utils/Loop.h"



tarch::la::Vector<N_INTERVALS_HISTOGRAM, int> particles::pit::myfunctions::RepresentationChange::_histogramData(0);

double particles::pit::myfunctions::RepresentationChange::_global_max_error = 0;
double particles::pit::myfunctions::RepresentationChange::_globalMaxOffset = 0;
double particles::pit::myfunctions::RepresentationChange::_globalMaxRelativeError = 0;
double particles::pit::myfunctions::RepresentationChange::_globalMaxL2ErrorNorm = 0;
int particles::pit::myfunctions::RepresentationChange::_globalNormAdditions = 0;
tarch::la::Vector<DIMENSIONS, double> particles::pit::myfunctions::RepresentationChange::_globalL2ErrorNorm(0);
tarch::la::Vector<DIMENSIONS, double> particles::pit::myfunctions::RepresentationChange::_globalL2OffsetNorm(0);

int particles::pit::myfunctions::RepresentationChange::_iteration = 0;

bool particles::pit::myfunctions::RepresentationChange::_outputInConsole = 0;

std::ostringstream particles::pit::myfunctions::RepresentationChange::_maxRelativeErrorOut;
std::ostringstream particles::pit::myfunctions::RepresentationChange::_maxErrorOut;
std::ostringstream particles::pit::myfunctions::RepresentationChange::_maxOffsetOut;
std::ostringstream particles::pit::myfunctions::RepresentationChange::_RMSDOut;
std::ostringstream particles::pit::myfunctions::RepresentationChange::_L2ErrorNormOut;
std::ostringstream particles::pit::myfunctions::RepresentationChange::_L2NormOut;
std::ostringstream particles::pit::myfunctions::RepresentationChange::_meanVelocityOut;


void particles::pit::myfunctions::RepresentationChange::writeHistogramData( const std::string& filename, const bool& writeFirstTime ) {
  std::ofstream out;
  if( writeFirstTime ) {
    out.open( filename.c_str() );
  } else {
    out.close();
    out.open( filename.c_str(), std::ofstream::app );
  }
  if ( (!out.fail()) && out.is_open() && !writeFirstTime ) {
    for(int d = 0; d<_histogramData.size(); d++) {
      out << _histogramData[d] << " ";
    }
    out << std::endl;
  }
}


void particles::pit::myfunctions::RepresentationChange::processHistogram( const tarch::la::Vector<DIMENSIONS,double>& Norm ) {
  double bigBound = 0.001, smallBound = 0.000001;
  double check = smallBound;
  double oneStep = pow(bigBound/smallBound, 1.0/(N_INTERVALS_HISTOGRAM-3)); // We subtract 3 because two places already reserved
  //std::cout << "processHistogram(), oneStep=" << oneStep << std::endl;
  //std::cout << "processHistogram(), n_intervals=" << N_INTERVALS_HISTOGRAM << std::endl;

  // We save the data in increasing order.

  for(int d = 0; d<DIMENSIONS; d++) {
    check = smallBound;

    if(Norm[d] < smallBound) {
      _histogramData[0]++;
    } else if(Norm[d] >= bigBound) {
      _histogramData[N_INTERVALS_HISTOGRAM - 1]++;
    } else {

      for(int i = 1; i< N_INTERVALS_HISTOGRAM-1; i++) {
        if(Norm[d] >= check) {
          check *= oneStep;
          //std::cout << check << std::endl;

          if(Norm[d] < check) {
            _histogramData[i]++;
            break;
          }

        }
      }

      if(Norm[d] >= check && Norm[d] <bigBound) {
        // If we came here it means that we did not save
        //std::cout << "processHistogram() - ERROR -  we didn't save data about Norm in _histogramData for: " << Norm[d] << std::endl;
      }

    }
  }
}


void particles::pit::myfunctions::RepresentationChange::printParticlesInfo(const particles::pit::Cell& fineGridCell, const std::string normName, const tarch::la::Vector<DIMENSIONS, double> norm ) {
  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();

  if(NumberOfParticles > 0) {
    const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);
    const ParticleCompressedHeap::HeapEntries& compressedParticles = ParticleCompressedHeap::getInstance().getData(cellIndex);
    const tarch::la::Vector<DIMENSIONS, double> meanVelocity = fineGridCell.getMeanVelocity();

    // Setuping view of output
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    std::cout.precision(20);
    //typedef std::numeric_limits< double > dbl;
    //std::cout << "Precision for output: " << dbl::digits10 << std::endl;

    std::cout << "\n************ Data for Cell [" << cellIndex << "];" << " Number of Particles: " << NumberOfParticles << " **************\n";
    std::cout << "************ Mean velocity saved in Cell: [";
    for(int d=0; d<DIMENSIONS; d++) {
      std::cout << meanVelocity[d] << " ";
    }
    std::cout << "]\n";

    // Norm
    std::cout << "\n////" << normName << ": ( " ;
    for(int d=0; d<DIMENSIONS; d++) {
      std::cout << norm[d] << " ";
    }
    std::cout << " );\n\n";

    // Velocities
    std::cout << "---Velocities---------------------------:" << std::endl;
    for (int i=0; i<NumberOfParticles; i++) {
      for(int d=0; d<DIMENSIONS; d++) {
    	std::cout << ( currentParticles.at(i)._persistentRecords._v(d) ) << " ";
      }
      std::cout << std::endl;
    }

    // Offsets of velocities
    std::cout << "---Offsets of velocities---------------------------:" << std::endl;
    for (int i=0; i<NumberOfParticles; i++) {
      for(int d=0; d<DIMENSIONS; d++) {
    	std::cout << std::abs( currentParticles.at(i)._persistentRecords._v(d)) - meanVelocity[d] << " ";
      }
      std::cout << std::endl;
    }

    // Compressed offsets of velocities
    std::cout << "---Offsets of velocities compressed---------------------------:" << std::endl;
    for (int i=0; i<NumberOfParticles; i++) {
      for(int d=0; d<DIMENSIONS; d++) {
    	std::cout << compressedParticles.at(i).getV()[d] << " ";
      }
      std::cout << std::endl;
    }

    double offset;
    // Error
//    std::cout << "---Relative Errors---------------------------:" << std::endl;
//    for (int i=0; i<NumberOfParticles; i++) {
//      for(int d=0; d<DIMENSIONS; d++) {
//        offset = std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d];
//    	std::cout << std::abs( (MUL_FACTOR*offset- compressedParticles.at(i).getV()[d]) / (MUL_FACTOR*offset) ) << " ";
//      }
//      std::cout << std::endl;
//    }
    std::cout << "---Absolute Errors---------------------------:" << std::endl;
    for (int i=0; i<NumberOfParticles; i++) {
      for(int d=0; d<DIMENSIONS; d++) {
          offset = std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d];
          std::cout << std::abs( (MUL_FACTOR*offset - compressedParticles.at(i).getV()[d]) / MUL_FACTOR ) << " ";
      }
      std::cout << std::endl;
    }

    std::cout << "********End of output for Cell [" << cellIndex << "];" << " Number of Particles: " << NumberOfParticles << " ***********\n\n";
  }
}

void particles::pit::myfunctions::RepresentationChange::leaveCell(particles::pit::Cell& fineGridCell) {

  std::cout <<"leaveCell()!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << MANTISSA << std::endl;

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
//std::cout << "cellIndex in leaveCell():" << cellIndex << std::endl;

  if(NumberOfParticles > 0) {
    const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);

    // Compute the mean value of the velocity for each axes
    tarch::la::Vector<DIMENSIONS, double> meanVelocity = computeMeanVelocity(currentParticles, NumberOfParticles);

    // Compute the mean value of the coordinate for each axes
    tarch::la::Vector<DIMENSIONS, double> meanCoordinate = particles::pit::myfunctions::CoordinatesRepresentationChange::computeMeanCoordinate(currentParticles, NumberOfParticles);

    // Write mean velocity and coordinate in Cell
    fineGridCell.setMeanVelocity(meanVelocity);
    fineGridCell.setMeanCoordinate(meanCoordinate);

    // Write in Heap of compressed Particles
    writeInCompressedHeap(currentParticles, cellIndex, meanVelocity, meanCoordinate);
  }
}


tarch::la::Vector<DIMENSIONS, double> particles::pit::myfunctions::RepresentationChange::computeMeanVelocity(
  const ParticleHeap::HeapEntries& currentParticles,
  const int& NumberOfParticles
) {
  tarch::la::Vector<DIMENSIONS, double> meanVelocity(0);
  for (int i=0; i<NumberOfParticles; i++) {
    for(int d=0; d<DIMENSIONS; d++) {
	  meanVelocity[d] += std::abs( currentParticles.at(i)._persistentRecords._v[d] );
    }
  }
  for (int d =0; d<DIMENSIONS; d++) {
    meanVelocity[d] /= NumberOfParticles;
  }


  return meanVelocity;
}


tarch::la::Vector<DIMENSIONS, double> particles::pit::myfunctions::RepresentationChange::computeRMSD( const particles::pit::Cell& fineGridCell ) {
  tarch::la::Vector<DIMENSIONS, double> rmsd(0);

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
  const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);
  const ParticleCompressedHeap::HeapEntries& compressedParticles = ParticleCompressedHeap::getInstance().getData(cellIndex);

  tarch::la::Vector<DIMENSIONS, double> meanVelocity(0);

  //Here we check if there more than one particle to prevent division by zero
  if ( NumberOfParticles > 1 ) {
    // Compute the mean value of the velocity for each axes
    meanVelocity = computeMeanVelocity(currentParticles, NumberOfParticles);

    double precise_offset = 0;

    for (int i=0; i<NumberOfParticles; i++) {
	  for(int d=0; d < DIMENSIONS; d++) {
	      precise_offset = std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d];

	    rmsd[d] += std::pow ( ( (MUL_FACTOR*precise_offset - compressedParticles.at(i).getV()[d])/ (MUL_FACTOR*precise_offset) ), 2);
	  }
    }
    for(int d=0; d < DIMENSIONS; d++) {
      rmsd[d] = std::sqrt( rmsd[d] / NumberOfParticles );
    }
  }

  return rmsd;
}


double particles::pit::myfunctions::RepresentationChange::computeMaxRelativeError( const particles::pit::Cell& fineGridCell ) {

  double maxRelativeError = 0;

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
  const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);
  const ParticleCompressedHeap::HeapEntries& compressedParticles = ParticleCompressedHeap::getInstance().getData(cellIndex);

  tarch::la::Vector<DIMENSIONS, double> meanVelocity(0);

  // Here we check if there more than one particle to prevent division by zero
  if ( NumberOfParticles > 1 ) {
    // Compute the mean value of the velocity for each axes
    meanVelocity = computeMeanVelocity(currentParticles, NumberOfParticles);

    double precise_offset = 0;

    for (int i=0; i<NumberOfParticles; i++) {
	  for(int d=0; d < DIMENSIONS; d++) {
	      precise_offset = std::abs(std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d]);

	    if( maxRelativeError <  std::abs( (MUL_FACTOR*precise_offset - std::abs(compressedParticles.at(i).getV()[d])) / (MUL_FACTOR*precise_offset) ) ) {
	      maxRelativeError = std::abs( (MUL_FACTOR*precise_offset - std::abs(compressedParticles.at(i).getV()[d])) / (MUL_FACTOR*precise_offset));
	    }
	  }
    }
  }

  return maxRelativeError;
}


tarch::la::Vector<DIMENSIONS, double> particles::pit::myfunctions::RepresentationChange::computeL2ErrorNorm( const particles::pit::Cell& fineGridCell ) {

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
  const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);
  const ParticleCompressedHeap::HeapEntries& compressedParticles = ParticleCompressedHeap::getInstance().getData(cellIndex);

  tarch::la::Vector<DIMENSIONS, double> l2ErrorNorm(0);
  tarch::la::Vector<DIMENSIONS, double> meanVelocity(0);

  if ( NumberOfParticles > 0 ) {
    // Compute the mean value of the velocity for each axes
    meanVelocity = computeMeanVelocity(currentParticles, NumberOfParticles);

    double precise_offset = 0;
    for (int i=0; i<NumberOfParticles; i++) {
	  for(int d=0; d < DIMENSIONS; d++) {
	    precise_offset = std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d];
	    l2ErrorNorm[d] += std::abs(MUL_FACTOR*precise_offset - compressedParticles.at(i).getV()[d]) / MUL_FACTOR;
	  }
    }
    for (int d =0; d<DIMENSIONS; d++) {
      l2ErrorNorm[d] /= NumberOfParticles;
    }
  }


  return l2ErrorNorm;
}


tarch::la::Vector<DIMENSIONS, double> particles::pit::myfunctions::RepresentationChange::computeL2Norm( const particles::pit::Cell& fineGridCell ) {

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
  const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);
  //const ParticleCompressedHeap::HeapEntries& compressedParticles = ParticleCompressedHeap::getInstance().getData(cellIndex);

  tarch::la::Vector<DIMENSIONS, double> l2Norm(0);
  tarch::la::Vector<DIMENSIONS, double> meanVelocity(0);

  if ( NumberOfParticles > 0 ) {
    // Compute the mean value of the velocity for each axes
    meanVelocity = computeMeanVelocity(currentParticles, NumberOfParticles);


    for (int i=0; i<NumberOfParticles; i++) {
	  for(int d=0; d < DIMENSIONS; d++) {
	    l2Norm[d] += std::abs( std::abs(currentParticles.at(i).getV()[d]) - meanVelocity[d] );
	  }
    }
    for (int d =0; d<DIMENSIONS; d++) {
      l2Norm[d] /= NumberOfParticles;
    }
  }


  return l2Norm;
}


double particles::pit::myfunctions::RepresentationChange::computeMaxOffset( const particles::pit::Cell& fineGridCell ) {

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
  const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);

  double maxOffset = 0;
  tarch::la::Vector<DIMENSIONS, double> meanVelocity = fineGridCell.getMeanVelocity();

  if ( NumberOfParticles > 0 ) {

    for (int i=0; i<NumberOfParticles; i++) {
	  for(int d=0; d < DIMENSIONS; d++) {
	    if( maxOffset < std::abs( std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d]) )
	      maxOffset = std::abs( std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d]);
	  }
    }
  }


  return maxOffset;
}


double particles::pit::myfunctions::RepresentationChange::computeMaxError( const particles::pit::Cell& fineGridCell ) {

  const int cellIndex = fineGridCell.getCellIndex();
  const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();
  const ParticleHeap::HeapEntries& currentParticles = ParticleHeap::getInstance().getData(cellIndex);
  const ParticleCompressedHeap::HeapEntries& compressedParticles = ParticleCompressedHeap::getInstance().getData(cellIndex);

  double real_error;

  double maxErrorOffset = 0;
  tarch::la::Vector<DIMENSIONS, double> meanVelocity = fineGridCell.getMeanVelocity();

  if ( NumberOfParticles > 0 ) {

    for (int i=0; i<NumberOfParticles; i++) {
	  for(int d=0; d < DIMENSIONS; d++) {
	    real_error = MUL_FACTOR*(std::abs(currentParticles.at(i)._persistentRecords._v[d]) - meanVelocity[d])
                       - compressedParticles.at(i).getV()[d];
	    if( maxErrorOffset < std::abs(real_error) / MUL_FACTOR)
	      maxErrorOffset = std::abs(real_error) / MUL_FACTOR;
	  }
    }

  }


  return maxErrorOffset;
}


void particles::pit::myfunctions::RepresentationChange::writeInCompressedHeap(
  const ParticleHeap::HeapEntries&                        currentParticles,
  const int                                               cellIndex,
  const tarch::la::Vector<DIMENSIONS, double>&            meanVelocity,
  const tarch::la::Vector<DIMENSIONS, double>&            meanCoordinate
) {
  const int NumberOfParticles = currentParticles.size();

  // Clear all data from Compressed heap not to manage lifting and dropping of particles
  ParticleCompressedHeap::getInstance().getData(cellIndex).clear();

  // absVlosity is used to store asolute values of currentParicle velocity
  tarch::la::Vector<DIMENSIONS, double> absOffset(0);

  for (int i = 0; i< NumberOfParticles; i++) {
    particles::pit::records::ParticleCompressedPacked newParticleCompressed;
    newParticleCompressed.setX(  currentParticles[i]._persistentRecords._x - meanCoordinate );

    for(int d = 0; d<DIMENSIONS; d++) {
      absOffset[d] = MUL_FACTOR * (std::abs( currentParticles[i]._persistentRecords._v[d] ) - meanVelocity[d]);
    }
    newParticleCompressed.setV( absOffset );
    ParticleCompressedHeap::getInstance().getData(cellIndex).push_back(newParticleCompressed);
  }

}


void particles::pit::myfunctions::RepresentationChange::beginIteration() {
  particles::pit::myfunctions::CoordinatesRepresentationChange::beginIteration();

  tarch::la::Vector<N_INTERVALS_HISTOGRAM, int> zeroVector_N_INTERVALS_HISTOGRAM(0);
  _histogramData = zeroVector_N_INTERVALS_HISTOGRAM;

  _global_max_error = 0;
  _globalMaxOffset = 0;
  _globalMaxRelativeError = 0;
  _globalMaxL2ErrorNorm = 0;
  tarch::la::Vector<DIMENSIONS, double> zeroVector(0);
  _globalL2ErrorNorm = zeroVector;
  _globalL2OffsetNorm = zeroVector;
  _globalNormAdditions = 0;

  _maxRelativeErrorOut.str("");
  _maxRelativeErrorOut.clear();
  _maxErrorOut.str("");
  _maxErrorOut.clear();
  _maxOffsetOut.str("");
  _maxOffsetOut.clear();
  _RMSDOut.str("");
  _RMSDOut.clear();
  _L2ErrorNormOut.str("");
  _L2ErrorNormOut.clear();
  _L2NormOut.str("");
  _L2NormOut.clear();
  _meanVelocityOut.str("");
  _meanVelocityOut.clear();
}


void particles::pit::myfunctions::RepresentationChange::endIteration() {
  particles::pit::myfunctions::CoordinatesRepresentationChange::endIteration();

  if ( _globalNormAdditions > 0 ) {
    for(int d = 0; d<DIMENSIONS; d++) {
      _globalL2ErrorNorm[d] /= _globalNormAdditions;
      _globalL2OffsetNorm[d] /= _globalNormAdditions;
    }
  }

  writeAllInFile();

  ++_iteration;

}


void particles::pit::myfunctions::RepresentationChange::writeAllInFile() {
  // Write maxRelativeError
  //writeNorm( "maxRelativeError", _maxRelativeErrorOut );

  // Write maxError
  //writeNorm( "maxError", _maxErrorOut );

  // Write maxOffset
  //writeNorm( "maxOffset", _maxOffsetOut );

  // Write RMSD
  //writeNorm( "RMSDOut", _RMSDOut );

  // Write l2ErrorNorm
  //writeNorm( "L2ErrorNorm", _L2ErrorNormOut );

  // Write l2Norm
  //writeNorm( "L2Norm", _L2NormOut );

  // Write meanVelocity
  //writeNorm( "meanVelocity", _meanVelocityOut );

  static bool writeFirstTime = 1;
  // Write Histogram data
  //writeHistogramData( "histogram", writeFirstTime);

  // Write globalL2ErrorNorm
  writeGlobalNorm( "globalL2ErrorNorm.dat", _globalL2ErrorNorm, writeFirstTime );

  // Write _globalL2OffsetNorm
  //writeGlobalNorm( "globalL2OffsetNorm.dat", _globalL2OffsetNorm, writeFirstTime );

  // Write _globalMaxL2ErrorNorm
  writeGlobalNorm( "globalMaxL2ErrorNorm.dat", _globalMaxL2ErrorNorm, writeFirstTime );

  // Write _globalMaxRelativeError
  //writeGlobalNorm( "globalMaxRelativeError.dat", _globalMaxRelativeError, writeFirstTime );

  // Write _globalMaxOffset
  //writeGlobalNorm( "globalMaxOffset.dat", _globalMaxOffset, writeFirstTime );

  // Write global max error
  writeGlobalNorm( "global_max_error.dat", _global_max_error, writeFirstTime );

  writeFirstTime = 0;
}


void particles::pit::myfunctions::RepresentationChange::writeGlobalNorm( const std::string& filename, const tarch::la::Vector<DIMENSIONS,double>& Norm, const bool& writeFirstTime ) {
  std::ofstream out;
  if( writeFirstTime ) {
    out.open( filename.c_str() );
  } else {
    out.close();
    out.open( filename.c_str(), std::ofstream::app );
  }
  if ( (!out.fail()) && out.is_open() && !writeFirstTime ) {
    for(int d = 0; d<DIMENSIONS; d++) {
      out << Norm[d] << " ";
    }
    out << std::endl;
  }
}


void particles::pit::myfunctions::RepresentationChange::writeNorm( const std::string& normName, const std::ostringstream& normData ) {
  std::ostringstream normFileName;
  normFileName << normName
   		       << "-" << _iteration
    	       << ".dat";
  std::ofstream out;
  out.open( normFileName.str().c_str() );
  if ( (!out.fail()) && out.is_open() ) {
    out << normData.str() << std::endl;
  }
}


void particles::pit::myfunctions::RepresentationChange::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
  particles::pit::myfunctions::CoordinatesRepresentationChange::ascend( fineGridCells, fineGridVertices, fineGridVerticesEnumerator, coarseGridVertices, coarseGridVerticesEnumerator, coarseGridCell );

  dfor3(k)
    particles::pit::Cell fineGridCell = fineGridCells[ fineGridVerticesEnumerator.cell(k) ];
    const tarch::la::Vector<DIMENSIONS,double> cellOffset     = fineGridVerticesEnumerator.getVertexPosition(k);
    const tarch::la::Vector<DIMENSIONS,double> meanVelocity = fineGridCell.getMeanVelocity();
    bool isLeaf = fineGridCell.isLeaf();
    const int cellIndex = fineGridCell.getCellIndex();
    const int NumberOfParticles = ParticleHeap::getInstance().getData(cellIndex).size();

    if( isLeaf && NumberOfParticles>1 ) {
      // Compute Max-Norm
      double maxRelativeError = computeMaxRelativeError( fineGridCell );
      // Save maximal maxRelativeError in _globalMaxRelativeError
      if (_globalMaxRelativeError < maxRelativeError) {
        _globalMaxRelativeError = maxRelativeError;
      }
      double maxError = computeMaxError( fineGridCell );
      if(_global_max_error < maxError) {
          _global_max_error = maxError;
      }
      double maxOffset = computeMaxOffset( fineGridCell );
      if(_globalMaxOffset < maxOffset) {
        _globalMaxOffset = maxOffset;
      }
      // Compute RMSD
      tarch::la::Vector<DIMENSIONS,double> rmsd = computeRMSD( fineGridCell );
      // Computer L2-Norm
      tarch::la::Vector<DIMENSIONS,double> l2ErrorNorm = computeL2ErrorNorm( fineGridCell );
      tarch::la::Vector<DIMENSIONS,double> l2Norm = computeL2Norm( fineGridCell );
      std::cout << "ascend() l2ErrorNorm: " << l2ErrorNorm << std::endl;

      // Histogram process
      processHistogram( l2ErrorNorm );

      // Save maximal l2ErrorNorm in _globalMaxL2ErrorNorm
      for(int d = 0; d<DIMENSIONS; d++) {
        if(_globalMaxL2ErrorNorm < l2ErrorNorm[d]) {
          _globalMaxL2ErrorNorm = l2ErrorNorm[d];
        }
      }
      // Add l2ErrorNorm to _globalL2ErrorNorm
      _globalL2ErrorNorm += l2ErrorNorm;
      // Add l2Norm to _globalL2OffsetNorm
      _globalL2OffsetNorm += l2Norm;
      // Don't forget to increment _globalNormAdditions to divide _globalL2Norm by it
      // at the end of iteration before writing it in the file!
      ++_globalNormAdditions;


      // Output for checking
      printParticlesInfo( fineGridCell, "l2ErrorNorm", l2ErrorNorm );

      _maxRelativeErrorOut << maxRelativeError << " ";
      _maxErrorOut << maxError << " ";
      _maxOffsetOut << maxOffset << " ";
      for(int d=0; d<DIMENSIONS; d++) {
        _RMSDOut << rmsd[d] << " ";
        _L2ErrorNormOut << l2ErrorNorm[d] << " ";
        _L2NormOut << l2Norm[d] << " ";
        _meanVelocityOut << meanVelocity[d] << " ";
      }
      for(int d=0; d<DIMENSIONS; d++) {
        _maxRelativeErrorOut << cellOffset[d] << " ";
    	_maxErrorOut << cellOffset[d] << " ";
        _maxOffsetOut << cellOffset[d] << " ";
        _RMSDOut << cellOffset[d] << " ";
        _L2ErrorNormOut << cellOffset[d] << " ";
        _L2NormOut << cellOffset[d] << " ";
        _meanVelocityOut << cellOffset[d] << " ";
      }
      _maxRelativeErrorOut << std::endl;
      _maxErrorOut << std::endl;
      _maxOffsetOut << std::endl;
      _RMSDOut << std::endl;
      _L2ErrorNormOut << std::endl;
      _L2NormOut << std::endl;
      _meanVelocityOut << std::endl;
    }
  enddforx
}
