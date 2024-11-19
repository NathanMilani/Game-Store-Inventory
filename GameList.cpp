// GameList.cpp : This file contains GameList code Implementation
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "GameList.h"

GameList::GameList(int maxItems)
{
	maxNumItems = maxItems;
	length = 0;
	head = nullptr;
	curPos = nullptr;

	cout << "Hello visitor! Great to have you come. I'm Nathan Milani the owner of Next Level Player's Edge.\n";
}

GameList::~GameList()
{
	MakeEmpty();
}


bool GameList::PutItem(ItemType* newItem)
{
    if (IsFull())
    {
        return false;
    }

    string title = "";
    bool found = false;

    // Try to find if the item is already present in the list
    ItemType* existingItem = GetItem(newItem, found);

    if (found)
    {
        // Item already exists, output the message
        newItem->GetData(title);  // Get the game title
        int partNum = newItem->GetData(title);  // Get part number
        cout << "found! Item " << abs(partNum) << " " << title << " already exists, not adding it\n";
        return false;
    }

    // If not found, create a new node and add it to the list
    Node* newNode = new Node(*newItem);
    newNode->SetNext(head);
    head = newNode;

    // Get the game title and part number for printing
    int partNum = newItem->GetData(title);  // Fetch title and partNumber
    cout << "Added: " << abs(partNum) << ", " << left << setw(26) << title << " ... " << newNode << endl;  // Match output style

    return true;
}

ItemType* GameList::GetItem(ItemType* sample, bool& found)
{
    cout << "Searching...";

    curPos = head;

    string title = "";
    
    while (curPos != nullptr)
    {
        int partNumber = curPos->GetItem().GetData(title);
        cout << abs(partNumber) << "; ";

        if (curPos->GetItem().Compare(sample) == EQUAL)
        {
            found = true;

            ItemType* newItem = new ItemType(curPos->GetItem());
            
            return newItem;
        }
        curPos = curPos->GetNext();
    }
    found = false;
    return nullptr;
}

bool GameList::DeleteItem(ItemType* item)
{
    curPos = head;
    Node* previous = nullptr;

    while (curPos != nullptr)
    {
        if (curPos->GetItem().Compare(item) == EQUAL)
        {
            if (curPos == head)
            {
                head = curPos->GetNext();
            }
            else
            {
                previous->SetNext(curPos->GetNext());
            }

            cout << "Deleting:  ";
            curPos->GetItem().PrintInfo();
            cout << " ... " << curPos << endl;

            delete curPos;

            return true;
        }
        previous = curPos;
        curPos = curPos->GetNext();
    }
    return false;
}

void GameList::ResetList()
{
    curPos = head;
}

bool GameList::IsFull()
{
    return GetLength() >= maxNumItems;
}


void GameList::MakeEmpty()
{
    curPos = head;
    Node* temp;

    while (curPos != nullptr) 
    {
        temp = curPos->GetNext();
        delete curPos;
        curPos = temp;
    }

    head = nullptr;
    curPos = nullptr;
    cout << "\nEnd of list reached. All nodes deleted." << endl;
}

void GameList::PrintList()
{
    cout << "\n\nPrintlist:\n";

    curPos = head;

    while (curPos != nullptr)
    {
        // Print the item information
        curPos->GetItem().PrintInfo();

        // Align the dots and the address
        cout << " ...  " << curPos << endl;
        curPos = curPos->GetNext(); 
    }
}

ItemType* GameList::GetNext()
{
    if (curPos == nullptr)
    {            
        return nullptr;
    }

    ItemType* currentItem = new ItemType(curPos->GetItem());
    curPos = curPos->GetNext();

    return currentItem;
}

int GameList::GetLength()
{
    int length = 0;
    curPos = head;

    while (curPos != nullptr)
    {
        length++;
        curPos = curPos->GetNext();
    }
    return length;
}

