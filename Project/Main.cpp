#include "GraphType.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string FILE_NAME = "graph_data.txt";

int main()
{
	GraphType g1;
	g1.createGraph(FILE_NAME);
	cout << g1 << endl;

	vector<int> bfsSequence;
	cout << "\nBFS traversal: ";
	g1.bfsTraversal(0, bfsSequence);		// 0 is the first vertex of the BFS
	for (int vertex : bfsSequence)
		cout << vertex << " ";
	cout << endl;

	cout << endl;
	system("Pause");
	return 0;
}
