#include "TestHelper.h"
#include <Windows.h>

TestHelper::TestHelper()
{
	// Std. Print to the output window!
	mPrintFunc = []( std::string const& str )
	{
		std::ostringstream oss;
		oss << str.c_str() << "\n";
		OutputDebugString( oss.str().c_str() );
	};

}

TestHelper::TestHelper( std::function<void( std::string const& str )>& printFunc ) :
	mPrintFunc( printFunc )
{

}

TestHelper::~TestHelper()
{

}