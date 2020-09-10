/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: Below is the header file containing the input validation
**			 function that verifies if the user enters a positive 
**			 integer. 
******************************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <ctype.h>
#include <string>

int getPosInt();

bool isPosInt(std::string);

#endif