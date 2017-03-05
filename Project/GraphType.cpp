#include "GraphType.h"

ostream& operator<<(ostream& out, const GraphType& theGraph)
{
	if (theGraph.gSize == 0)
		out << "Graph is empty.\n";
	else
	{
		for (int index = 0; index < theGraph.gSize; ++index)
			out << index << " => successors: " << theGraph.graph[index] << endl;
	}

	return out;
}
     // default constructor
GraphType::GraphType()  
{
     maxSize = MAX_SIZE;
     graph = new LinkedListType[maxSize];
	 gSize = 0;
}

void GraphType::createGraph(const string& fileName)
{
	ifstream infile;
	int vertex;
	int adjacentVertex;

	if (gSize != 0)		//if the graph is not empty, make it empty
		clearGraph();

	infile.open(fileName);

	if (!infile)
	{
		cerr << "Cannot open the input file." << endl;
		system("Pause"); //to check the error message
		exit(1);
	}

	infile >> gSize;  //get the number of vertices

	for (int index = 0; index < gSize; ++index)
	{
		//read the vertex in the graph and its adjacent vertices
		infile >> vertex;
		infile >> adjacentVertex;

		while (adjacentVertex != -1 && adjacentVertex != -999)
		{
			//graph is an array of linked lists
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		}
	}

	infile.close();
}

void GraphType::clearGraph()
{
	for (int index = 0; index < gSize; ++index)
		graph[index].destroyList();

	gSize = 0;
}

GraphType::~GraphType()
{
	clearGraph();

	delete[] graph;
}

