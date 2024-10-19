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
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
  # todo
endif()

# add light dir
add_subdirectory (light)

# add adapter dir
add_subdirectory (adapter)

# define PROJECT_VERSION in compilation
add_compile_definitions(PROJECT_VERSION="${CMAKE_PROJECT_VERSION}")

add_executable(TimeLight main.cpp)
target_link_libraries(TimeLight light adapter)

