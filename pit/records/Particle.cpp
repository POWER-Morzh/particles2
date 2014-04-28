#include "particles/pit/records/Particle.h"

particles::pit::records::Particle::PersistentRecords::PersistentRecords() {
   
}


particles::pit::records::Particle::PersistentRecords::PersistentRecords(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v):
_x(x),
_v(v) {
   
}


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::Particle::PersistentRecords::getX() const  {
   return _x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::Particle::PersistentRecords::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _x = (x);
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::Particle::PersistentRecords::getV() const  {
   return _v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::Particle::PersistentRecords::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _v = (v);
}


particles::pit::records::Particle::Particle() {
   
}


particles::pit::records::Particle::Particle(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._x, persistentRecords._v) {
   
}


particles::pit::records::Particle::Particle(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v):
_persistentRecords(x, v) {
   
}


particles::pit::records::Particle::~Particle() { }


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::Particle::getX() const  {
   return _persistentRecords._x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::Particle::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _persistentRecords._x = (x);
}



 double particles::pit::records::Particle::getX(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._x[elementIndex];
   
}



 void particles::pit::records::Particle::setX(int elementIndex, const double& x)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._x[elementIndex]= x;
   
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::Particle::getV() const  {
   return _persistentRecords._v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::Particle::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _persistentRecords._v = (v);
}



 double particles::pit::records::Particle::getV(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._v[elementIndex];
   
}



 void particles::pit::records::Particle::setV(int elementIndex, const double& v)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._v[elementIndex]= v;
   
}




std::string particles::pit::records::Particle::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pit::records::Particle::toString (std::ostream& out) const {
   out << "("; 
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "v:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getV(i) << ",";
   }
   out << getV(DIMENSIONS-1) << "]";
   out <<  ")";
}


particles::pit::records::Particle::PersistentRecords particles::pit::records::Particle::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pit::records::ParticlePacked particles::pit::records::Particle::convert() const{
   return ParticlePacked(
      getX(),
      getV()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pit::records::Particle::_log( "particles::pit::records::Particle" );
   
   MPI_Datatype particles::pit::records::Particle::Datatype = 0;
   MPI_Datatype particles::pit::records::Particle::FullDatatype = 0;
   
   
   void particles::pit::records::Particle::initDatatype() {
      {
         Particle dummyParticle[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticle[1]._persistentRecords._x[0])), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Particle::Datatype );
         MPI_Type_commit( &Particle::Datatype );
         
      }
      {
         Particle dummyParticle[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticle[1]._persistentRecords._x[0])), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Particle::FullDatatype );
         MPI_Type_commit( &Particle::FullDatatype );
         
      }
      
   }
   
   
   void particles::pit::records::Particle::shutdownDatatype() {
      MPI_Type_free( &Particle::Datatype );
      MPI_Type_free( &Particle::FullDatatype );
      
   }
   
   void particles::pit::records::Particle::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pit::records::Particle "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         
      }
      else {
      
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pit::records::Particle "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for particles::pit::records::Particle "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "particles::pit::records::Particle",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pit::records::Particle",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
   }
   
   
   
   void particles::pit::records::Particle::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         MPI_Status  status;
         const int   result = MPI_Recv(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pit::records::Particle from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
      }
      else {
      
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pit::records::Particle from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for particles::pit::records::Particle failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "particles::pit::records::Particle",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pit::records::Particle",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
   }
   
   
   
   bool particles::pit::records::Particle::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
      MPI_Status status;
      int  flag        = 0;
      MPI_Iprobe(
         MPI_ANY_SOURCE, tag,
         tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
      );
      if (flag) {
         int  messageCounter;
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            MPI_Get_count(&status, Datatype, &messageCounter);
         }
         else {
            MPI_Get_count(&status, FullDatatype, &messageCounter);
         }
         return messageCounter > 0;
      }
      else return false;
      
   }
   
   
#endif


particles::pit::records::ParticlePacked::PersistentRecords::PersistentRecords() {
   
}


