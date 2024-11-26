#ifndef RUSSIAN_ROULETTE_H
#define RUSSIAN_ROULETTE_H

#include <memory>
#include "Ability.h"
#include "Link.h"

using namespace std;

class RussianRoulette : public Ability {
    std::shared_ptr<Link> targetLink; 

public:
    RussianRoulette(std::shared_ptr<Ability> ability, std::shared_ptr<Link> link);
    void execute(std::shared_ptr<GameState> game) override;
};

#endif // RUSSIAN_ROULETTE_H
