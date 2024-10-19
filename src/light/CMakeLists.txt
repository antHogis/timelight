cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME "light")

add_library(${MODULE_NAME} STATIC light_element.cpp light_matrix.cpp)

target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS ${MODULE_NAME} ARCHIVE DESTINATION lib COMPONENT libraries)
install(FILES light_element.hpp light_matrix.cpp
		DESTINATION include/"${MODULE_NAME}")

