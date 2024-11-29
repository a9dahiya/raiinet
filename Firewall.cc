#include "Firewall.h"
#include "Ability.h"
#include "board.h"
#include "GameState.h"
#include "Cell.h"


// Constructs a Firewall ability with a name, ID, and owning player.
// Inputs: std::string name - Name of the ability, int id - Unique ID, std::shared_ptr<Player> owner - Owning player.
Firewall::Firewall(std::string name, int id, std::shared_ptr<Player> owner) : 
    Ability{name, id, owner}, targetCell{nullptr} {}

// Executes the Firewall ability to place a firewall in the target cell.
// Inputs: std::shared_ptr<GameState> game - The current game state.
// Outputs: bool - True if successfully executed, false otherwise.
bool Firewall::execute(std::shared_ptr<GameState> game) {
    auto board = game->GetBoard();
    auto cellPos = targetCell->getPos();
    auto currentPlayer = game->GetCurrentPlayer();

    if (isUsed()) return false;
    if (targetCell->getLink() != nullptr) return false;
    if (targetCell->isFirewall()) return false;
    if (board->isOppServer(cellPos, currentPlayer) || 
        board->isOppServer(cellPos, game->GetNextPlayer())) return false;

    targetCell->setFirewall(std::shared_ptr<Firewall>(this));
    setUsed();
    return true;
}

// Sets the target cell for the firewall.
// Inputs: std::shared_ptr<Cell> cell - The cell to set as the target.
// Outputs: None.
void Firewall::setTargetCell(std::shared_ptr<Cell> cell) {
    targetCell = cell;
}

// Sets the target link for the firewall (unused for this ability).
// Inputs: std::shared_ptr<Link> link - The link to set as the target.
// Outputs: None.
void Firewall::setTargetLink(std::shared_ptr<Link> link) {
    // Unused for this ability.
}

// Sets the player's link for the firewall (unused for this ability).
// Inputs: std::shared_ptr<Link> link - The link to set as the player's link.
// Outputs: None.
void Firewall::setMyLink(std::shared_ptr<Link> link) {
    // Unused for this ability.
}

// Sets the opponent's link for the firewall (unused for this ability).
// Inputs: std::shared_ptr<Link> link - The link to set as the opponent's link.
// Outputs: None.
void Firewall::setOppLink(std::shared_ptr<Link> link) {
    // Unused for this ability.
}
