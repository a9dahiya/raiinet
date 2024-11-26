#include "UnlimitedVoid.h"
#include <iostream>
#include "board.h"

using namespace std;

UnlimitedVoid::UnlimitedVoid(string name, int id, shared_ptr<Player> owner)
    : Ability{name, id, owner}, playerLink{nullptr}, opponentLink{nullptr} {}

void UnlimitedVoid::execute(shared_ptr<GameState> game) {

    auto board = game->GetBoard();
    auto result = board->tatake(playerLink, opponentLink);

    
    cout << "Through Heaven and hell the honoured one is " << result->getName() << std::endl;
}

void UnlimitedVoid::setMyLink(shared_ptr<Link> link){
    playerLink = link;
}

void UnlimitedVoid::setOppLink(shared_ptr<Link> link){
    opponentLink = link;
}
