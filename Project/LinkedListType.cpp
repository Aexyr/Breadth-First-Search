#include "LinkedListType.h"

ostream& operator<<(ostream& out, const LinkedListType& theList)
{
	Node *current = theList.first;

	while (current != nullptr)
	{
		out << current->getInfo() << " ";
		current = current->getLink();
	}

	return out;
}

LinkedListType::LinkedListType() 
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

void LinkedListType::insertLast(int newItem)
{
	Node *newNode = new Node(newItem, 0);
            								
	if(first == nullptr) first = newNode;	
	else last->setLink(newNode);		

	last = newNode;
	++count;
}

void LinkedListType::destroyList()
{
	while(first != nullptr)   
	{
	   Node *temp = first;
	   first = first->getLink();	
	   delete temp;					
	}

	last = nullptr;	                   
 	count = 0;
}

LinkedListType::~LinkedListType() 
{
	destroyList(); 
}

int LinkedListType::queueFixer(queue<int>& bfsQueue, bool* visited) const 
{
	int vertex, addedCount = 0;
	Node* temp = first;

	while (temp != nullptr) // Loops through the successors of the current vertex
	{
		vertex = temp->getInfo();

		if (!visited[vertex]) // Checks is vertex is visited.
		{
			bfsQueue.push(vertex); // Inserts the vertex into the queue.
			visited[vertex] = true; // Sets the vertex to visited.
			++addedCount; // Iterates everytime a vertex has been added to the queue.
		}
		temp = temp->getLink();
	}
	return addedCount; // Returns the count of added vertexes.
}