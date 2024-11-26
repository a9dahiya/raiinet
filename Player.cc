#include "Player.h"
#include "Link.h"
#include "Ability.h"
#include "Position.h"

Player::Player(string name) : name{name} {}


vector<shared_ptr<Link>> Player::getAllLinks(){
    return myLinks;
}

vector<shared_ptr<Ability>> Player::getAbilities(){
    return Abilities;
}

string Player::getName(){
    return name;
}

int Player::numAbilityLeft(){
    return abilitiesLeft;
}

int Player::getData(){
    return downloadedData;
}

int Player::getVirus(){
    return downloadedVirus;
}

void Player::downloadLink(std::shared_ptr<Link> link){
    if (link->isData()){
        downloadedData++;
    }
    else{
        downloadedVirus++;
    }
}

shared_ptr<Link> Player::getLink(char id){
    for (auto i : myLinks){
        if (id == i->getLetter()){
            return i;
        }
    }
}

bool Player::isOwnLink(shared_ptr<Link> link){
    for (auto i : myLinks){
        if (i == link){
            return true;
        }
    }
    return false;
}

void Player::setServerPort(Position pos){
    serverPorts.emplace_back(pos);
}

bool Player::isOwnServerPort(Position pos){
    for (auto i : serverPorts){
        if (pos == i){
            return true;
        }
    }
    return false;
}

void Player::addLink(shared_ptr<Link> link){
    myLinks.emplace_back(link);
}

void Player::addAbility(shared_ptr<Ability> ability){
    Abilities.emplace_back(ability);
    abilitiesLeft++;
}

bool Player::operator!=(shared_ptr<Player> other){
    return (name != other->getName());
}
