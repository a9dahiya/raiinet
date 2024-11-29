#include "UnlimitedVoid.h"
#include <iostream>
#include "board.h"

using namespace std;

// Constructor: Initializes an UnlimitedVoid ability.
// Inputs: string name - The name of the ability,
//         int id - Unique ID of the ability,
//         shared_ptr<Player> owner - The owner of this ability.
UnlimitedVoid::UnlimitedVoid(string name, int id, shared_ptr<Player> owner)
    : Ability{name, id, owner}, playerLink{nullptr}, opponentLink{nullptr} {}

// Executes the UnlimitedVoid ability.
// Inputs: shared_ptr<GameState> game - The current game state.
// Outputs: bool - True if executed successfully, false otherwise.
bool UnlimitedVoid::execute(shared_ptr<GameState> game) {
    // Ensure both player's and opponent's links are set.
    if (!playerLink || !opponentLink) {
        return false;
    }

    // Access the game board and resolve the battle using the `tatakae` method.
    auto board = game->GetBoard();
    auto result = board->tatakae(playerLink, opponentLink);

    // Mark the ability as used.
    setUsed();

    // Output the result of the battle.
    cout << "Through Heaven and Earth, Link " 
         << result->getLetter() 
         << " alone is the Honoured One" << endl;

    return true;
}

// Sets the player's link (attacking link).
// Inputs: shared_ptr<Link> link - The link controlled by the player.
void UnlimitedVoid::setMyLink(shared_ptr<Link> link) {
    playerLink = link;
}

// Sets the opponent's link (defending link).
// Inputs: shared_ptr<Link> link - The link controlled by the opponent.
void UnlimitedVoid::setOppLink(shared_ptr<Link> link) {
    opponentLink = link;
}
