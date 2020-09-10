/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the header file for the abstract character class used 
**			in the fantasy fighting game. Cannot be instantiated.
******************************************************************************/

#include "randomInt.hpp"
#include <string>

using std::string;

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
protected:
	int offense;
	int defense;
	int armor;
	int strength;

public: 
	Character() {};
	virtual int attack() = 0;
	virtual int defend() = 0; 
	virtual void takeDamage(int) = 0;

	virtual int getArmor() = 0;
	virtual int getStrengthPts() = 0;

	// virtual void function for attackStatus and defenseStatus
	virtual string showAttack() = 0;
	virtual string showDefense() = 0;
};
#endif