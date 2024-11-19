#pragma once 
// GameList.h : This file contains GameList code Declorations
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "Node.h" 
#include "ItemType.h"

class GameList
{
private:
	Node* head;
	Node* curPos;
	int maxNumItems = 0;
	int length = 0;

public:
	GameList(int maxItems);
	~GameList();

	bool PutItem(ItemType* newItem);
	ItemType* GetItem(ItemType* findItem, bool& found);
	bool DeleteItem(ItemType* delItem);
	void ResetList();
	bool IsFull();
	void MakeEmpty();
	void PrintList();
	ItemType* GetNext();
	int GetLength();
};

