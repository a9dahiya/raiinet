#include "LinkBoost.h"
#include "Link.h"

bool LinkBoost::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return false;
    }
    if(!targetLink){
        return false;
    }
    targetLink->setLinkBoost();
    setUsed();
    return true;
}

LinkBoost::LinkBoost(string name, int id, shared_ptr<Player> owner)
: Ability{name, id, owner},targetLink{nullptr} {}

void LinkBoost::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
