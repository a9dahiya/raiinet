#ifndef FIREWALL_H
#define FIREWALL_H


using namespace std;

#include <memory>
#include "Ability.h"

// Forward declarations
class Cell;
class GameState;

class Firewall : public Ability {
    std::shared_ptr<Cell> targetCell;
    public:
    void execute(shared_ptr<GameState> game) override;
    Firewall(shared_ptr<Ability> ability, shared_ptr<Cell> cell);
};

#endif // FIREWALL_H
