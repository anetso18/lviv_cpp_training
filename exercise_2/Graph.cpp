#include "Graph.h"
#include <iostream>

Graph::Graph(int(&a)[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			arr[i][j] = a[i][j];
		}
	}
}

Graph::~Graph()
{
}

void  Graph::printGraph()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::printPath(int a[N], int start)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << "From " << start << " to " << i << "  " << a[i] << " " << std::endl;
	}
}

void  Graph::findShortestPath(int start = 0)
{
	int path[N]{ 0 };
	bool visited[N];

	for (int i = 0; i < N; ++i)
	{
		path[i] = INT_MAX;
		visited[i] = false;
	}
	path[start] = 0;
	int index = -1;
	for (int i = 0; i < N; ++i)
	{
		int min = INT_MAX;

		for (int j = 0; j < N; ++j)
		{
			if (!visited[j] && path[j] <= min)
			{
				min = path[j];
				index = j;
			}
		}
		visited[index] = true;
		for (int j = 0; j < N; ++j)
		{
			if (!visited[j] && arr[index][j] > 1
				&& path[index] != INT_MAX
				&& path[index] + arr[index][j] < path[j])
			{
				path[j] = path[index] + arr[index][j];
			}
		}
	}
	printPath(path, start);
}


