// ------------------------
// projects/life/TestLife.h
// Copyright (C) 2009
// Glenn P. Downing
// ------------------------

#ifndef TestLife_h
#define TestLife_h

// --------
// includes
// --------

#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END

// ----------
// namespaces
// ----------

namespace cs {

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {
    // -----
    // tests
    // -----

    // <your tests>

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST_SUITE_END();};

} // cs

#endif // TestLife_h
