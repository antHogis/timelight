#include "light_element.hpp"
#include <cstdio>
#include <iostream>
#include <random>
#include <stdexcept>

namespace Light
{

	LightElement::LightElement() : LightElement::LightElement(0, 0, 0)
	{
	}

	LightElement::LightElement(LightComponent red,
	                           LightComponent green,
	                           LightComponent blue)
		: red(red), green(green), blue(blue)
	{
	}

	LightElement LightElement::random()
	{
		ColourDistribution dist(0, 255);

		return random(dist, dist, dist);
	}

	LightElement LightElement::random(ColourDistribution red_dist,
	                                  ColourDistribution green_dist,
	                                  ColourDistribution blue_dist)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		return LightElement(red_dist(mt), green_dist(mt), blue_dist(mt));
	}

	std::ostream& operator<<(std::ostream& os, const LightElement& a)
	{
		char buffer[14];
		int result = std::snprintf(buffer, 14, "[%3u,%3u,%3u]", a.red, a.green, a.blue);
		if (!result)
		{
			throw std::runtime_error("light_value_format");
		}
		return os << buffer;
	}

} // namespace Light
