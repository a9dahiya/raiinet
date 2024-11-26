#ifndef FIREWALL_H
#define FIREWALL_H

#include <memory>
#include <vector>
#include "Ability.h"
#include "Cell.h"
#include "GameState.h"
#include "GameState.h"
#include "Player.h"

class Firewall : public Ability {
    std::shared_ptr<Cell> targetCell;
    public:
    void execute(shared_ptr<GameState> game) override;
    Firewall(shared_ptr<Cell> targetCell);
};

#endif // FIREWALL_H
