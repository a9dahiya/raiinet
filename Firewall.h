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
    void execute(shared_ptr<GameState> game) override;
    Firewall(std::shared_ptr<Ability> ability, std::shared_ptr<Cell> cell);
};

#endif // FIREWALL_H
