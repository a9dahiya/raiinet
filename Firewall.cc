#include "Firewall.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"
#include "Cell.h"

Firewall::Firewall(string name, int id, shared_ptr<Player> owner): 
    Ability{name, id, owner}, targetCell{nullptr} {}

bool Firewall::execute(std::shared_ptr<GameState> game) {
    auto board = game->GetBoard();
    auto cellPos = targetCell->getPos();
    auto currentPlayer = game->GetCurrentPlayer();

    if (isUsed()) return false;
    if (targetCell->getLink() != nullptr) return false;
    if (targetCell->isFirewall()) return false;
   
    if (board->isOppServer(cellPos, currentPlayer) || board->isOppServer(cellPos, game->GetNextPlayer())) return false;
    targetCell->setFirewall(std::shared_ptr<Firewall>(this));
    setUsed();
    return true;
    
}

void Firewall::setTargetCell(shared_ptr<Cell> cell){
    targetCell = cell;
}


void Firewall::setTargetLink(shared_ptr<Link> link) {
    // Firewall does not use target links, so this can remain empty
}

void Firewall::setMyLink(shared_ptr<Link> link) {
    // Firewall does not use my links, so this can remain empty
}

void Firewall::setOppLink(shared_ptr<Link> link) {
    // Firewall does not use opponent links, so this can remain empty
}