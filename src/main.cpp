#include "adapter/terminal_adapter.hpp"
#include "app/config.hpp"
#include "light/light_matrix.hpp"
#include <chrono>
#include <iostream>
#include <thread>

// Should already be defined in CMake
#ifndef PROJECT_VERSION
#define PROJECT_VERSION "N/A"
#endif

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	// TODO only show with -v flag
	std::cout << "TimeLight version " << PROJECT_VERSION << std::endl;

	const App::Config config;
	std::cout
		<< "Config start time "
		<< (int)config.cycle().cycle_start_times.find(App::CYCLE_MORNING)->second.at(0)
		<< std::endl;

	Light::LightMatrix matrix(config.light_matrix().rows, config.light_matrix().cols);
	Adapter::TerminalAdapter adapter;

	while (true)
	{
		matrix.randomize();
		adapter.display_matrix(matrix);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return 0;
}
