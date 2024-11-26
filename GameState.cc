#include <GameState.h>
#include <vector>
#include <memory>
#include <string>
#include <Player.h>
#include <Link.h>
#include <string>
#include <Ability.h>
#include <Firewall.h>
#include <Position.h>
using namespace std;

bool GameState::isAbilityUsed(){
    return abilityUsed;
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
                firewall->execute();
            }else if(name == "Polarize"){
                char link;
            }
            abilityUsed == true;
        }
    }
}