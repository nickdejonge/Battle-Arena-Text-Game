/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the header file for the barbarian fighter class.
******************************************************************************/

#include "character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian: public Character
{
protected:
	int offense;
	int defense;
	int armor;
	int strength;
	
	string attackStats = "Barbarian - Attack: 2d6";
	string defendStats = "Barbarian - Defense: 2d6, Armor: 0, Strength Points: ";

public:
	Barbarian();
	~Barbarian();
	int attack();
	int defend();
	void takeDamage(int);

	int getArmor();
	int getStrengthPts();

	string showAttack();
	string showDefense();
};
#endif