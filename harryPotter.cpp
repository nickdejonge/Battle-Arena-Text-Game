/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the implementation file for Harry Potter fighter class.
******************************************************************************/

#include "harryPotter.hpp"

HarryPotter::HarryPotter()
{
	strength = 10;
	armor = 0;
	secondLife = true;
}

HarryPotter::~HarryPotter()
{
}

int HarryPotter::attack()
{
	int diceRoll1, diceRoll2;
	diceRoll1 = randomInt(1, 6);
	diceRoll2 = randomInt(1, 6);
	return (diceRoll1 + diceRoll2);
}
int HarryPotter::defend()
{
	int diceRoll1, diceRoll2;
	diceRoll1 = randomInt(1, 6);
	diceRoll2 = randomInt(1, 6);
	return (diceRoll1 + diceRoll2);
}
void HarryPotter::takeDamage(int damage)
{
	strength -= damage;
	if (strength < 0 && secondLife == true)
	{
		strength = 20;
		secondLife = false;
	}
}

string HarryPotter::showAttack()
{
	return attackStats;
}

string HarryPotter::showDefense()
{
	int strengthPoints = strength;
	string str = std::to_string(strengthPoints);
	return (defendStats + str);
}

int HarryPotter::getArmor()
{
	return armor;
}
int HarryPotter::getStrengthPts()
{
	return strength;
}