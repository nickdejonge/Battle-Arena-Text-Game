/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the implementation file for the random integer
**			generating function that accepts the min and max integers the 
**			user wants to return.
******************************************************************************/

#include "randomInt.hpp"
#include <cstdlib>
#include <ctime>

int randomInt(int min, int max)
{
	//std::srand(std::time(0));
	int random_num = (std::rand() % max) + min;
	return random_num;
}
