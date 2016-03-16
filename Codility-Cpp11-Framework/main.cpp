#include <iostream>

#include <memory>
#include "TestHelper.h"
#include <Windows.h> // remove later

int ex1( int N )
{
	return 123;
}

std::vector<int> ex2( std::vector<int> &A, int K )
{
	return std::vector<int> { 1,2,3,4,5 };
}

int ex3( std::vector<int> &A )
{
	return 123;
}

int ex4( int X, int Y, int D )
{
	return 123;
}

std::vector<int> ex5( std::string const& S, std::vector<int> &P, std::vector<int> &Q )
{
	return std::vector<int> { 1, 2, 3, 4, 5 };
}

std::vector<int> ex6( int N, std::vector<int> &P, std::vector<int> &Q )
{
	return std::vector<int> { 1, 2, 3, 4, 5 };
}

int ex7( std::string const& S )
{
	return 123;
}

int main()
{
	// Init Helper!
	auto helper = std::make_unique<TestHelper>();

	helper->execute( ex1, 1 );
	helper->execute( ex2, std::vector<int> { 1, 2, 3, 4, 5 }, 1 );
	helper->execute( ex3, std::vector<int> { 1, 2, 3, 4, 5 } );
	helper->execute( ex4, 1, 2, 3 );
	helper->execute( ex5, "Foobar", std::vector<int> { 1, 2, 3, 4, 5 }, std::vector<int> { 6, 7, 8, 9, 0 } );
	helper->execute( ex6, 101, std::vector<int> { 1, 2, 3, 4, 5 }, std::vector<int> { 6, 7, 8, 9, 0 } );
	helper->execute( ex7, "Foobar" );

}