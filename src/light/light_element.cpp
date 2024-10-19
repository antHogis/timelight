#include "light_element.hpp"
#include <cstdio>
#include <random>
#include <stdexcept>

namespace Light
{

	LightElement::LightElement() : LightElement::LightElement(0, 0, 0, 0)
	{
	}

	LightElement::LightElement(LightComponent red,
	                           LightComponent green,
	                           LightComponent blue,
	                           LightComponent luminance)
		: red(red), green(green), blue(blue), luminance(luminance)
	{
	}

	LightElement LightElement::random()
	{
		ColourDistribution dist(0, 255);

		return random(dist, dist, dist, dist);
	}

	LightElement LightElement::random(ColourDistribution red_dist,
	                                  ColourDistribution green_dist,
	                                  ColourDistribution blue_dist)
	{
		return random(red_dist, green_dist, blue_dist, ColourDistribution(0, 255));
	}

	LightElement LightElement::random(ColourDistribution red_dist,
	                                  ColourDistribution green_dist,
	                                  ColourDistribution blue_dist,
	                                  ColourDistribution luminance_dist)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		return LightElement(red_dist(mt),
		                    green_dist(mt),
		                    blue_dist(mt),
		                    luminance_dist(mt));
	}

	std::ostream& operator<<(std::ostream& os, const LightElement& a)
	{
		char buffer[18];
		int result = std::snprintf(buffer,
		                           18,
		                           "[%3u,%3u,%3u,%3u]",
		                           a.red,
		                           a.green,
		                           a.blue,
		                           a.luminance);
		if (!result)
		{
			throw std::runtime_error("light_value_format");
		}
		return os << buffer;
	}

} // namespace Light
