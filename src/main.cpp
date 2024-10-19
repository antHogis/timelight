// A simple program that computes the square root of a number
#include "adapter/terminal_adapter.hpp"
#include "light/light_matrix.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

// Should already be defined in CMake
#ifndef PROJECT_VERSION
#define PROJECT_VERSION "N/A"
#endif

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	// TODO only show with -v flag
	std::cout << "TimeLight version " << PROJECT_VERSION << std::endl;

	Light::LightMatrix matrix(10, 100);
	matrix.randomize();

	Adapter::TerminalAdapter adapter;
	adapter.displayMatrix(matrix);

	return 0;
}
