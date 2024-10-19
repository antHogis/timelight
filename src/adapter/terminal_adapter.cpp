#include "terminal_adapter.hpp"
#include "../light/light_matrix.hpp"
#include "abstract_adapter.hpp"
#include <sstream>

namespace Adapter
{
	TerminalAdapter::TerminalAdapter() : AbstractAdapter()
	{
	}

	void TerminalAdapter::displayMatrix(Light::LightMatrix& matrix)
	{
		for (auto row : matrix.getImpl())
		{
			for (auto val : row)
			{
				addColourBlock(val);
			}
			std::cout << std::endl;
		}
	}

	void TerminalAdapter::addColourBlock(Light::LightElement& e)
	{
		std::string rgb = (std::ostringstream()
		                   << (int)e.red << ';' << (int)e.green << ';' << (int)e.blue)
							  .str();

		// Set text color (RGB)
		std::cout << "\033[38;2;" << rgb << "m\033[48;2;" << rgb << "m  \033[0m";
	}

} // namespace Adapter
