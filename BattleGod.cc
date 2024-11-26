#include "BattleGod.h"
#include "Link.h"

void BattleGod::execute(shared_ptr<GameState> game){
    targetLink->setBattleGod();
}

BattleGod::BattleGod(shared_ptr<Ability> ability, shared_ptr<Link> link): Ability{ability->getName(), ability->getId(), ability->getOwner()}, targetLink{link} {}