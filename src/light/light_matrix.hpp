#ifndef LIGHT_MATRIX_HPP
#define LIGHT_MATRIX_HPP

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

		LightElement& elementAt(int row, int col);

		void randomize();

		LightMatrixImpl& getImpl();

	private:
		LightMatrixImpl matrix_;
	};
} // namespace Light

#endif
