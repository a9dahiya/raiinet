#include "Ability.h"
#include "Player.h"
#include "GameState.h"

using namespace std;

// Initializes an Ability object (constructor)
// Inputs:
//   - string name: Name of the ability.
//   - int id: Unique identifier for the ability.
//   - shared_ptr<Player> Owner: The player owning this ability.
// Outputs: Constructs an Ability with the provided name, id, and owner.
// Time Complexity: O(1)
Ability::Ability(string name, int id, shared_ptr<Player> Owner): name{name}, id{id}, Owner{Owner} {}

// Checks if the ability has been used.
// Outputs: Returns true if the ability is marked as used; otherwise, false.
// Time Complexity: O(1)
bool Ability::isUsed(){
    return used;
}

// Marks the ability as used.
// Outputs: Updates the ability's state to indicate it has been used.
// Time Complexity: O(1)
void Ability::setUsed(){
    used = true;
}

// Retrieves the name of the ability.
// Outputs: Returns the name of the ability.
// Time Complexity: O(1)
string Ability::getName(){
    return name;
}

// Retrieves the owner of the ability.
// Outputs: Returns a shared pointer to the owning player.
// Time Complexity: O(1)
shared_ptr<Player> Ability::getOwner(){
    return Owner;
}

// Retrieves the unique identifier of the ability.
// Outputs: Returns the id of the ability.
// Time Complexity: O(1)
int Ability::getId(){
    return id;
}

//Sets the target cell for the ability
void Ability::setTargetCell(shared_ptr<Cell> cell){}

// Sets the target link for the ability
void Ability::setTargetLink(shared_ptr<Link> link){}

// Sets one of the player's own links as the target
void Ability::setMyLink(shared_ptr<Link> link){}

// Sets one of the opponent's links as the target
void Ability::setOppLink(shared_ptr<Link> link){}
