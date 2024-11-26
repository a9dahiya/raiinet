#include "Ability.h"
#include <memory>
#include <string>
#include "Player.h"
using namespace std;

Ability::Ability(string name, int id, shared_ptr<Player> Owner): name{name}, id{id}, Owner{Owner} {}

bool Ability::isUsed(){
    return used;
}

void Ability::setUsed(){
    used = true;
}

string Ability::getName(){
    return name;
}

shared_ptr<Player> Ability::getOwner(){
    return Owner;
}

int Ability::getId(){
    return id;
}

Ability(const Ability& baseAbility) : name{baseAbility.name()}, 
id{baseAbility.id()}, Owner{baseAbility.Owner}, used{baseAbility.used}{}

