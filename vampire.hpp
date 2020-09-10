/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the header file for the Vampire fighter class.
******************************************************************************/

#include "character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
protected:
	int offense;
	int defense;
	int armor;
	int strength;

	string attackStats = "Vampire - Attack: 1d12";
	string defendStats = "Vampire - Defense: 1d6, Armor: 1, Strength Points: ";

public:
	Vampire();
	~Vampire();
	int attack();
	int defend();
	void takeDamage(int);

	int getArmor();
	int getStrengthPts();

	string showAttack();
	string showDefense();
};
#endif