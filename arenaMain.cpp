/******************************************************************************
** Program Name: Battle Arena
** Author: Nick de Jonge
** Description: This is the driver main function for the fantasy fighting
**			game "Battle Arena". It allows the user to pick two characters 
**			and have them face off in battle. After each round, results are 
**			shown. First warrior to kill their opponent wins the battle.
******************************************************************************/

#include "barbarian.hpp"
#include "blueMen.hpp"
#include "character.hpp"
#include "harryPotter.hpp"
#include "inputValidation.hpp"
#include "medusa.hpp"
#include "menu.hpp"
#include "randomInt.hpp"
#include "vampire.hpp"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// function prototypes
void intro();
int fighterChoice();
bool attackStatus(Character*, Character*);

int main()
{
	// generate seed for randomInt function
	std::srand(std::time(0));

	int option;
	// call main menu
	option = menu();

	while (option == 1)
	{
		intro();
		int battle = 1;
		while (battle == 1)
		{
			// choose character for player 1
			cout << "\nPlayer 1 choose your fighter!\n";
			int fighter1 = fighterChoice();
			if (fighter1 < 0 || fighter1 > 4)
			{
				cout << "Invalid choice.\n";
				fighter1 = fighterChoice();
			}
			// choose character for player 2
			cout << "\nPlayer 2 choose your fighter!\n";
			int fighter2 = fighterChoice();
			if (fighter2 < 0 || fighter2 > 4)
			{
				cout << "Invalid choice.\n";
				fighter2 = fighterChoice();
			}

			// create  player 1's fighter object
			Character* player1 = nullptr;
			string p1;
			if (fighter1 == 0)
			{
				player1 = new Barbarian;
				p1 = "Barbarian";
			}
			else if (fighter1 == 1)
			{
				player1 = new BlueMen;
				p1 = "Blue Men";
			}
			else if (fighter1 == 2)
			{
				player1 = new HarryPotter;
				p1 = "Harry Potter";
			}
			else if (fighter1 == 3)
			{
				player1 = new Medusa;
				p1 = "Medusa";
			}
			else if (fighter1 == 4)
			{
				player1 = new Vampire;
				p1 = "Vampire";
			}
			else if (fighter1 < 0 || fighter1 > 4)
			{
				player1 = new Barbarian;
				p1 = "Barbarian";
			}
			// create player 2's fighter object
			Character* player2 = nullptr;
			string p2;
			if (fighter2 == 0)
			{
				player2 = new Barbarian;
				p2 = "Barbarian";
			}
			else if (fighter2 == 1)
			{
				player2 = new BlueMen;
				p2 = "Blue Men";
			}
			else if (fighter2 == 2)
			{
				player2 = new HarryPotter;
				p2 = "Harry Potter";
			}
			else if (fighter2 == 3)
			{
				player2 = new Medusa;
				p2 = "Medusa";
			}
			else if (fighter2 == 4)
			{
				player2 = new Vampire;
				p2 = "Vampire";
			}
			else if (fighter2 < 0 || fighter2 > 4)
			{
				player2 = new Barbarian;
				p2 = "Barbarian";
			}
			// start fight loop
			// use while loop with playerHealth > 0
			bool player1Alive = true, player2Alive = true;
			while (player1Alive == true && player2Alive == true)
			{	
				// first player attacks, second player defends
				cout << "Player 1, press enter to attack Player 2!\n";
				cin.ignore(1);
				player2Alive = attackStatus(player1, player2);
				// if fighter is killed, battle is over
				if (player2Alive == false)
				{
					cout << "Player 2's " << p2 << " has fallen in battle!" << endl;
					cout << "Player 1's " << p1 << " wins the battle!" << endl;
					break;
				}
				// second player attacks, first player defends
				cout << "Player 2, press enter to attack Player 1!\n";
				cin.ignore(1);
				player1Alive = attackStatus(player2, player1);
				// if fighter is killed, battle is over
				if (player1Alive == false)
				{
					cout << "Player 1's " << p1 << " has fallen in battle!" << endl;
					cout << "Player 2's " << p2 << " wins the battle!" << endl;
				}
			}
			cout << "Would you like battle again?\nEnter 1 for yes, 2 for no.\n";
			cin >> battle;
			if (battle != 1)
			{
				// delete pointers
				delete[] player1;
				delete[] player2;
				break;
			}
		}
		option = menu();
	}
	return 0;
}

