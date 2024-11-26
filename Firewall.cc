#include "Firewall.h"
using namespace std;
#include "Firewall.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"

Firewall::Firewall(shared_ptr<Ability> ability, shared_ptr<Cell> cell): 
    Ability{ability}, targetCell{cell} {}

void Firewall::execute(std::shared_ptr<GameState> game) {
    auto board = game->GetBoard();
    auto cellPos = targetCell->getPos();
    auto currentPlayer = game->GetCurrentPlayer();

    if (isUsed()) return;
    if (targetCell->getLink() != nullptr) return;
   
    if (board->isOppServer(cellPos, currentPlayer) || board->isOppServer(cellPos, game->GetNextPlayer())) return;
    targetCell->setFirewall(std::shared_ptr<Firewall>(this));
    setUsed();
    


}