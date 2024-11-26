#include "Polarize.h"
using namespace std;
#include "Ability.h"
#include "board.h"
#include "GameState.h"

Polarize::Polarize(std::shared_ptr<Ability> ability, std::shared_ptr<Link> li):
    Ability{ability},targetLink{li} {}

void Polarize::execute(shared_ptr<GameState> game) {
    targetLink->switchType();
}