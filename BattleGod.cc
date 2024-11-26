#include "BattleGod.h"
#include "Link.h"

void BattleGod::execute(shared_ptr<GameState> game){
    targetLink->setBattleGod();
    setUsed();
}

BattleGod::BattleGod(string name, int id, shared_ptr<Player> owner): Ability{name, id, owner}, targetLink{nullptr} {}

void BattleGod::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
