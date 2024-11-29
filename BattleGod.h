#ifndef BATTLEGOD_H
#define BATTLEGOD_H

#include <memory>
#include "Ability.h"
#include "Link.h"

using namespace std;

class BattleGod : public Ability {
    shared_ptr<Link> targetLink;
public:
    bool execute(shared_ptr<GameState> game) override;
    BattleGod(string name, int id, shared_ptr<Player> owner);
    void setTargetLink(shared_ptr<Link> link) override;
};

#endif // BATTLEGOD_H