#ifndef TIMELIGHT_LIGHT_ELEMENT_HPP
#define TIMELIGHT_LIGHT_ELEMENT_HPP

#include <random>

namespace Light
{
	typedef unsigned char LightComponent;
	typedef std::uniform_int_distribution<std::mt19937::result_type> ColourDistribution;

	struct LightElement
	{
		LightElement();
		LightElement(LightComponent red, LightComponent green, LightComponent blue);

		static LightElement random();

		static LightElement random(ColourDistribution red_dist,
		                           ColourDistribution green_dist,
		                           ColourDistribution blue_dist);

		LightComponent red;
		LightComponent green;
		LightComponent blue;
	};

	std::ostream& operator<<(std::ostream& strm, const LightElement& a);

} // namespace Light
#endif
