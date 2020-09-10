/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: Below is the header file for the menu for fantasy fighting 
**              game. Gives user option to pick two characters to fight. Then
**              user gives option to run again after completion of battle.
******************************************************************************/

#include "menu.hpp"

int menu()
{
	// variable to hold user's menu option choice
	int option;

	std::cout << "Option 1: Battle Arena\nOption 2: Quit\n";
	std::cout << "Press 1 or 2 on your keyboard to choose an option.\n";

	// verify user enters a valid number using input validation
	option = getPosInt();
	
	// inform user of incorrect choice if input not equal to 1 or 2
	while (option != 1 && option != 2)
	{
		std::cout << "Invalid entry. Options are 1 and 2.\n";
		option = getPosInt();
	}

	// returns 1 or 2 depending on choice for main function to run option
	if (option == 1)
	{
		return 1;
	}

	else if (option == 2)
	{
		return 2;
	}
}