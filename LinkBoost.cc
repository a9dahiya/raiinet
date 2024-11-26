#include "LinkBoost.h"
#include "Link.h"

void LinkBoost::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return;
    }
    targetLink->setLinkBoost();
}

LinkBoost::LinkBoost(shared_ptr<Ability> ability, shared_ptr<Link> link): Ability{ability->getName(), ability->getId(), ability->getOwner()},targetLink{link} {}