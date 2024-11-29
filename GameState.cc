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
// Constructs the game state and initializes the board.
// Inputs: const vector<shared_ptr<Player>>& players - List of players in the game.
GameState::GameState(const vector<shared_ptr<Player>> players): players{players}, board{make_shared<Board>(players)} {}


// Checks if an ability has been used in the current turn.
// Inputs: None.
// Outputs: bool - True if an ability was used, false otherwise.
bool GameState::isAbilityUsed(){
    return abilityUsed; 
}

// Checks if a player has won, updates the winner, and removes losing players.
// Inputs: None.
// Outputs: None
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

// Returns the board.
// Inputs: None.
// Outputs: shared_ptr<Board> - The game board.
shared_ptr<Board> GameState::GetBoard(){
    return board;
}

// Returns the list of players.
// Inputs: None.
// Outputs: vector<shared_ptr<Player>> - List of players.
std::vector<std::shared_ptr<Player>> GameState::getPlayers(){
    return players;
}

// Sets the winner of the game.
// Inputs: shared_ptr<Player> player - The player who has won.
// Outputs: None.
void GameState::setWinner(std::shared_ptr<Player> player){
    winner = player;
}

// Returns the winner of the game.
// Inputs: None.
// Outputs: shared_ptr<Player> - The winning player.
shared_ptr<Player> GameState::GetWinner(){
    return winner;
}

// Checks if the game is over.
// Inputs: None.
// Outputs: bool - True if the game is over, false otherwise.
bool GameState::isGameOver(){
    return GameOver;
}

// Advances the turn to the next player.
// Inputs: None.
// Outputs: None.
void GameState::NextTurn(){
    PlayerTurn = (PlayerTurn + 1) % (players.size());
    abilityUsed = false;
}

// Returns the current player.
// Inputs: None.
// Outputs: shared_ptr<Player> - The current player.
shared_ptr<Player> GameState::GetCurrentPlayer(){
    return players[PlayerTurn];
}

// Returns the next player.
// Inputs: None.
// Outputs: shared_ptr<Player> - The next player.
shared_ptr<Player> GameState::GetNextPlayer(){
    int next_player = (PlayerTurn + 1) % (players.size());
    return players[next_player];
}

// Moves a player's link on the board.
// Inputs: char linkId - ID of the link to move, const string& Dir - Direction to move.
// Outputs: None.
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

// Executes an ability for the current player.
// Inputs: int AbilityId - ID of the ability, istream& in - Input stream for ability parameters.
// Outputs: None.
void GameState::ExecuteAbility(int AbilityId, istream& in){
    if(AbilityId > 4 || AbilityId < 0){
        cerr << "Please enter a valid Ability Id";
        return;
    }
    if(isAbilityUsed()){
        // Ability already used in turn
        cerr << "Cannot use another Ability" << endl;
        return;
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
