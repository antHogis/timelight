#include "light_matrix.hpp"

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

	LightElement& LightMatrix::elementAt(int row, int col)
	{
		return matrix_.at(row).at(col);
	}

	void LightMatrix::randomize()
	{
		for (auto& row : matrix_)
		{
			for (LightMatrixRowSize i = 0; i < row.size(); i++)
			{
				row[i] = LightElement::random();
			}
		}
	}

	LightMatrixImpl& LightMatrix::getImpl()
	{
		return matrix_;
	}

} // namespace Light
