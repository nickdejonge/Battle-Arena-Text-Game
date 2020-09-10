/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the implementation file for Medusa fighter class.
******************************************************************************/

#include "medusa.hpp"

Medusa::Medusa()
{
	strength = 8;
	armor = 3;
}

Medusa::~Medusa()
{
}

int Medusa::attack()
{
	int diceRoll1, diceRoll2;
	diceRoll1 = randomInt(1, 6);
	diceRoll2 = randomInt(1, 6);
	if ((diceRoll1 + diceRoll2) == 12)
	{
		return 69;
	}
	else
	{
		return (diceRoll1 + diceRoll2);
	}
}
int Medusa::defend()
{
	int diceRoll1;
	diceRoll1 = randomInt(1, 6);
	return diceRoll1;
}
void Medusa::takeDamage(int damage)
{
	strength -= damage;
}

string Medusa::showAttack()
{
	return attackStats;
}

string Medusa::showDefense()
{
	int strengthPoints = strength;
	string str = std::to_string(strengthPoints);
	return (defendStats + str);
}

int Medusa::getArmor()
{
	return armor;
}
int Medusa::getStrengthPts()
{
	return strength;
}