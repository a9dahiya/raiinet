#include "Scan.h"
#include "Link.h"

void Scan::execute(shared_ptr<GameState> game){
    targetLink->setRevealed();
}

Scan::Scan(string name, int id, shared_ptr<Player> owner):
 Ability{name, id, owner}, targetLink{nullptr} {}

void Scan::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
