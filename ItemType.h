// ItemType.h : This file contains ItemType code Declorations
// Class assignment for Program 2
// Author: Nathan Milani – This is my own work!
// I understand that I may be asked questions about my submission.
// email: nrm0002@uah.edu
// For: CS221-01, Fall 2023 Mrs. Delugach
// Using compiler MSVS 2022

#pragma once 
#include <iostream> 
#include <string> 
#include "iomanip"
using namespace std;

enum Comp { EQUAL, LESS, GREATER, INDETERMINITE};

class ItemType {
private:
    string gameTitle;       
    int partNumber;
    Comp greater = GREATER;
    Comp less = LESS;
    Comp equal = EQUAL;
    Comp indeterminite = INDETERMINITE;
    
public:
    ItemType();
    ItemType(string newTitle, int partNum);

    ~ItemType();

    Comp Compare(ItemType* sample);

    int GetData(string& Title);

    void PrintInfo();
};

