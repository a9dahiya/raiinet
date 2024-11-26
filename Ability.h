#ifndef ABILITY_H
#define ABILITY_H

#include <memory>
#include <string>
#include <vector>
#include "Player.h"
#include "GameState.h"

using namespace std;


class Ability {
    string name;
    int id;
    shared_ptr<Player> Owner;
    bool used = false;

public:
    Ability(string name, int id, shared_ptr<Player> Owner);
    Ability(const Ability& baseAbility);
    virtual void execute(shared_ptr<GameState> game) = 0;
    bool isUsed();
    void setUsed();
    string getName();
    shared_ptr<Player> getOwner();
    int getId();
};

#endif // ABILITY_H