particles::pit::records::ParticlePacked::PersistentRecords::PersistentRecords(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v):
_x(x),
_v(v) {
   
}


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::ParticlePacked::PersistentRecords::getX() const  {
   return _x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::ParticlePacked::PersistentRecords::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _x = (x);
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::ParticlePacked::PersistentRecords::getV() const  {
   return _v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::ParticlePacked::PersistentRecords::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _v = (v);
}


particles::pit::records::ParticlePacked::ParticlePacked() {
   
}


particles::pit::records::ParticlePacked::ParticlePacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._x, persistentRecords._v) {
   
}


particles::pit::records::ParticlePacked::ParticlePacked(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v):
_persistentRecords(x, v) {
   
}


particles::pit::records::ParticlePacked::~ParticlePacked() { }


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::ParticlePacked::getX() const  {
   return _persistentRecords._x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::ParticlePacked::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _persistentRecords._x = (x);
}



 double particles::pit::records::ParticlePacked::getX(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._x[elementIndex];
   
}



 void particles::pit::records::ParticlePacked::setX(int elementIndex, const double& x)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._x[elementIndex]= x;
   
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pit::records::ParticlePacked::getV() const  {
   return _persistentRecords._v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pit::records::ParticlePacked::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _persistentRecords._v = (v);
}



 double particles::pit::records::ParticlePacked::getV(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._v[elementIndex];
   
}



 void particles::pit::records::ParticlePacked::setV(int elementIndex, const double& v)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._v[elementIndex]= v;
   
}




std::string particles::pit::records::ParticlePacked::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pit::records::ParticlePacked::toString (std::ostream& out) const {
   out << "("; 
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "v:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getV(i) << ",";
   }
   out << getV(DIMENSIONS-1) << "]";
   out <<  ")";
}


particles::pit::records::ParticlePacked::PersistentRecords particles::pit::records::ParticlePacked::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pit::records::Particle particles::pit::records::ParticlePacked::convert() const{
   return Particle(
      getX(),
      getV()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pit::records::ParticlePacked::_log( "particles::pit::records::ParticlePacked" );
   
   MPI_Datatype particles::pit::records::ParticlePacked::Datatype = 0;
   MPI_Datatype particles::pit::records::ParticlePacked::FullDatatype = 0;
   
   
   void particles::pit::records::ParticlePacked::initDatatype() {
      {
         ParticlePacked dummyParticlePacked[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticlePacked[1]._persistentRecords._x[0])), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &ParticlePacked::Datatype );
         MPI_Type_commit( &ParticlePacked::Datatype );
         
      }
      {
         ParticlePacked dummyParticlePacked[2];
         
         const int Attributes = 3;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticlePacked[1]._persistentRecords._x[0])), 		&disp[2] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &ParticlePacked::FullDatatype );
         MPI_Type_commit( &ParticlePacked::FullDatatype );
         
      }
      
   }
   
   
   void particles::pit::records::ParticlePacked::shutdownDatatype() {
      MPI_Type_free( &ParticlePacked::Datatype );
      MPI_Type_free( &ParticlePacked::FullDatatype );
      
   }
   
   void particles::pit::records::ParticlePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pit::records::ParticlePacked "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         
      }
      else {
      
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pit::records::ParticlePacked "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for particles::pit::records::ParticlePacked "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "particles::pit::records::ParticlePacked",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pit::records::ParticlePacked",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
   }
   
   
   
   void particles::pit::records::ParticlePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         MPI_Status  status;
         const int   result = MPI_Recv(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pit::records::ParticlePacked from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
      }
      else {
      
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pit::records::ParticlePacked from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for particles::pit::records::ParticlePacked failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "particles::pit::records::ParticlePacked",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pit::records::ParticlePacked",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
   }
   
   
   
   bool particles::pit::records::ParticlePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
      MPI_Status status;
      int  flag        = 0;
      MPI_Iprobe(
         MPI_ANY_SOURCE, tag,
         tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
      );
      if (flag) {
         int  messageCounter;
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            MPI_Get_count(&status, Datatype, &messageCounter);
         }
         else {
            MPI_Get_count(&status, FullDatatype, &messageCounter);
         }
         return messageCounter > 0;
      }
      else return false;
      
   }
   
   
#endif



