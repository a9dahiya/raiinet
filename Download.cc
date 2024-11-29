#include "Download.h"
#include "GameState.h"
#include "Player.h"
#include "Link.h"
#include <memory>
#include <string>

// Constructs a Download ability with a name, ID, and owning player.
// Inputs: std::string name - Name of the ability, int id - Unique ID, std::shared_ptr<Player> owner - Owning player.
Download::Download(std::string name, int id, std::shared_ptr<Player> owner) : 
    Ability{name, id, owner}, targetLink{nullptr} {}

// Executes the download ability.
// Inputs: std::shared_ptr<GameState> game - The current game state.
// Outputs: bool - True if successfully executed, false otherwise.
bool Download::execute(std::shared_ptr<GameState> game) {
    if (isUsed()) return false;
    if (!targetLink) return false;

    game->GetCurrentPlayer()->downloadLink(targetLink);
    setUsed();
    return true;
}

// Sets the target link for the download.
// Inputs: std::shared_ptr<Link> link - The link to set as the target.
// Outputs: None.
void Download::setTargetLink(std::shared_ptr<Link> link) {
    targetLink = link;
}
