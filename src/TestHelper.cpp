#include "TestHelper.h"
#include <Windows.h>

TestHelper::TestHelper()
{
	// Std. Print to Visual Studio's Output windows
	mPrintFunc = []( std::string const& str )
	{
		std::ostringstream oss;
		oss << str.c_str() << "\n";
		OutputDebugString( oss.str().c_str() );
	};

}

TestHelper::TestHelper( std::function<void( std::string const& str )> const& printFunc )
	: mPrintFunc( printFunc )
{

}