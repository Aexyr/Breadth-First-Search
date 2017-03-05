#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H

#include "LinkedListType.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 50;

class GraphType
{
	friend ostream& operator<<(ostream& out, const GraphType& theGraph);

public:
	GraphType();

	void createGraph(const string& fileName);

	void clearGraph();
	
	~GraphType();

	/*************************************************************
	*
	*	Write your function declarations go below this block.
	*
	**************************************************************/
	void bfsTraversal(int vertex, vector<int>& bfs) const;



private:
	int maxSize;    //maximum number of vertices
	int gSize;      //current number of vertices

	LinkedListType *graph; //array of pointers to objects 
							//of type LinkedListGraph to  
							//create the adjacency lists 
};

#endif