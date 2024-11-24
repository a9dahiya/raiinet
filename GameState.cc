#include <GameState.h>
#include <vector>
#include <memory>
#include <string>
#include <Player.h>
#include <Link.h>
#include <string>
using namespace std;

void GameState::moveLink(char linkId, const string& Dir){
    shared_ptr<Player> player = GetCurrentPlayer();
    shared_ptr<Link> link = player->getLink(linkId);
    
    int dist = 1;
    if(link->getLinkBoost()){
        dist = 2;
    }
    Position from = link->getPos();
    Position to = from.getnewPos(from, Dir, dist);
    if(!(GetBoard()->validMove(from, to, player))){
        //ur mom type shi
    }
    
    GetBoard()->moveLink(link, from, to);
    
    if( GetBoard()->hasOppLink(to, player) ){
        GetBoard()->tatake();
    }
}