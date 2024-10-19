#ifndef ABSTRACT_ADAPTER_HPP
#define ABSTRACT_ADAPTER_HPP

#include "../light/light_matrix.hpp"

namespace Adapter
{
	class AbstractAdapter
	{
	public:
		AbstractAdapter() {};

		virtual void displayMatrix(Light::LightMatrix& matrix) = 0;
	};

} // namespace Adapter

#endif
