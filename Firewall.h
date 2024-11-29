#ifndef FIREWALL_H
#define FIREWALL_H

using namespace std;

#include <memory>
#include "Ability.h"

// Forward declarations
class Cell;
class GameState;

class Firewall : public Ability {
    shared_ptr<Cell> targetCell;

public:
    Firewall(string name, int id, shared_ptr<Player> owner);

    // Override virtual functions
    bool execute(shared_ptr<GameState> game) override;
    void setTargetCell(shared_ptr<Cell> cell) override;
    void setTargetLink(shared_ptr<Link> link) override;
    void setMyLink(shared_ptr<Link> link) override;
    void setOppLink(shared_ptr<Link> link) override;
};

#endif // FIREWALL_H
