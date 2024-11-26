#include "Polarize.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"
#include "Link.h"

using namespace std;

Polarize::Polarize(std::shared_ptr<Ability> ability, std::shared_ptr<Link> li):
    Ability{ability->getName(), ability->getId(), ability->getOwner()},targetLink{li} {}

void Polarize::execute(shared_ptr<GameState> game) {
    targetLink->switchType();
}