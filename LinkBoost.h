#ifndef LINKBOOST_H
#define LINKBOOST_H

#include <memory>
#include <vector>
#include "Ability.h"
#include "Link.h"
using namespace std;

class LinkBoost : public Ability {
    shared_ptr<Link> targetLink;
public:
    void execute(shared_ptr<GameState> game) override;
    LinkBoost(string name, int id, shared_ptr<Player> owner);
    void setTargetLink(shared_ptr<Link> link) override;
};

#endif // LINKBOOST_H