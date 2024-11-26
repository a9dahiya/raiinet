#ifndef ABILITY_H
#define ABILITY_H

#include <memory>
#include <string>
#include <vector>
#include "Player.h"
#include "GameState.h"

using namespace std;


class Ability {
public:
    Ability(string name, int id, shared_ptr<Player> Owner);
    virtual void execute(shared_ptr<GameState> game) = 0;
    bool isUsed();
    void setUsed();
    std::string getName();
    int getId();

private:
    string name;
    int id;
    shared_ptr<Player> Owner;
    bool used = false;
};

#endif // ABILITY_H
