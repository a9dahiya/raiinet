#ifndef FIREWALL_H
#define FIREWALL_H

#include <memory>
#include <vector>
#include "Ability.h"
class Cell;
class GameState;
class Player;

class Firewall : public Ability {
public:
    void execute(Game* game, const std::vector<std::string>& para) override;

private:
    std::shared_ptr<Cell> targetCell;
};

#endif // FIREWALL_H
