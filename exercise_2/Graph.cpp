#include "Graph.h"
#include <iostream>
#include <vector>
#include "WeightMatrix.h"

Graph::Graph(const int& vertices, WeightMatrix& m)
{
	this->vertices = vertices;
	this->matrix = m;
}

Graph::~Graph() = default;

int Graph::minIndex(std::vector<int>& v, std::vector<bool>& visited)
{
	int min = INT_MAX, min_index = 0;
	for (int i = 0; i < vertices; ++i)
	{
		if (visited[i] == false && v[i] <= min)
		{
			min = v[i], min_index = i;
		}
	}
	return min_index;
}

void Graph:: setToDefaultValues(std::vector <int>& shortestPath, std::vector <bool>& visited)
{
	for (int i = 0; i < vertices; ++i)
	{
		shortestPath.push_back(INT_MAX);
		visited.push_back(false);
	}
}
bool Graph::isPathToNextUnvisitedVertice(std::vector <bool>& visited, int& index, int& j)
{
	if ((!visited[j]) && (matrix.weightMatrix[index][j] != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector <int>  Graph::findShortestPath(int start)
{
	std::vector <int> shortestPath;
	std::vector <bool> visited;
	setToDefaultValues(shortestPath, visited);
	shortestPath[start] = 0;
	for (int i = 0; i < vertices; ++i)
	{
		int index = minIndex(shortestPath, visited);
		visited[index] = true;
		for (int j = 0; j < vertices; ++j)
		{
			if(isPathToNextUnvisitedVertice(visited, index, j))
			{
				if (shortestPath[index] + matrix.weightMatrix[index][j] < shortestPath[j])
				{
					shortestPath[j] = shortestPath[index] + matrix.weightMatrix[index][j];
				}
			}
		}
	}
	return shortestPath;
}
