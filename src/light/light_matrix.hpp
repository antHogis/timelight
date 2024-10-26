#ifndef TIMELIGHT_LIGHT_MATRIX_HPP
#define TIMELIGHT_LIGHT_MATRIX_HPP

#include "light_element.hpp"
#include <vector>

namespace Light
{
	typedef std::vector<std::vector<LightElement>> LightMatrixImpl;
	typedef std::vector<Light::LightElement>::size_type LightMatrixRowSize;

	class LightMatrix
	{
	public:
		LightMatrix(int rows, int cols);

		LightElement& element_at(int row, int col);
		void randomize();
		LightMatrixImpl& get_impl();

	private:
		LightMatrixImpl matrix_;
	};
} // namespace Light

#endif
