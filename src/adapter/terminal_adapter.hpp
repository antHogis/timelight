#ifndef TERMINAL_ADAPTER_HPP
#define TERMINAL_ADAPTER_HPP

#include "abstract_adapter.hpp"

namespace Adapter
{
	class TerminalAdapter : public AbstractAdapter
	{
	public:
		TerminalAdapter();
		void displayMatrix(Light::LightMatrix& matrix) override;

	private:
		void addColourBlock(Light::LightElement& element);
	};

} // namespace Adapter

#endif
