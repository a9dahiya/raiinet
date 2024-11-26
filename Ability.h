#ifndef ABILITY_H
#define ABILITY_H


using namespace std;

#include <memory>
#include <string>

// Forward declarations
class Player;
class GameState;

class Ability {
protected:
    string name;
    int id;
    shared_ptr<Player> Owner;
    bool used = false;

public:
    Ability(string name, int id, shared_ptr<Player> Owner);
    virtual void execute(shared_ptr<GameState> game);
    bool isUsed();
    void setUsed();
    string getName();
    shared_ptr<Player> getOwner();
    int getId();
};

#endif // ABILITY_H
