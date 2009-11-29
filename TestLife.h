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

    void test_in () {
		istringstream in("2\n3\n.*.\n0+-\n");
		Life<Cell> l;
		in >> l;


		CPPUNIT_ASSERT(!l._grid[0][0].isAlive());
		CPPUNIT_ASSERT(l._grid[0][1].isAlive());
		CPPUNIT_ASSERT(l._grid[1][0].isAlive());
		CPPUNIT_ASSERT(l._grid[1][1].isAlive());
		CPPUNIT_ASSERT(!l._grid[1][2].isAlive());
	}

	void test_conway_1 () {
		istringstream in("3\n3\n...\n.*.\n...\n");
		Life<ConwayCell> l;
		in >> l;

		l.move();


		CPPUNIT_ASSERT(!l._grid[1][1].isAlive());
	}

	void test_conway_2 () {
		istringstream in("2\n3\n***\n...\n");
		Life<ConwayCell> l;
		in >> l;

		l.move();

		ostringstream out;
		out << l;

		CPPUNIT_ASSERT(out.str() == "Generation = 1, Population = 2.\n.*.\n.*.\n\n");
	}

	void test_fredkin_1 () {
		istringstream in("1\n1\n3\n");
		Life<FredkinCell> l;
		in >> l;

		l.move();

		CPPUNIT_ASSERT(l._grid[0][0].age == -1);
	}

	void test_fredkin_2 () {
		istringstream in("1\n2\n33\n");
		Life<FredkinCell> l;
		in >> l;

		l.move();

		CPPUNIT_ASSERT(l._grid[0][0].age == 4);
		CPPUNIT_ASSERT(l._grid[0][1].age == 4);
	}

	void test_fredkin_3 () {
		istringstream in("1\n2\n+9\n");
		Life<FredkinCell> l;
		in >> l;

		l.move();

		ostringstream out;
		out << l;

		CPPUNIT_ASSERT(l._grid[0][0].age == 11);
		CPPUNIT_ASSERT(l._grid[0][1].age == 10);
		CPPUNIT_ASSERT(out.str() == "Generation = 1, Population = 2.\n++\n\n");
	}

	void test_fredkin_4 () {
		istringstream in("1\n2\n3-\n");
		Life<FredkinCell> l;
		in >> l;

		l.move();

		ostringstream out;
		out << l;

		CPPUNIT_ASSERT(l._grid[0][0].age == -1);
		CPPUNIT_ASSERT(l._grid[0][1].age == 0);
		CPPUNIT_ASSERT(out.str() == "Generation = 1, Population = 1.\n-0\n\n");

		l.move();
		CPPUNIT_ASSERT(l._grid[0][0].age == 0);
		CPPUNIT_ASSERT(l._grid[0][1].age == -1);
	}

	void test_cell_1 () {
		istringstream in("1\n2\n01\n");
		Life<Cell> l;

		in >> l;

		l.move();

		ostringstream out;
		out << l;

		CPPUNIT_ASSERT(out.str() == "Generation = 1, Population = 2.\n1*\n\n");
	}

	void test_cell_2 () {
		istringstream in("2\n2\n00\n0*");
		Life<Cell> l;

		in >> l;

		l.move();

		ostringstream out;
		out << l;

		CPPUNIT_ASSERT(out.str() == "Generation = 1, Population = 1.\n--\n-*\n\n");
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(test_in);
	CPPUNIT_TEST(test_conway_1);
	CPPUNIT_TEST(test_conway_2);
	CPPUNIT_TEST(test_fredkin_1);
	CPPUNIT_TEST(test_fredkin_2);
	CPPUNIT_TEST(test_fredkin_3);
	CPPUNIT_TEST(test_fredkin_4);
	CPPUNIT_TEST(test_cell_1);
	CPPUNIT_TEST(test_cell_2);
    CPPUNIT_TEST_SUITE_END();};

} // cs

#endif // TestLife_h
