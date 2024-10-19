cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME "adapter")

add_library(${MODULE_NAME} STATIC terminal_adapter.cpp)

target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS ${MODULE_NAME} ARCHIVE DESTINATION lib COMPONENT libraries)
install(FILES abstract_adapter.hpp terminal_adapter.hpp
		DESTINATION include/"${MODULE_NAME}")
