#ifndef LINKBOOST_H
#define LINKBOOST_H

#include <memory>
#include <vector>
#include "Ability.h"
#include "Link.h"
using namespace std;

class LinkBoost : public Ability {
    std::shared_ptr<Link> targetLink;
    public:
    void execute(shared_ptr<GameState> game) override;
    LinkBoost(shared_ptr<Ability> ability, shared_ptr<Link> link);
};

#endif // LINKBOOST_H