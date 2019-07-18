#pragma once	
#include <iostream>
#include <vector>
#include "WeightMatrix.h"

class Graph
{
public:
	Graph(int verticiesCount, WeightMatrix& matrix);
	~Graph();
	std::vector <int> findShortestPath(int start);
private:	
	int verticiesCount;
	WeightMatrix matrix;
	int getIndexofNearestUnvisitedVertice(const std::vector<int>& shortestPath, const std::vector<bool>& visited);
	void setToDefaultValues(std::vector <int>& shortestPath, std::vector <bool>& visited);
	bool isPathToNextUnvisitedVertice(const std::vector <bool>& visited, int index, int j);
};