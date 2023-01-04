# cmake_path command requires CMake 3.2 or newer
cmake_minimum_required( VERSION 3.20 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( CodilityFramework )

cmake_path(SET PATH_APP "${CMAKE_CURRENT_SOURCE_DIR}")

set(FILES_CMAKE
	"${PATH_APP}/src/TestHelper.cpp"
	"${PATH_APP}/src/TestHelper.h"
	"${PATH_APP}/src/main.cpp"
	"${PATH_APP}/README.md"
)


add_executable(CodilityFramework ${FILES_CMAKE})

set_property(TARGET CodilityFramework PROPERTY CXX_STANDARD 17)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CodilityFramework)