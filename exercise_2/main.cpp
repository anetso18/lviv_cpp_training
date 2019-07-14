#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.h"
#include "WeightMatrix.h"

#include <ostream>

 int getNumberOfVertices(const std::string &argv )
 {
	 int vertices = 0;
	 std::ifstream in(argv);
	 if (in.is_open())
	 {
		 int start = 0, end = 0, weight = 0;
		 while (in>>start>>end>>weight)
		 {
			 if (start> vertices)
			     vertices = start+1;
		 }
	 }
	 else
	 {
		 std::cout << "Unable to open file";
		 exit(1);
	 }
	 return vertices;
 }

 void loadMatrixFromFile(WeightMatrix& m, const std::string &argv)
 {
	 std::ifstream in(argv);
	 if (in.is_open())
	 {
		 int start = 0, end = 0, weight = 0;
		 while (in >> start >> end >> weight)
		 {
			 m.weightMatrix[start][end] = weight;
	     }
	 }
	 else
	 {
		 std::cerr << "Unable to open file";
         exit(1);
	 }
 }

 int startFrom(const int& vertices)
 {
	 int start = 0;
	 std::cout << "Please enter start vertice: from 0 to " << vertices - 1 << std::endl;
	 std::cin >> start;
	 if (start < 0 || start>7)
	 {
		 std::cerr << "Entered digit is not in range 0 to 7";
		 exit(1); 
	 }
	 return start;
 }

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please specify name of the file by command line argument" << std::endl;
	}
	else
	{ 
		const int vertices = getNumberOfVertices(argv[1]);
		WeightMatrix matrix(vertices);
		
		loadMatrixFromFile(matrix, argv[1]);
		std::cout << matrix << std::endl;
		
		Graph graph(vertices, matrix);
		int start = startFrom(vertices);
		
		std::vector<int> v = graph.findShortestPath(start);
		for (int i = 0; i < vertices; ++i)
		{
            std::cout << "From " << start << " to " << i << "  " << v[i] << " " << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
