#ifndef UNLIMITED_VOID_H
#define UNLIMITED_VOID_H

#include <memory>
#include "Ability.h"
#include "GameState.h"
#include "Link.h"

class UnlimitedVoid : public Ability {
    std::shared_ptr<Link> playerLink;   
    std::shared_ptr<Link> opponentLink; 

public:

    UnlimitedVoid(std::shared_ptr<Ability> ability, std::shared_ptr<Link> playerLink, std::shared_ptr<Link> opponentLink);
    void execute(std::shared_ptr<GameState> game) override;
};

#endif // UNLIMITED_VOID_H
