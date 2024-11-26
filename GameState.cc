#include "GameState.h"
#include "board.h"
#include "Player.h"
#include "Link.h"
#include "Position.h"
#include "Ability.h"
#include "Firewall.h"
#include "Polarize.h"
#include "Scan.h"
#include "Download.h"
#include "LinkBoost.h"
#include "BattleGod.h"
#include "UnlimitedVoid.h"
#include "RussianRoulette.h"


using namespace std;

GameState::GameState(const vector<shared_ptr<Player>> players): players{players}, board{make_shared<Board>(players)} {}

bool GameState::isAbilityUsed(){
    return abilityUsed;
}

void GameState::HasWon() {
    for (auto it = players.begin(); it != players.end();) {
        if ((*it)->getVirus() == 4) {
            it = players.erase(it);
        } else {
            if ((*it)->getData() == 4) {
                setWinner(*it);
                GameOver = true;
                return; 
            }
            ++it;
        }
    }

    if (players.size() == 1) {
        setWinner(players.front());
        GameOver = true;
    }
}

shared_ptr<Board> GameState::GetBoard(){
        return board;
}

std::vector<std::shared_ptr<Player>> GameState::getPlayers(){
    return players;
}

void GameState::setWinner(std::shared_ptr<Player> player){
    winner = player;
}

shared_ptr<Player> GameState::GetWinner(){
    return winner;
}

bool GameState::isGameOver(){
    return GameOver;
}

void GameState::NextTurn(){
    PlayerTurn = (PlayerTurn + 1) % (players.size());
    abilityUsed = false;
}

shared_ptr<Player> GameState::GetCurrentPlayer(){
    return players[PlayerTurn];
}
shared_ptr<Player> GameState::GetNextPlayer(){
    return players[PlayerTurn + 1];
}

void GameState::moveLink(char linkId, const string& Dir){
    shared_ptr<Player> player = GetCurrentPlayer();
    shared_ptr<Link> link = player->getLink(linkId);
    
    int dist = 1;
    if(link->getLinkBoost()){
        dist = 2;
    }
    Position from = link->getPos();
    Position to = link->getNewPos(Dir, dist);
    if(!(GetBoard()->ValidMove(from, to, player))){
        //ur mom type shi
    }
    
    GetBoard()->moveLink(link, from, to, shared_ptr<GameState>(this));
    
}

void GameState::ExecuteAbility(int AbilityId, istream& in){
    if(isAbilityUsed()){
        // Ability already used in turn
    }else{
        shared_ptr<Player> player = GetCurrentPlayer();
        vector<shared_ptr<Ability>> abilities = player->getAbilities();
        if( !(abilities[AbilityId]->isUsed()) ){
            string name = abilities[AbilityId]->getName();
            if(name == "Firewall"){
                int row, col;
                in >> row >> col;
                Position pos{row, col};
                shared_ptr<Cell> cell = GetBoard()->getCell(pos);
                shared_ptr<Firewall> firewall = make_shared<Firewall>(abilities[AbilityId], cell);
                firewall->execute( shared_ptr<GameState>(this) );
            }else if(name == "Polarize"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                shared_ptr<Polarize> polarize = make_shared<Polarize>(abilities[AbilityId], target_link);
                polarize->execute( shared_ptr<GameState>(this) );
            }else if(name == "Download"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetNextPlayer()->getLink(link);
                shared_ptr<Download> download = make_shared<Download>(abilities[AbilityId], target_link);
                download->execute(shared_ptr<GameState>(this) );
            }else if(name == "Scan"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetNextPlayer()->getLink(link);
                shared_ptr<Scan> scan = make_shared<Scan>(abilities[AbilityId], target_link);
                scan->execute(shared_ptr<GameState>(this));
            }else if(name == "Link Boost"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                shared_ptr<LinkBoost> linkBoost = make_shared<LinkBoost>(abilities[AbilityId], target_link);
                linkBoost->execute(shared_ptr<GameState>(this));
            }else if(name == "Russian Roulette"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                shared_ptr<RussianRoulette> russianRoulette = make_shared<RussianRoulette>(abilities[AbilityId], target_link);
                russianRoulette->execute(shared_ptr<GameState>(this));
            }else if(name == "Battle God"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                shared_ptr<BattleGod> battleGod = make_shared<BattleGod>(abilities[AbilityId], target_link);
                battleGod->execute(shared_ptr<GameState>(this));
            }else if(name == "Unlimited Void"){
                char attacker, defender;
                in >> attacker >> defender;
                shared_ptr<Link> attacking_link = GetCurrentPlayer()->getLink(attacker);
                shared_ptr<Link> defending_link = GetNextPlayer()->getLink(defender);
                shared_ptr<UnlimitedVoid> unlimitedVoid = make_shared<UnlimitedVoid>(abilities[AbilityId], attacking_link, defending_link);
                unlimitedVoid->execute(shared_ptr<GameState>(this));
            }

            abilityUsed = true;
        }
    }
}