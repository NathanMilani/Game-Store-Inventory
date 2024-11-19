//Things tested for:
//1). Negeitive numbers as input for part numbers
//2). Tested for all possible deleted node and they all return intended outputs
//3). Tested for all possible duplications as input into the list and the output is satisfied
//4). Tested for all possible searching parts and the output is as intended
// 
//
//
//
//





#include "ItemType.h"
#include "Node.h"
#include "GameList.h"

int main()
{
	cout << "\033[32mlinked List Testing Application!\nInstantiating List and some items to work with\n\n\033[0m";
	GameList newList(5);
	ItemType game1("Beat Saber", -1);
	ItemType game2("Star Trek: Bridge Crew", -2);
	ItemType game3("Megaman Legends", -3);
	ItemType game4("Final Fantasy VII", -4);


	cout << "\033[32m""\nTest 1: Adding 4 items, Check that the list mentions their additions, then print them in 4, 3, 2, 1 order\n""\033[0m";
	newList.PutItem(&game1);
	newList.PutItem(&game2);
	newList.PutItem(&game3);
	newList.PutItem(&game4);
	newList.PutItem(&game1);

	newList.PrintList();

	cout << "\033[32m""\n\nSearching for item2: 2, Star Trek: Bridge Crew\n""\033[0m";

	bool found = false;
	newList.GetItem(&game2, found);

	cout << "\033[32m""\n\nDelete item 3\n""\033[0m";
	newList.DeleteItem(&game3);

	newList.MakeEmpty();

	return 0;
}

