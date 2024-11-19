// Node.h : This file contains Node code Declorations
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022#pragma once

#pragma once
#include "ItemType.h" 
class Node
{
private:
	ItemType* item;
	Node* next;

public:
	Node(ItemType sampleNewItem);
	~Node();

	void SetNext(Node* nextItem);
	ItemType GetItem();
	Node* GetNext();
};

