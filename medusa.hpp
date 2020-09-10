/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the header file for the Medusa fighter class.
******************************************************************************/

#include "character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
protected:
	int offense;
	int defense;
	int armor;
	int strength;

	string attackStats = "Medusa - Attack: 2d6";
	string defendStats = "Medusa - Defense: 1d6, Armor: 3, Strength Points: ";

public:
	Medusa();
	~Medusa();
	int attack();
	int defend();
	void takeDamage(int);

	int getArmor();
	int getStrengthPts();

	string showAttack();
	string showDefense();
};
#endif
