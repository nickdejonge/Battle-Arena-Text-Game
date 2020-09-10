/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the implementation file for barbarian fighter class.
******************************************************************************/

#include "barbarian.hpp"

Barbarian::Barbarian() 
{
	strength = 12;
	armor = 0;
}

Barbarian::~Barbarian()
{
}

int Barbarian::attack() 
{
	int diceRoll1, diceRoll2;
	diceRoll1 = randomInt(1, 6);
	diceRoll2 = randomInt(1, 6);
	return (diceRoll1 + diceRoll2);
}
int Barbarian::defend() 
{
	int diceRoll1, diceRoll2;
	diceRoll1 = randomInt(1, 6);
	diceRoll2 = randomInt(1, 6);
	return (diceRoll1 + diceRoll2);
}
void Barbarian::takeDamage(int damage)
{
	strength -= damage;
}

string Barbarian::showAttack()
{
	return attackStats;
}

string Barbarian::showDefense()
{
	int strengthPoints = strength;
	string str = std::to_string(strengthPoints);
	return (defendStats + str);
}

int Barbarian::getArmor()
{
	return armor;
}
int Barbarian::getStrengthPts()
{
	return strength;
}