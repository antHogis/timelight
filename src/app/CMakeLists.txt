
cmake_minimum_required(VERSION 3.10)

set(MODULE_NAME "app")
set(MODULE_SOURCES config.cpp)
set(MODULE_HEADERS config.hpp)

add_library(${MODULE_NAME} STATIC ${MODULE_SOURCES})

target_include_directories(${MODULE_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

install(TARGETS ${MODULE_NAME} ARCHIVE DESTINATION lib COMPONENT libraries)
install(FILES ${MODULE_HEADERS}
		DESTINATION include/"${MODULE_NAME}")
