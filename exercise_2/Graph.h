#pragma once	
#include <iostream>

class Graph
{
private:
	static int const N = 8;
	int arr[N][N];
	void printPath(int a[N], int start);

public:
	Graph(int(&a)[N][N]);
	~Graph();
	void printGraph();
	void  findShortestPath(int start);
};
