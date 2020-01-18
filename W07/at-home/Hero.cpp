/*
	Name:		  Pedro Zelada Souza
	Student#:	116427188
	E-mail:		pzelada-souza@myseneca.ca
	Sect:		  SHH

	Workshop:	07
*/

// Header files
#include "Hero.h"
#include <iostream>
#include <cstring>

using namespace std; // Namespace for the COUT object.

namespace sict {

	// Default constructor. Set the object to a safe empty state.
	Hero::Hero() {

		name[0] = '\0';
    health = -1;
    attack = -1;

	} // end Hero::Hero()

  // 3 Parameters constructor. Sets the member variables to the received data if valid or set the object to a safe empty state otherwise.
  Hero::Hero(char const* par_name, int par_health, int par_attack){
    bool valid = true; // Control variable that will tell if the received parameters are valid.

    // If the received name is empty, set the control variable to false.
    if(par_name == nullptr || strcmp(par_name, "") == 0){
      valid = false;
    } // end if

    // If received health value or attack value is not positive, set the control variable to false.
    if( par_health < 1 || par_attack < 1){
      valid = false;
    } // end if

    // If received data is valid, initialized the object with received data.
    if( valid == true){
      // Set the Hero name
      strncpy(name, par_name, name_max_length);
      name[name_max_length + 1] = '\0';
      // Set the Hero health.
      health = par_health;
      // Set the Hero attack.
      attack = par_attack;
    } else {
      // If any data received is invalid, initialize the object at a safe empty state.
      *this = Hero();
    } // end else
  } // end Hero::Hero(char*, int, int)

  // Subtraction and assign operator overload.
  void Hero::operator-=(int par_attack){
    // Check if the received attack value is positive. If not, this function does nothing.
    if(par_attack > 0){
      // Reduce the current Hero health by the attack value.
      health -= par_attack;

      // If health is negative, set it to 0.
      if(health < 0){
        health = 0;
      } // end if(health)
    } // end if(par_attack)

  } // end Hero::operator-=

  // A query that tells if the Hero is alive. Returns true if the current Hero's health is positive and false otherwise.
  bool Hero::isAlive() const{
    // Return true if the Hero health is positive or false otherwise.
    return (health > 0) ? true : false;
  } // end Hero::isAlive()

  // A query that returns a Hero attack strength.
  int Hero::attackStrength() const{
    return attack;
  } // end Hero::attackStrength()

  // Friend helper function that insert the received Hero's name into stream 'os' and returns a refernce to that stream.
  // If the received Hero is in a safe empty state, display 'No hero'.
  ostream& operator<<(ostream& os, const Hero& hero){
    // Check if the Hero is in a safe empty state (Health < 0).
    if(hero.health < 0){
      // If in a safe empty state, add No hero to the os stream.
      os << "No hero";
    } else {
      // If not in a safe empty state, add the Hero name to the os stream.
      os << hero.name;
    } // end else

    return os; // Return the os stream
  } // end operator<<(ostream&, const Hero&)

  // A functon that will execute a battle between two Heroes and return the winner.
  const Hero& operator*(const Hero& first, const Hero& second){

    Hero left = first; // Copy the first hero to manipulate the battle damage
    Hero right = second; // Copy the second hero to manipulate the battle damage
    int winner; // Temporary variable that will tell which Hero was the winner.

    int rounds = 0; // Rounds counter to tell how many rounds it took to end the battle.

    for( int i = 0; i < max_rounds; i++){
      // Both Heroes attack each other.
      right -= left.attackStrength();
      left -= right.attackStrength();

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
    cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << ((winner == 1) ? first : second) << " in " << rounds << " rounds." << endl;

    return (winner == 1) ? first : second; // Return the winner Hero
  } // end Hero& operator*

} // end namespace sict
