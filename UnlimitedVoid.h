#ifndef UNLIMITED_VOID_H
#define UNLIMITED_VOID_H

#include <memory>
#include "Ability.h"
#include "GameState.h"
#include "Link.h"

using namespace std;

class UnlimitedVoid : public Ability {
    shared_ptr<Link> playerLink;   
    shared_ptr<Link> opponentLink; 

public:

    UnlimitedVoid(string name, int id, shared_ptr<Player> owner);
    bool execute(std::shared_ptr<GameState> game) override;
    void setMyLink(shared_ptr<Link> link) override;
    void setOppLink(shared_ptr<Link> link) override;

};

#endif // UNLIMITED_VOID_H
