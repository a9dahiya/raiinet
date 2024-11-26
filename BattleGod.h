#ifndef BATTLEGOD_H
#define BATTLEGOD_H

#include <memory>
#include "Ability.h"


class BattleGod : public Ability {
    std::shared_ptr<Link> targetLink;
public:
    void execute(shared_ptr<GameState> game) override;
    BattleGod(shared_ptr<Ability> ability, shared_ptr<Link> link);
    // YASHILA IS OVER HERE AND DISHAS BD IS HERE AND SHE DIDNT INVITE HER WHAT DO U WANNA 
    // 2 options, we can invite her to the daru party honestly, or we just vibes
};

#endif // BATTLEGOD_H