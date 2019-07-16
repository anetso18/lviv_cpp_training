#include "WeightMatrix.h"
#include <iostream>

WeightMatrix::WeightMatrix(const int& vertices_)
:vertices{vertices_}
{
	std::vector<std::vector<int>> matrix_(vertices_, std::vector<int>(vertices));
	weightMatrix = matrix_;
}

WeightMatrix::~WeightMatrix() = default;

int WeightMatrix::GetVertices()
{
	return vertices;
}

int WeightMatrix::GetMatrixElement(int& start, int& end)
{
	return weightMatrix[start][end];
}

void WeightMatrix::SetMatrixElement(int& start, int& end, int& weight) 
{
	weightMatrix[start][end]=weight;
}

std::ostream& operator<< (std::ostream& out,  WeightMatrix matrix)
{
	 for (int i = 0; i < matrix.GetVertices(); ++i)
	 {
		 for (int j = 0; j < matrix.GetVertices(); ++j) {
			 out << matrix.GetMatrixElement(i, j) << " ";
		 }
		 out<<std::endl;
	 }
	return out;
}