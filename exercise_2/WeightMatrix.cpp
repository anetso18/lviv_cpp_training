#include "WeightMatrix.h"
#include <iostream>

WeightMatrix::WeightMatrix() {}

WeightMatrix::WeightMatrix(const int& vertices)
{
	std::vector<std::vector<int>> matrix(vertices, std::vector<int>(vertices));
	this->weightMatrix = matrix;
}

WeightMatrix::~WeightMatrix() = default;

std::ostream& operator << (std::ostream& out, const WeightMatrix& m)
{
	 for (int i = 0; i< m.weightMatrix.size(); ++i) 
	 {
		 for (int j = 0; j < m.weightMatrix.size(); ++j){
			 out << m.weightMatrix[i][j] << " ";
		 }
		 out << std::endl;
	 }
	return out;
}
