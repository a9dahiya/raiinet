#ifndef RUSSIAN_ROULETTE_H
#define RUSSIAN_ROULETTE_H

#include <memory>
#include "Ability.h"
#include "Link.h"

using namespace std;

class RussianRoulette : public Ability {
    shared_ptr<Link> targetLink; 

public:
    RussianRoulette(string name, int id, shared_ptr<Player> owner);
    void execute(shared_ptr<GameState> game) override;
    void setTargetLink(shared_ptr<Link> link) override;
};

#endif // RUSSIAN_ROULETTE_H
