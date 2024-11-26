#include "Download.h"
#include "GameState.h"
#include "Player.h"
using namespace std;



Download::Download(string name, int id, shared_ptr<Player> owner): 
    Ability{name, id, owner}, targetLink{nullptr} {}

void Download::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return;
    }
    game->GetCurrentPlayer()->downloadLink(targetLink);
    setUsed();
}

void Download::setTargetLink(shared_ptr<Link> link){
    targetLink = link;
}
