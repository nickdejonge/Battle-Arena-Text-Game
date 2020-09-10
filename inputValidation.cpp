/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: Below is the implementation file containing the input 
**			 validation function that verifies if the user enters a positive
**			 integer.
******************************************************************************/

#include <iostream>
#include "inputValidation.hpp"

int getPosInt()
{
	std::string entry; // holds string input 
	int userInput; // holds user input after string is changed to integer

	// repeats until user gives a positive integer
	do
	{
		// retrieve entry from user 
		std::getline(std::cin, entry);
		// std::cin >> entry;

		// error message if entry is not a positive integer 
		if (!(isPosInt(entry)))
		{
			std::cout << "Invalid entry.";
			std::cout << std::endl;
		}
	} 

	// if entry is not a positive integer, loop repeats
	while (!(isPosInt(entry)));
	
	// converts string to integer 
	userInput = std::atoi(entry.c_str());
	
	return userInput;
}

// verify input characters are integers by stepping through string
bool isPosInt(std::string inputString)
{
	bool digitCheck = false; // assumes not integer until isdigit checks
	for (int count = 0; count < inputString.size(); count++)
	{
		if (isdigit(inputString[count])) // isdigit checks for non-digits
			digitCheck = true;
		else // returns false if any character is not a digit
			return false;
	}
	return digitCheck;
}