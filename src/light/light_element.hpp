#ifndef LIGHT_ELEMENT_HPP
#define LIGHT_ELEMENT_HPP

#include <random>

namespace Light
{
	typedef unsigned char LightComponent;
	typedef std::uniform_int_distribution<std::mt19937::result_type> ColourDistribution;

	struct LightElement
	{
		LightElement();
		LightElement(LightComponent red,
		             LightComponent green,
		             LightComponent blue,
		             LightComponent luminance);

		static LightElement random();

		static LightElement random(ColourDistribution red_dist,
		                           ColourDistribution green_dist,
		                           ColourDistribution blue_dist);

		static LightElement random(ColourDistribution red_dist,
		                           ColourDistribution green_dist,
		                           ColourDistribution blue_dist,
		                           ColourDistribution luminance_dist);

		LightComponent red;
		LightComponent green;
		LightComponent blue;
		LightComponent luminance;
	};

	std::ostream& operator<<(std::ostream& strm, const LightElement& a);

} // namespace Light
#endif
