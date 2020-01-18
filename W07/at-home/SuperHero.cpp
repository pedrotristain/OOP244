/*
	Name:		  Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		  SHH

	Workshop:	07
*/

// Header files
#include "SuperHero.h"
#include <iostream>
#include <cstring>

using namespace std; // Namespace for the COUT object.

namespace sict {

	// Default constructor. Set the object to a safe empty state.
	SuperHero::SuperHero() {
    super_power = -1;
    defense = -1;
	} // end SuperHero::SuperHero()

  // 5 Parameters constructor.
  // Sets the member variables to the received data if valid or set the object to a safe empty state otherwise.
  SuperHero::SuperHero(char const* par_name, int par_health, int par_attack, int par_super_power, int par_defense) : Hero(par_name, par_health, par_attack){
    bool valid = true; // Control variable that will tell if the received parameters are valid.

    // If received super power or defense value is not positive, set the control variable to false.
    if( par_super_power < 1 || par_defense < 1){
      valid = false;
    } // end if

    // If received data is valid, initialized the object with received data.
    if( valid == true){
      // Set the Super Hero super power strength.
      super_power = par_super_power;
      // Set the Super Hero defense strength.
      defense = par_defense;
    } else {
      // If any data received is invalid, initialize the object at a safe empty state.
      *this = SuperHero();
    } // end else
  } // end SuperHero::SuperHero(char*, int, int, int, int)

  // A query that returns a Super Hero total attack strength.
  // A Super Hero total attack strength is equal to its attack strength + super power strength.
  int SuperHero::attackStrength() const{
    // Calculate the total Super Hero strength.
    int total_strength = Hero::attackStrength() + super_power;

    // If the object is in a safe empty state, set the total strength to 0.
    if( super_power < 1 ){
      total_strength = 0;
    } // end if

    // Return the Super Hero total strength.
    return total_strength;
  } // end SuperHero::attackStrength()

  // A query that returns a Super Hero defense strength or 0 in case it is in a safe empty state.
  int SuperHero::defend() const{
    return (defense != -1) ? defense : 0;
  } // end SuperHero::defend()

  // A functon that will execute a battle between two Heroes and return the winner.
  const SuperHero& operator*(const SuperHero& first, const SuperHero& second){

    SuperHero left = first; // Copy the first hero to manipulate the battle damage
    SuperHero right = second; // Copy the second hero to manipulate the battle damage
    int winner; // Temporary variable that will tell which Hero was the winner.

    int rounds = 0; // Rounds counter to tell how many rounds it took to end the battle.

    for( int i = 0; i < max_rounds; i++){
      // Both Heroes attack each other.
      right -= left.attackStrength() - right.defend();
      left -= right.attackStrength() - left.defend();

      // Check if the Left Hero is alive
      // If not, the Winner is the Right hero.
      if(left.isAlive() == false){
        winner = 2;
        i = max_rounds; // Exit the loop
      } else if( right.isAlive() == false) {
        // If the Left Hero is alive, check if the Right Hero is alive.
        // If not, the winner is the Left Hero.
        winner = 1;
        i = max_rounds; // Exit the loop
      } // end else

      rounds++; // Increment the rounds counter.
    } // end for

    // If neither Hero was defeated before the max number of rounds, the winner is the Left hero.
    if(left.isAlive() && right.isAlive()){
      winner = 1;
    } // end if(left && right)

    // Output the Battle Message with the Winner.
    cout << "Super Fight! " << first << " vs " << second << " : Winner is " << ((winner == 1) ? first : second) << " in " << rounds << " rounds." << endl;

    return (winner == 1) ? first : second; // Return the winner Hero
  } // end SuperHero& operator*

} // end namespace sict
