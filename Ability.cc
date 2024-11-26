#include "Ability.h"
#include "Player.h"
#include "GameState.h"

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

void Ability::setTargetCell(shared_ptr<Cell> cell){}

void Ability::setTargetLink(shared_ptr<Link> link){}

void Ability::setMyLink(shared_ptr<Link> link){}

void Ability::setOppLink(shared_ptr<Link> link){}
