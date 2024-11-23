#include "Player.h"
#include "subject.h"
#include "GameState.h"
#include "Observer.h"
#include "GraphicalObserver.h"
#include "TextObserver.h"
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    // Initializing Players and GameState
    shared_ptr<Player> P1 = make_shared<Player>("Player1" );
    shared_ptr<Player> P2 = make_shared<Player>("Player2" );
    int x = 0;
    bool setGraphics = false;
    while(x < argc){
        // 
        string arg = argv[x];
        if(arg = "-link1"){
            //Add Order for Link for Player 1
        }else if(arg == "-graphics" ){
            setGraphics = true;
        }else if(arg == ""){
            iji
        }

        x++;
    }
    
    shared_ptr<GameState> game;
    if(setGraphics){
        shared_ptr<GraphicalObserver> graphicDisplay= make_shared<GraphicalObserver>(game);
        game->attach(graphicDisplay);
    }else{
        shared_ptr<TextObserver> textDisplay= new(TextObserver);
        game->attach(textDisplay);
    }
}