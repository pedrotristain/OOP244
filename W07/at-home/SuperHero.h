/*
	Name:		  Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		  SHH

	Workshop:	07
*/

// Headers
#include <iostream>
#include "Hero.h"
using namespace std;

// Header file guard
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

// Namespace
namespace sict {

	// Class SuperHero that inherits the Hero class and expands with the SuperHero data.
	class SuperHero : public Hero {
    int super_power;
    int defense;
	public:
		SuperHero(); // Default constructor. Set the object to a safe empty state.
    SuperHero(char const*, int, int, int ,int); // 5 Parameter constructor. Set the object member variables to the received parameters if valid, or to a safe empty state otherwise.
    int attackStrength() const; // A query function that returns the attack power of the SuperHero (attack strength + super power strength). It returns 0 if the object is in a safe empty state.
    int defend() const; // A query that return the defense strength of the SuperHero or 0 if the object is in a safe empty state.
	};

  const SuperHero& operator*(const SuperHero&, const SuperHero&); // Helper function that execute a battle for a defined max number of rounds and return the winner.

} // end namespace sict
#endif
