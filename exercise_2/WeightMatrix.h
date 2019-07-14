#pragma once
#include <iostream>
#include <vector>

struct WeightMatrix
{
public:
	WeightMatrix();
	WeightMatrix(const int& vertices);
	~WeightMatrix();
	std::vector<std::vector<int>> weightMatrix;
private:
	friend std::ostream& operator<< (std::ostream& out, const WeightMatrix& m);
};
 
