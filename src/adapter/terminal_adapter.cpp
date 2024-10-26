#include "terminal_adapter.hpp"
#include "../light/light_matrix.hpp"
#include "abstract_adapter.hpp"
#include <iostream>
#include <sstream>

namespace Adapter
{
	TerminalAdapter::TerminalAdapter() : AbstractAdapter(), has_printed_(false)
	{
	}

	void TerminalAdapter::display_matrix(Light::LightMatrix& matrix)
	{
		auto& matrix_impl = matrix.get_impl();

		if (has_printed_)
		{
			// Move the cursor up
			std::cout << "\033[" << matrix_impl.size() << "A";
		}

		for (std::vector<Light::LightElement>& row : matrix_impl)
		{
			if (has_printed_)
			{
				// Clear the line
				std::cout << "\033[2K";
			}

			std::ostringstream row_stream;
			for (auto& val : row)
			{
				add_colour_block(row_stream, val);
			}
			std::cout << row_stream.str() << std::endl;
			std::cout.flush();
		}

		has_printed_ = true;
	}

	void TerminalAdapter::add_colour_block(std::ostringstream& row_stream,
	                                       Light::LightElement& e)
	{
		std::string rgb = (std::ostringstream()
		                   << (int)e.red << ';' << (int)e.green << ';' << (int)e.blue)
							  .str();

		// Set text color (RGB)
		row_stream << "\033[38;2;" << rgb << "m\033[48;2;" << rgb << "m  \033[0m";
	}

} // namespace Adapter
