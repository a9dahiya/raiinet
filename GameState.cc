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
    p
    int dist = 1;
    if(link->getLinkBoost()){
        dist = 2;
    }
    Position from = link->getPos();
    Position to = link->getnewPos(from, Dir, dist);
    if 
}