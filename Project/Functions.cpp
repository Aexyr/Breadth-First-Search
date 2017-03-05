/*
	Fazeli, Bijan
	Lauguico, Marco

	CS A200

	Febuary 16, 2017
*/

#include "GraphType.h"

void GraphType::bfsTraversal(int vertex, vector<int>& bfs) const 
{
	if (gSize > 0)  // if gSize == 0 or less than 0 then do nothing.
	{
		if (gSize == 1) 
			bfs.push_back(vertex);
		else  // if gSize > 1 then do the code below else if gSize is 1 then do nothing (BFS is done).
		{
			queue<int> bfsQueue;
			bool* visited = new bool[gSize](); // Dynamic array of visited vertexes.
			visited[vertex] = true; // Sets the vertex to visited.
			int visitedCounter = 1;
			bfsQueue.push(vertex);
			do // This loops until all vertexes are in the BFS.
			{
				vertex = bfsQueue.front(); // Changes the value of vertex into the front of queue.
				bfsQueue.pop(); // Removes vertex in the queue.

				// Checks if all the vertex have been in the queue already.
				if (visitedCounter != gSize)
				{
					// queueFixer returns the number of new added vertex/s in the queue.
					visitedCounter += graph[vertex].queueFixer(bfsQueue, visited);
				}

				bfs.push_back(vertex); // Adds vertex in the the BFS.
			} while (!bfsQueue.empty());

			delete[] visited;
		}
	}
}