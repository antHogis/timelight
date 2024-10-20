#ifndef TIMELIGHT_TERMINAL_ADAPTER_HPP
#define TIMELIGHT_TERMINAL_ADAPTER_HPP

#include "abstract_adapter.hpp"

namespace Adapter
{
	class TerminalAdapter : public AbstractAdapter
	{
	public:
		TerminalAdapter();
		void displayMatrix(Light::LightMatrix& matrix) override;

	private:
		void addColourBlock(std::ostringstream& row_stream, Light::LightElement& element);

		bool has_printed_;
	};

} // namespace Adapter

#endif
