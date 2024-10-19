#ifndef LIGHT_ELEMENT_HPP
#define LIGHT_ELEMENT_HPP

#include <iostream>

namespace Light
{
	typedef unsigned char LightComponent;

	struct LightElement
	{
		LightElement();
		LightElement(LightComponent red,
		             LightComponent green,
		             LightComponent blue,
		             LightComponent luminance);

		static LightElement random();

		LightComponent red;
		LightComponent green;
		LightComponent blue;
		LightComponent luminance;
	};

	std::ostream& operator<<(std::ostream& strm, const LightElement& a);

} // namespace Light
#endif
