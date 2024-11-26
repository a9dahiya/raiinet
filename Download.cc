#include "Download.h"
using namespace std;
#include "GameState.h"


Download::Download(shared_ptr<Ability> ability, shared_ptr<Link> link): 
    Ability{ability}, targetLink{link} {}

void Download::execute(shared_ptr<GameState> game){
    if(isUsed()){
        return;
    }
    game->GetCurrentPlayer()->downloadLink(targetLink);
}