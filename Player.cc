#include "Player.h"

Player::Player(string name, vector<shared_ptr<Link>> myLinks, vector<shared_ptr<Ability>> Abilities,
     int downloadedData, int downloadedVirus, int abilitiesLeft) 
     : name{name}, myLinks{myLinks}, Abilities{Abilities}, downloadedData{downloadedData}, downloadedVirus{downloadedVirus},
     abilitiesLeft{abilitiesLeft} {
            
     } //implement fully


vector<shared_ptr<Link>> Player::getAllLinks(){
    return myLinks;
}

vector<shared_ptr<Ability>> Player::getAbilities(){
    return Abilities;
}

string Player::getName(){
    return name;
}