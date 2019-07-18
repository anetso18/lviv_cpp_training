#include "Graph.h"
#include <iostream>
#include <vector>
#include "WeightMatrix.h"

Graph::Graph(int verticiesCount, WeightMatrix& matrix)
	: verticiesCount { verticiesCount }, matrix { matrix }
{
}

Graph::~Graph() = default;

int Graph::getIndexofNearestUnvisitedVertice(const std::vector<int>& shortestPath,const std::vector<bool>& visited)
{
	int min = INT_MAX, min_index = 0;
	for (int i = 0; i < verticiesCount; ++i)
	{
		if (!visited[i] && shortestPath[i] <= min)
		{
			min = shortestPath[i], min_index = i;
		}
	}
	return min_index;
}

void Graph::setToDefaultValues( std::vector <int>& shortestPath, std::vector <bool>& visited)
{
	for (int i = 0; i < verticiesCount; ++i)
	{
		shortestPath.push_back(INT_MAX);
		visited.push_back(false);
	}
}

bool Graph::isPathToNextUnvisitedVertice(const std::vector <bool>& visited, int index, int j)
{
	return (!visited[j] && matrix.GetMatrixElement(index,j) != 0);
}

std::vector <int> Graph::findShortestPath(int start)
{
	std::vector <int> shortestPath;
	std::vector <bool> visited;
	setToDefaultValues(shortestPath, visited);
	
	shortestPath[start] = 0;
	for (int i = 0; i < verticiesCount; ++i)
	{
		int index = getIndexofNearestUnvisitedVertice(shortestPath, visited);
		visited[index] = true;
		for (int j = 0; j < verticiesCount; ++j)
		{
			if(isPathToNextUnvisitedVertice(visited, index, j))
			{
				if (shortestPath[index] + matrix.GetMatrixElement(index,j) < shortestPath[j])
				{
					shortestPath[j] = shortestPath[index] + matrix.GetMatrixElement(index,j);
				}
			}
		}
	}
	return shortestPath;
}



