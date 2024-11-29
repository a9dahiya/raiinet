#include "UnlimitedVoid.h"
#include <iostream>
#include "board.h"

using namespace std;

UnlimitedVoid::UnlimitedVoid(string name, int id, shared_ptr<Player> owner)
    : Ability{name, id, owner}, playerLink{nullptr}, opponentLink{nullptr} {}

bool UnlimitedVoid::execute(shared_ptr<GameState> game) {
    if(!playerLink || !opponentLink){
        return false;
    }
    auto board = game->GetBoard();
    auto result = board->tatake(playerLink, opponentLink);
    setUsed();  

    
    cout << "Through Heaven and Earth, Link " << result->getLetter()  << " alone is the Honoured One" << std::endl;
    return true;
}

void UnlimitedVoid::setMyLink(shared_ptr<Link> link){
    playerLink = link;
}

void UnlimitedVoid::setOppLink(shared_ptr<Link> link){
    opponentLink = link;
}
