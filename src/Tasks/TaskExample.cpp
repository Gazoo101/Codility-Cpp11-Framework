// std.dev
#include <vector>
#include <iostream>

// 3rd Party

// 1st Party
#include "TestHelper.h"

#include "TaskExample.h"

namespace {

	int ex1( int N )
	{
		return 123;
	}

	std::vector<int> ex2( std::vector<int>& A, int K )
	{
		return std::vector<int> { 1, 2, 3, 4, 5 };
	}

	int ex3( std::vector<int>& A )
	{
		return 123;
	}

	int ex4( int X, int Y, int D )
	{
		return 123;
	}

	std::vector<int> ex5( std::string const& S, std::vector<int>& P, std::vector<int>& Q )
	{
		return std::vector<int> { 1, 2, 3, 4, 5 };
	}

	std::vector<int> ex6( int N, std::vector<int>& P, std::vector<int>& Q )
	{
		return std::vector<int> { 1, 2, 3, 4, 5 };
	}

	int ex7( std::string const& S )
	{
		return 123;
	}
}

void TaskExample::RunTest()
{
	typedef std::vector<int> VectorInt;

	mTestHelper.execute( ex1, 1 );
	mTestHelper.execute( ex2, VectorInt{ 1, 2, 3, 4, 5 }, 1 );
	mTestHelper.execute( ex2, VectorInt{ 1, 2, 3, 4, 5 }, 1 );
	mTestHelper.execute( ex4, 1, 2, 3 );
	mTestHelper.execute( ex5, "Foobar", VectorInt{ 1, 2, 3, 4, 5 }, VectorInt{ 6, 7, 8, 9, 0 } );
	mTestHelper.execute( ex6, 101, VectorInt{ 1, 2, 3, 4, 5 }, VectorInt{ 6, 7, 8, 9, 0 } );
	mTestHelper.execute( ex7, "Foobar" );

	// Instantiate a helper with a different output function (to std::cout)
	auto helperWithStdout = std::make_unique<TestHelper>( []( std::string const& str ) {
		std::cout << str << std::endl;
	} );

	helperWithStdout->execute( ex1, 1 );
	helperWithStdout->execute( ex2, VectorInt{ 1, 2, 3, 4, 5 }, 1 );
}