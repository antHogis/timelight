#ifndef TIMELIGHT_ABSTRACT_ADAPTER_HPP
#define TIMELIGHT_ABSTRACT_ADAPTER_HPP

#include "../light/light_matrix.hpp"

namespace Adapter
{
	class AbstractAdapter
	{
	public:
		AbstractAdapter() {};

		virtual void display_matrix(Light::LightMatrix& matrix) = 0;
	};

} // namespace Adapter

#endif
