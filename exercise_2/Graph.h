#pragma once	
#include <iostream>
#include <vector>
#include "WeightMatrix.h"

class Graph
{
public:
	Graph(const int& vertices_, WeightMatrix& matrix_);
	~Graph();
	std::vector <int> findShortestPath(int start);

private:	
	int vertices;	
	WeightMatrix matrix;
	int getIndexofNearestUnvisitedVertice(std::vector<int>& shortestPath, std::vector<bool>& visited);
	void setToDefaultValues(std::vector <int>& shortestPath, std::vector <bool>& visited);
	bool isPathToNextUnvisitedVertice(std::vector <bool>& visited, int& index, int& j);
};