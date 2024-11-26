#include "Scan.h"
#include "Link.h"

void Scan::execute(shared_ptr<GameState> game){
    targetLink->setRevealed();
}

Scan::Scan(shared_ptr<Ability> ability, shared_ptr<Link> link): Ability{ability->getName(), ability->getId(), ability->getOwner()}, targetLink{link} {}