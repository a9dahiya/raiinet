#include "LinkBoost.h"

void LinkBoost::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return;
    }
    targetLink->setLinkBoost();
}

LinkBoost::LinkBoost(shared_ptr<Ability> ability, shared_ptr<Link> link): ability{ability}, link{link} {}