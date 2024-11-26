#include "Firewall.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"
#include "Cell.h"

Firewall::Firewall(string name, int id, shared_ptr<Player> owner): 
    Ability{name, id, owner}, targetCell{nullptr} {}

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

void Firewall::setTargetCell(shared_ptr<Cell> cell){
    targetCell = cell;
}