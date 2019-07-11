#include <iostream>
#include<fstream>
#include "Graph.h"

int const N = 8;

void loadArrayFromFile(int(&arr)[N][N], std::string argv);

void loadArrayFromFile(int (&arr)[N][N], std::string argv) {

	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i != j)
			{
				arr[i][j] = -1;
			}
		}
	}
		std::ifstream in(argv);

		if (in.is_open())
		{
			int start = 0, end = 0, weight = 0;

			while (in >> start >> end >> weight) {

				arr[start][end] = weight;
			}
			in.close();
		}

		else
		{
			std::cout << "Unable to open file";
		}
	}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please specify name of the file by command line argument" << std::endl;
	}
	else
	{
		int arr[N][N]{ 0 };
		loadArrayFromFile(arr, argv[1]);

		Graph graph(arr);
		graph.printGraph();

		graph.findShortestPath(0);
	}
	return EXIT_SUCCESS;
}
