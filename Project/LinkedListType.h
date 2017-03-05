#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
	Node() : info(0), link(nullptr){}
    Node(int theInfo, Node *theLink) : info(theInfo), link(theLink){}
    Node *getLink( ) const { return link; }
    int getInfo( ) const { return info; }
    void setInfo(int theInfo) { info = theInfo; }
    void setLink(Node *theLink) { link = theLink; }
	~Node(){}
private:
    int info;		
    Node *link;	
};

class LinkedListType
{
	friend ostream& operator<<(ostream& out, const LinkedListType& theList);

public:	
	
	LinkedListType(); 

	void insertLast(int newItem);

	void destroyList();
	
	~LinkedListType();   

	/*************************************************************
	*
	*	Write your function declarations below this block.
	*
	**************************************************************/
	int queueFixer(queue<int>& bfsQueue, bool* visited) const;

protected:
    int count;		//variable to store the number of elements in the list
    Node *first;	//pointer to the first node of the list
    Node *last;		//pointer to the last node of the list 

};

#endif

