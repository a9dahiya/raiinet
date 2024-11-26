#include "Download.h"
#include "GameState.h"
#include "Player.h"
using namespace std;



Download::Download(shared_ptr<Ability> ability, shared_ptr<Link> link): 
    Ability{ability->getName(), ability->getId(), ability->getOwner()}, targetLink{link} {}

void Download::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return;
    }
    game->GetCurrentPlayer()->downloadLink(targetLink);
}