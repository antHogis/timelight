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
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, 255);

		return LightElement(dist(mt), dist(mt), dist(mt), dist(mt));
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
