/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the implementation file for Blue Men fighter class.
******************************************************************************/

#include "blueMen.hpp"


BlueMen::BlueMen()
{
	strength = 12;
	armor = 3;
}

BlueMen::~BlueMen()
{
}

int BlueMen::attack()
{
	int diceRoll1, diceRoll2;
	diceRoll1 = randomInt(1, 10);
	diceRoll2 = randomInt(1, 10);
	return (diceRoll1 + diceRoll2);
}

// need to adjust Blue Men defense based on his strength
int BlueMen::defend()
{
	// adjust defense due to Mob ability
	if (strength > 8)
	{
		int diceRoll1, diceRoll2, diceRoll3; 
		diceRoll1 = randomInt(1, 6);
		diceRoll2 = randomInt(1, 6);
		diceRoll3 = randomInt(1, 6);
		return diceRoll1 + diceRoll2 + diceRoll3; 
	}
	else if (strength > 4)
	{
		int diceRoll1, diceRoll2, diceRoll3;
		diceRoll1 = randomInt(1, 6);
		diceRoll2 = randomInt(1, 6);
		return diceRoll1 + diceRoll2;
	}
	else
	{
		int diceRoll1, diceRoll2, diceRoll3;
		diceRoll1 = randomInt(1, 6);
		return diceRoll1;
	}
}

void BlueMen::takeDamage(int damage)
{
	strength -= damage;
}

string BlueMen::showAttack()
{
	return attackStats;
}

string BlueMen::showDefense()
{
	int strengthPoints = strength;
	string str = std::to_string(strengthPoints);
	if (strengthPoints > 8)
	{
		return (defendStats1 + str);
	}
	else if (strengthPoints > 4)
	{
		return (defendStats2 + str);
	}
	else
	{
		return (defendStats3 + str);
	}

}

int BlueMen::getArmor()
{
	return armor;
}
int BlueMen::getStrengthPts()
{
	return strength;
}