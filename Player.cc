#include "Player.h"

Player::Player(string name, vector<shared_ptr<Link>> myLinks, vector<shared_ptr<Ability>> Abilities,
     int downloadedData, int downloadedVirus, int abilitiesLeft, vector<Position> serverPorts) 
     : name{name}, myLinks{myLinks}, Abilities{Abilities}, downloadedData{downloadedData}, downloadedVirus{downloadedVirus},
     abilitiesLeft{abilitiesLeft}, vector<Position> serverPorts{serverPorts} {}


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
    if (link->getIsData()){
        downloadedData++;
    }
    else{
        downloadedVirus++;
    }
}

shared_ptr<Link> Player::getLink(char id){
    for (auto i : myLinks){
        if (id == i->getName()){
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
