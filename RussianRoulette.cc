#include "RussianRoulette.h"
#include <random>

RussianRoulette::RussianRoulette(std::shared_ptr<Ability> ability, std::shared_ptr<Link> link)
    : Ability(ability), targetLink{link} {}

void RussianRoulette::execute(std::shared_ptr<GameState> game) {
    auto players = game->GetPlayers();
    std::random_device rd;                        
    std::mt19937 gen(rd());                
    std::uniform_int_distribution<> dist(0, players.size() - 1);

    int randomIndex = dist(gen);           
    auto chosenPlayer = players[randomIndex];     

    chosenPlayer->downloadLink(targetLink);     
}
