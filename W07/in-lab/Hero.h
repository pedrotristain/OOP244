/*
	Name:		  Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		  SHH

	Workshop:	07
*/

#include <iostream>
using namespace std;

// Header file guard
#ifndef SICT_HERO_H
#define SICT_HERO_H

// TODO: create namespace
namespace sict {

  const int name_max_length = 40; // Set the max name length
  const int max_rounds = 100; // Max number of rounds on a Hero battle.

	// Class Hero that will hold the data and functions of a Hero object.
	class Hero {
    char name[name_max_length + 1]; // Name of the hero
    int health; // Health of the hero.
    int attack; // Hero attack power.
	public:
		Hero(); // Default constructor. Set the object to a safe empty state.
    Hero(char const*, int, int); // 3 Parameter constructor. Set the object member variables to the received parameters if valid, or to a safe empty state otherwise.
    void operator-=(int); // Operator subtract and assign overload
    bool isAlive() const; // A query function that tells if the Hero is alive
    int attackStrength() const; // A query function that tells the attack strength of a hero or if it is in a safe empty state.

    friend ostream& operator<<(ostream&, const Hero&); // Friend helper function that display the current hero or 'No hero' if the object is in a safe empty state.
	};

  const Hero& operator*(const Hero&, const Hero&); // Helper function that execute a battle for a defined max number of rounds and return the winner.

} // end namespace sict
#endif
