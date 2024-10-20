#include "light_matrix.hpp"
#include "light_element.hpp"

namespace Light
{
	LightMatrix::LightMatrix(int rows, int cols)
	{
		matrix_ = LightMatrixImpl(rows);

		for (int i = 0; i < rows; ++i)
		{
			matrix_.at(i).resize(cols);
		}
	}

	LightElement& LightMatrix::element_at(int row, int col)
	{
		return matrix_.at(row).at(col);
	}

	void LightMatrix::randomize()
	{
		for (auto& row : matrix_)
		{
			for (LightMatrixRowSize i = 0; i < row.size(); i++)
			{
				row[i] = LightElement::random(ColourDistribution(180, 220),
				                              ColourDistribution(100, 120),
				                              ColourDistribution(30, 50));
			}
		}
	}

	LightMatrixImpl& LightMatrix::get_impl()
	{
		return matrix_;
	}

} // namespace Light
