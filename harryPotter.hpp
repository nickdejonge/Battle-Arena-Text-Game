/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the header file for the Harry Potter fighter class.
******************************************************************************/

#include "character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character
{
protected:
	int offense;
	int defense;
	int armor;
	int strength;

	bool secondLife;

	string attackStats = "Harry Potter - Attack: 2d6";
	string defendStats = "Harry Potter - Defense: 2d6, Armor: 0, Strength Points: ";

public:
	HarryPotter();
	~HarryPotter();
	int attack();
	int defend();
	void takeDamage(int);

	int getArmor();
	int getStrengthPts();

	string showAttack();
	string showDefense();
};
#endif