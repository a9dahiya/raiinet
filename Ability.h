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
    virtual void execute(shared_ptr<GameState> game) = 0;
    bool isUsed();
    void setUsed();
    string getName();
    shared_ptr<Player> getOwner();
    int getId();
    virtual ~Ability() = default;
    virtual void setTargetCell(shared_ptr<Cell> cell) = 0;
    virtual void setTargetLink(shared_ptr<Link> link) = 0;
    virtual void setMyLink(shared_ptr<Link> link) = 0;
    virtual void setOppLink(shared_ptr<Link> link) = 0;
};

#endif // ABILITY_H
