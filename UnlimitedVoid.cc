#include "UnlimitedVoid.h"

UnlimitedVoid::UnlimitedVoid(std::shared_ptr<Ability> ability, std::shared_ptr<Link> playerLink, std::shared_ptr<Link> opponentLink)
    : Ability(ability), playerLink{playerLink}, opponentLink{opponentLink} {}

void UnlimitedVoid::execute(std::shared_ptr<GameState> game) {

    auto board = game->GetBoard();
    auto result = board->tatake(playerLink, opponentLink);

    
    std::cout << "Through Heaven and hell the honoured one is " << result->getName() << std::endl;
}