#include "RussianRoulette.h"
#include <random>
#include "Player.h"
#include "GameState.h"

RussianRoulette::RussianRoulette(string name, int id, shared_ptr<Player> owner)
    : Ability{name, id, owner}, targetLink{nullptr} {}

void RussianRoulette::execute(std::shared_ptr<GameState> game) {
    auto players = game->getPlayers();
    std::random_device rd;                        
    std::mt19937 gen(rd());                
    std::uniform_int_distribution<> dist(0, players.size() - 1);

    int randomIndex = dist(gen);           
    auto chosenPlayer = players[randomIndex];     

    chosenPlayer->downloadLink(targetLink);  
    setUsed();   
}

void RussianRoulette::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
