#include "Download.h"
#include "GameState.h"
#include "Player.h"
using namespace std;



Download::Download(string name, int id, shared_ptr<Player> owner): 
    Ability{name, id, owner}, targetLink{nullptr} {}

bool Download::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return false;
    }
    if(!targetLink) return false;
    game->GetCurrentPlayer()->downloadLink(targetLink);
    setUsed();
    return true;
}

void Download::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
