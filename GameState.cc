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

// Constructor for Game, calls Board constructor to initialize Board
GameState::GameState(const vector<shared_ptr<Player>> players): players{players}, board{make_shared<Board>(players)} {}

// checks if Ability has already been used in current turn
bool GameState::isAbilityUsed(){
    return abilityUsed; 
}

// checks if a player has won and sets them as the winner, also removes any players that have lost from playing.
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

// allows Board methods to be accessed 
shared_ptr<Board> GameState::GetBoard(){
    return board;
}

// gets array of players
std::vector<std::shared_ptr<Player>> GameState::getPlayers(){
    return players;
}

// sets Winner of game
void GameState::setWinner(std::shared_ptr<Player> player){
    winner = player;
}

// returns winner
shared_ptr<Player> GameState::GetWinner(){
    return winner;
}

// returns if Game is over or not
bool GameState::isGameOver(){
    return GameOver;
}

// moves current player index to next player. loops back to first player
void GameState::NextTurn(){
    PlayerTurn = (PlayerTurn + 1) % (players.size());
    abilityUsed = false;
}

// gets current player
shared_ptr<Player> GameState::GetCurrentPlayer(){
    return players[PlayerTurn];
}

// gets next player
shared_ptr<Player> GameState::GetNextPlayer(){
    int next_player = (PlayerTurn + 1) % (players.size());
    return players[next_player];
}

// moves Link. calls Board::Link to move link across cells
void GameState::moveLink(char linkId, const string& Dir){
    shared_ptr<Player> player = GetCurrentPlayer();
    shared_ptr<Link> link = player->getLink(linkId);
    if(!link){
        cerr << "Cannot move a link that does not belong to you" << endl;
        return;
    }
    if(!(link->isActive())){
        cerr << "This link is not on the board anymore and cannot be moved" << endl;
        return;
    }
    if(Dir != "up" && Dir != "down" && Dir != "left" && Dir != "right"){
        cerr << "Did not enter a valid direction. Try Again!" << endl;
        return;
    }
    
    int dist = 1;
    if(link->getLinkBoost()){
        dist = 2;
    }
    Position from = link->getPos();
    Position to = link->getNewPos(Dir, dist);
    if(!(GetBoard()->ValidMove(from, to, player))){
        cerr << "Invalid move, try again!" << endl;
        return;
    }
    
    GetBoard()->moveLink(link, from, to, shared_from_this());
    NextTurn();
}

// Executes ability for current player if it has not been used before
void GameState::ExecuteAbility(int AbilityId, istream& in){
    if(AbilityId > 4 || AbilityId < 0){
        cerr << "Please enter a valid Ability Id";
    }
    if(isAbilityUsed()){
        // Ability already used in turn
        cerr << "Cannot use another Ability" << endl;
    }else{
        shared_ptr<Player> player = GetCurrentPlayer();
        vector<shared_ptr<Ability>> abilities = player->getAbilities();
        bool success = false;
        if( !(abilities[AbilityId]->isUsed()) ){
            string name = abilities[AbilityId]->getName();
            if(name == "Firewall"){
                int row, col;
                in >> row >> col;
                Position pos{row, col};
                shared_ptr<Cell> cell = GetBoard()->getCell(pos);
                abilities[AbilityId]->setTargetCell(cell);
                success = abilities[AbilityId]->execute( shared_from_this() );
            }else if(name == "Polarize"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                if(target_link == nullptr){
                    shared_ptr<Link> target_link = GetNextPlayer()->getLink(link);
                }
                abilities[AbilityId]->setTargetLink(target_link);
                success = abilities[AbilityId]->execute( shared_from_this() );
            }else if(name == "Download"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetNextPlayer()->getLink(link);
                abilities[AbilityId]->setTargetLink(target_link);
                success = abilities[AbilityId]->execute(shared_from_this() );
            }else if(name == "Scan"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetNextPlayer()->getLink(link);
                abilities[AbilityId]->setTargetLink(target_link);
                success = abilities[AbilityId]->execute(shared_from_this());
            }else if(name == "Link Boost"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                abilities[AbilityId]->setTargetLink(target_link);
                success = abilities[AbilityId]->execute(shared_from_this());
            }else if(name == "Russian Roulette"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                abilities[AbilityId]->setTargetLink(target_link);
                success = abilities[AbilityId]->execute(shared_from_this());
            }else if(name == "Battle God"){
                char link;
                in >> link;
                shared_ptr<Link> target_link = GetCurrentPlayer()->getLink(link);
                abilities[AbilityId]->setTargetLink(target_link);
                success = abilities[AbilityId]->execute(shared_from_this());
            }else if(name == "Unlimited Void"){
                char attacker, defender;
                in >> attacker >> defender;
                shared_ptr<Link> attacking_link = GetCurrentPlayer()->getLink(attacker);
                shared_ptr<Link> defending_link = GetNextPlayer()->getLink(defender);
                abilities[AbilityId]->setMyLink(attacking_link);
                abilities[AbilityId]->setOppLink(defending_link);
                success = abilities[AbilityId]->execute(shared_from_this());
            }
            if(success){
                abilityUsed = true;
                player->reduceAbilityCount();  
            }else{
                cerr << "Ability not executed, please enter the right parameters" << endl;
            } 
        }else{
            cerr << "This ability has already been used" << endl;
        }
    }
}