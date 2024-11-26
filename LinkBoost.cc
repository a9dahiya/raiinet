#include "LinkBoost.h"
#include "Link.h"

void LinkBoost::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return;
    }
    targetLink->setLinkBoost();
    setUsed();
}

LinkBoost::LinkBoost(string name, int id, shared_ptr<Player> owner)
: Ability{name, id, owner},targetLink{nullptr} {}

void LinkBoost::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}