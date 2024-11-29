#include "BattleGod.h"
#include "Link.h"

// Executes the BattleGod ability, marking the target link as a "BattleGod" if valid.
// Inputs: shared_ptr<GameState> game - The current game state.
// Outputs: Returns true if successfully executed; false otherwise.
// Time Complexity: O(1)
bool BattleGod::execute(shared_ptr<GameState> game) {
    if (isUsed()) {
        return false;
    }
    if (!targetLink) return false;
    targetLink->setBattleGod();
    setUsed();
    return true;
}

// Constructs a BattleGod ability object with name, ID, owner, and initializes the target link to nullptr.
// Inputs: string name, int id, shared_ptr<Player> owner
// Outputs: None
// Time Complexity: O(1)
BattleGod::BattleGod(string name, int id, shared_ptr<Player> owner)
    : Ability{name, id, owner}, targetLink{nullptr} {}

// Sets the target link for the BattleGod ability.
// Inputs: shared_ptr<Link> link - The target link to mark as BattleGod.
// Outputs: None
// Time Complexity: O(1)
void BattleGod::setTargetLink(shared_ptr<Link> link) {
    targetLink = link;
}
