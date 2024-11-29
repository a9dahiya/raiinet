#ifndef ABILITY_H
#define ABILITY_H


using namespace std;

#include <memory>
#include <string>

// Forward declarations
class Player;
class GameState;
class Cell;
class Link;

class Ability {
protected:
    string name;
    int id;
    shared_ptr<Player> Owner;
    bool used = false;

public:
    Ability(string name, int id, shared_ptr<Player> Owner);
    virtual bool execute(shared_ptr<GameState> game) = 0;
    bool isUsed();
    void setUsed();
    string getName();
    shared_ptr<Player> getOwner();
    int getId();
    virtual ~Ability() = default;
    virtual void setTargetCell(shared_ptr<Cell> cell);
    virtual void setTargetLink(shared_ptr<Link> link);
    virtual void setMyLink(shared_ptr<Link> link);
    virtual void setOppLink(shared_ptr<Link> link);
};

#endif // ABILITY_H
