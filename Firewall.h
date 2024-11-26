#ifndef FIREWALL_H
#define FIREWALL_H


using namespace std;

#include <memory>
#include "Ability.h"

// Forward declarations
class Cell;
class GameState;

using namespace std;

class Firewall : public Ability {
    shared_ptr<Cell> targetCell;

public:
    void execute(shared_ptr<GameState> game) override;
    Firewall(string name, int id, shared_ptr<Player> owner);
    void setTargetCell(shared_ptr<Cell> cell) override;
};

#endif // FIREWALL_H
