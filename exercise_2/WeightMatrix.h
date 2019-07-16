#pragma once
#include <iostream>
#include <vector>
struct WeightMatrix
{
public:
	
	WeightMatrix(const int& vertices_);
	~WeightMatrix();
	int GetVertices();
	int GetMatrixElement(int& start, int& end);
	void SetMatrixElement(int& start, int& end, int& weight);
	
private:
	int vertices;
	std::vector<std::vector<int>> weightMatrix;
	friend std::ostream& operator << (std::ostream& out,  WeightMatrix matrix);
};
 