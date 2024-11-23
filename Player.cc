#include "player.h"

Player::Player(string name, vector<shared_ptr<Link>> myLinks, vector<shared_ptr<Ability>> Abilities,
     int downloadedData, int downloadedVirus, int abilitiesLeft) 
     : name{name}, myLinks{myLinks}, Abilities{Abilities}, downloadedData{downloadedData}, downloadedVirus{downloadedVirus},
     abilitiesLeft{abilitiesLeft} {}