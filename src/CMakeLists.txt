# Probably doesn't need to be this recent but it's what I use
cmake_minimum_required(VERSION 3.10)

project(TimeLight LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add warnings
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror")
elseif (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror")
else()
	message(WARNING "CMake has not been configured for compiler " ${CMAKE_CXX_COMPILER_ID})
endif()

if (CMAKE_BUILD_TYPE MATCHES debug)
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG")
  message(STATUS "Using compiler debug flags" ${CMAKE_CXX_FLAGS_DEBUG})
elseif (CMAKE_BUILD_TYPE MATCHES release)
  set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG")
  message(STATUS "Using cmake release flags " ${CMAKE_CXX_FLAGS_DEBUG})
else()
  message (FATAL_ERROR "specify -DCMAKE_BUILD_TYPE=[debug|release]")
endif()


# add light dir
add_subdirectory (light)

# add adapter dir
add_subdirectory (adapter)

# define PROJECT_VERSION in compilation
add_compile_definitions(PROJECT_VERSION="${CMAKE_PROJECT_VERSION}")

add_executable(TimeLight main.cpp)
target_link_libraries(TimeLight light adapter)

