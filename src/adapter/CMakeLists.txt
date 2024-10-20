cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME "adapter")
set(MODULE_SOURCES terminal_adapter.cpp)
set(MODULE_HEADERS abstract_adapter.hpp terminal_adapter.hpp)

add_library(${MODULE_NAME} STATIC ${MODULE_SOURCES})

target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS ${MODULE_NAME} ARCHIVE DESTINATION lib COMPONENT libraries)
install(FILES ${MODULE_HEADERS} 
		DESTINATION include/"${MODULE_NAME}")
