#pragma once
#include <iostream>
#include <vector>
struct WeightMatrix
{
public:
	WeightMatrix(int verticiesCount);
	~WeightMatrix();
	int GetVerticesCount()const;
	int GetMatrixElement(int start, int end)const;
	void SetMatrixElement(int start, int end, int weight);
	
private:
	int verticiesCount;
	std::vector<std::vector<int>> weightMatrix;
	friend std::ostream& operator << (std::ostream& out, const WeightMatrix& matrix);
};
 