void intro()
{
	cout << "\nWelcome to the Battle Arena!\n";
	cout << "Here only one fighter can be the victor.\n";
	cout << "Each fighter has its own strengths and vulnerabilities but luck is always in play!\n";
}

int fighterChoice()
{
	cout << "Enter the corresponding integer to choose that fighter.\n\n";
	cout << "0. Barbarian - Attack (2d6), Defense (2d6), Armor(0), Strength Points (12)\n\n";
	cout << "1. Blue Men  - Attack (2d10), Defense (3d6), Armor(3), Strength Points (12 *Mob)\n";
	cout << "Mob: Blue Men are actually a swarm of small individuals.\nFor every 4 points of damage, they lose one defense die.\n\n";
	cout << "2. Harry Potter - Attack (2d6), Defense (2d6), Armor(0), Strength Points (10/20 *Hogwarts)\n";
	cout << "Hogwarts: If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20.\nCan only be used once per match.\n\n";
	cout << "3. Medusa - Attack (2d6 *Glare), Defense (1d6), Armor(3), Strength Points (8)\n";
	cout << "Glare: If a Medusa rolls a 12 when attackin, then target instantly gets turned into stone and Medusa wins!\n\n";
	cout << "4. Vampire - Attack (1d12), Defense (1d6 *Charm), Armor(1), Strength Points (18)\n";
	cout << "Charm: Vampires can charm an opponent into not attacking.\n50% chance that their opponent does not actually attack them.\n\n";
	int fighter;
	fighter = getPosInt();
	return fighter;
}

// attack turn - returns bool to check if defending character is still alive
bool attackStatus(Character *attacker, Character* defender)
{
	//   Attacker type.
	string att_str = attacker->showAttack();
	cout << "Attacker: " << att_str << endl;
	//	Defender type, armor, strength point.
	string def_str = defender->showDefense();
	cout << "Defender: " << def_str << endl;
	//	The attacker's attack dice roll.
	int attackerDamage, totalDamage;
	attackerDamage = attacker->attack();
	cout << "Attack Damage: " << attackerDamage << endl;
	if (attackerDamage == 69)
	{
		// medusa's special ability activates if Medusa rolls a 12
		cout << "Medusa's Gaze has turned her opponent to stone!\n";
		return false;
	}
	//	The defender’s defend dice roll.
	int defenderBlock;
	defenderBlock = defender->defend();
	if (defenderBlock == 69)
	{
		// vampire's special ability activates 50% of the time
		cout << "Vampire's Charm has convinced the opponent to not attack!\n";
		cout << "Attack Damage : 0\n";
		attackerDamage = 0;
	}
	else
	{
		int defenderArmor = defender->getArmor();
		cout << "Defender Blocked: " << defenderBlock << endl;
		cout << "Defender Armor: " << defenderArmor << endl;
		//	The total inflicted damage calculation.
		totalDamage = attackerDamage - defenderBlock - defenderArmor;
		if (totalDamage < 0)
		{
			totalDamage = 0;
		}
		cout << "Total Damage = Attack Damage - Defender Block - Defender Armor" << endl;
		cout << "Total Damage: " << totalDamage << endl;

		//	The defender’s updated strength point amount after subtracting damage.
		defender->takeDamage(totalDamage);
	}
	int defenderStrPts = defender->getStrengthPts();
	cout << "Total Defender Strength Points = Strength Points - Total Damage" << endl;
	cout << "Total Defender Strength Points: " << defenderStrPts << endl << endl;
	// if defender dies from hit then defender loses match
	if (defenderStrPts <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
