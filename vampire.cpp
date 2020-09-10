/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the implementation file for Vampire fighter class.
******************************************************************************/

#include "vampire.hpp"

Vampire::Vampire()
{
	strength = 18;
	armor = 1;
}

Vampire::~Vampire()
{
}

int Vampire::attack()
{
	int diceRoll1;
	diceRoll1 = randomInt(1, 12);
	return diceRoll1;
}
int Vampire::defend()
{
	int charm;
	charm = randomInt(1, 2);
	if (charm == 1)
	{
		int diceRoll1;
		diceRoll1 = randomInt(1, 6);
		return diceRoll1;
	}
	else if (charm == 2)
	{
		return 69;
	}
}
void Vampire::takeDamage(int damage)
{
	strength -= damage;
}

string Vampire::showAttack()
{
	return attackStats;
}

string Vampire::showDefense()
{
	int strengthPoints = strength;
	string str = std::to_string(strengthPoints);
	return (defendStats + str);
}

int Vampire::getArmor()
{
	return armor;
}
int Vampire::getStrengthPts()
{
	return strength;
}