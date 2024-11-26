#ifndef FIREWALL_H
#define FIREWALL_H

#include <memory>
#include <vector>
#include "Ability.h"
#include "Cell.h"
#include "GameState.h"
#include "GameState.h"
#include "Player.h"
using namespace std;

class Firewall : public Ability {
    std::shared_ptr<Cell> targetCell;
    public:
    virtual void execute(shared_ptr<GameState> game) override;
    Firewall(shared_ptr<Ability> ability, shared_ptr<Cell> targetCell);
};

#endif // FIREWALL_H
