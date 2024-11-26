#ifndef BATTLEGOD_H
#define BATTLEGOD_H

#include <memory>
#include "Ability.h"
#include "Link.h"


class BattleGod : public Ability {
    std::shared_ptr<Link> targetLink;
public:
    void execute(shared_ptr<GameState> game) override;
    BattleGod(shared_ptr<Ability> ability, shared_ptr<Link> link);
};

#endif // BATTLEGOD_H