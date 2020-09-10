/******************************************************************************
** Program Name: Project 3 (Battle Arena)
** Author: Nick de Jonge
** Description: This is the header file for the Blue Men fighter class.
******************************************************************************/

#include "character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
protected:
	int offense;
	int defense;
	int armor;
	int strength;

	string attackStats = "Blue Men - Attack: 2d10";
	// adjust Blue Men defense based on his strength
	string defendStats1 = "Blue Men - Defense: 3d6, Armor: 3, Strength Points: ";
	string defendStats2 = "Blue Men - Defense: 2d6, Armor: 3, Strength Points: ";
	string defendStats3 = "Blue Men - Defense: 1d6, Armor: 3, Strength Points: ";

public:
	BlueMen();
	~BlueMen();
	int attack();
	int defend();
	void takeDamage(int);

	int getArmor();
	int getStrengthPts();

	string showAttack();
	string showDefense();


};
#endif