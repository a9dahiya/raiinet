#include "BattleGod.h"
#include "Link.h"

bool BattleGod::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return false;
    }
    if(!targetLink) return false;
    targetLink->setBattleGod();
    setUsed();
    return true;
}

BattleGod::BattleGod(string name, int id, shared_ptr<Player> owner): Ability{name, id, owner}, targetLink{nullptr} {}

void BattleGod::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
