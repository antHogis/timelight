// A simple program that computes the square root of a number
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

// Should already be defined in CMake
#ifndef PROJECT_VERSION
#define PROJECT_VERSION "N/A"
#endif

int main(int argc, char* argv[])
{

	if (argc < 2)
	{
		std::cout << "TimeLight version " << PROJECT_VERSION << std::endl;
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}

	const double input_val = std::stod(argv[1]);

	// calculate square root
	const double output_val = std::sqrt(input_val);
	std::cout << "The square root of " << input_val << " is " << output_val << std::endl;
	return 0;
}
