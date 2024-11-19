// Node.cpp : This file contains Node code Implementation
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Node.h" 

Node::Node(ItemType sampleNewItem)
{
	item = new ItemType(sampleNewItem);
	next = nullptr;
}

Node::~Node()
{
	delete item;
}

void Node::SetNext(Node* nextItem)
{
	next = nextItem;
}

ItemType Node::GetItem()
{
	return *item;
}

Node* Node::GetNext()
{
	return next;
}

