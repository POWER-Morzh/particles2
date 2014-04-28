// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIDT_TESTS_TEST_CASE_H_
#define _PARTICLES_PIDT_TESTS_TEST_CASE_H_
 


#include "tarch/tests/TestCase.h"


namespace particles { 
  namespace pidt {
    namespace tests {
      class TestCase;
    } 
}
}
 

/**
 * This is just a default test case that demonstrated how to write unit tests 
 * in Peano. Feel free to rename, remove, or duplicate it. 
 */ 
class particles::pidt::tests::TestCase: public tarch::tests::TestCase {
  private:
    /**
     * These operation usually implement the real tests.
     */
    void test1();

    /**
     * These operation usually implement the real tests.
     */
    void test2();

    /**
     * These operation usually implement the real tests.
     */
    void test3();
  public: 
    TestCase(); 
    virtual ~TestCase();
     
    virtual void run();
};


#endif
