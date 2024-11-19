// ItemType.cpp : This file contains ItemType code Implementation
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#include "ItemType.h"

ItemType::ItemType()
{
    gameTitle = "Pong";
    partNumber = 0;
}

ItemType::ItemType(string newTitle, int partNum)
{
    gameTitle = newTitle;
    partNumber = partNum;
}

ItemType::~ItemType()
{

}

Comp ItemType::Compare(ItemType* sample)
{
    if (partNumber < sample->partNumber)
    {
        return less;
    }
    if (partNumber > sample->partNumber)
    {
        return greater;
    }
    if (partNumber == sample->partNumber)
    {
        return equal;
    }
    if (partNumber != sample->partNumber)
    {
        return indeterminite;
    }
}
 
int ItemType::GetData(string& title)
{
    title = gameTitle;
    return partNumber;
}

void ItemType::PrintInfo()
{
    cout << abs(partNumber) << ", " << left << setw(24) << gameTitle;
}

