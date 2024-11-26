#include "Polarize.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"
#include "Link.h"

using namespace std;

Polarize::Polarize(string name, int id, shared_ptr<Player> owner):
    Ability{name, id, owner}, targetLink{nullptr} {}

void Polarize::execute(shared_ptr<GameState> game) {
    targetLink->switchType();
}

void Polarize::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
