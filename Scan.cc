#include "Scan.h"
#include "Link.h"

bool Scan::execute(shared_ptr<GameState> game){
    if(!targetLink){
        return false;
    }
    targetLink->setRevealed();
    setUsed();  
    return true;
}

Scan::Scan(string name, int id, shared_ptr<Player> owner):
 Ability{name, id, owner}, targetLink{nullptr} {}

void Scan::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
