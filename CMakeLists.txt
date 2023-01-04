# cmake_path command requires CMake 3.2 or newer
cmake_minimum_required( VERSION 3.20 FATAL_ERROR )
set( CMAKE_VERBOSE_MAKEFILE ON )

project( CodilityFramework )

cmake_path(SET PATH_APP "${CMAKE_CURRENT_SOURCE_DIR}")
cmake_path(SET PATH_APP_SRC "${PATH_APP}/src")

set(FILES
	"${PATH_APP_SRC}/Tasks/TaskBase.cpp"
	"${PATH_APP_SRC}/Tasks/TaskBase.h"
	"${PATH_APP_SRC}/Tasks/TaskExample.cpp"
	"${PATH_APP_SRC}/Tasks/TaskExample.h"
	"${PATH_APP_SRC}/Tasks/TaskTemplate.cpp"
	"${PATH_APP_SRC}/Tasks/TaskTemplate.h"
	"${PATH_APP_SRC}/TestHelper.cpp"
	"${PATH_APP_SRC}/TestHelper.h"
	"${PATH_APP_SRC}/main.cpp"
	"${PATH_APP}/CMakeLists.txt"
	"${PATH_APP}/README.md"
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "Source Files/" FILES ${FILES})

add_executable(CodilityFramework ${FILES})

include_directories(${PATH_APP_SRC})

set_property(TARGET CodilityFramework PROPERTY CXX_STANDARD 17)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CodilityFramework)