#include "WeightMatrix.h"
#include <iostream>

WeightMatrix::WeightMatrix( int verticiesCount)
:verticiesCount{ verticiesCount }
{
	std::vector<std::vector<int>> matrix(verticiesCount, std::vector<int>(verticiesCount));
	weightMatrix = matrix;
}

WeightMatrix::~WeightMatrix() = default;

 int WeightMatrix::GetVerticesCount() const
{
	return verticiesCount;
}

int WeightMatrix::GetMatrixElement(int start, int end)const 
{
	return weightMatrix[start][end];
}

void WeightMatrix::SetMatrixElement(int start, int end, int weight)
{
	weightMatrix[start][end]=weight;
}

std::ostream& operator << (std::ostream& out, const WeightMatrix& matrix)
{
	 for (int i = 0; i < matrix.GetVerticesCount(); ++i)
	 {
		 for (int j = 0; j < matrix.GetVerticesCount(); ++j) {
			 out << matrix.GetMatrixElement(i, j) << " ";
		 }
		 out<<std::endl;
	 }
	return out;
}