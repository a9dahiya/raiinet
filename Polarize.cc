#include "Polarize.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"
#include "Link.h"

using namespace std;

Polarize::Polarize(string name, int id, shared_ptr<Player> owner):
    Ability{name, id, owner}, targetLink{nullptr} {}

bool Polarize::execute(shared_ptr<GameState> game) {
    if(!targetLink){
        return false;
    }
    targetLink->switchType();
    setUsed();
    return true;
}

void Polarize::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
