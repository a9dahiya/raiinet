#include "Player.h"
#include "Ability.h"
#include "subject.h"
#include "GameState.h"
#include "Observer.h"
#include "GraphicalObserver.h"
#include "TextObserver.h"
#include "Link.h"

#include <memory>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<shared_ptr<Link>> setupLinks(shared_ptr<Player> player, string File, char index){
    // 
    ifstream f{File};
    vector<shared_ptr<Link>> links;
    
    string token;
    bool isData = false;

    while(f >> token){
        if(token[0] == 'd' || token[0] == 'D'){
            bool isData = true;
        }
        int strength = token[1];
        shared_ptr<Link> link = make_shared<Link>(player, token, index, isData, strength);
        links.emplace_back(link);
        index++;
    }
}

int main(int argc, char* args[]) {
    // Initializing Players and GameState
    shared_ptr<Player> P1 = make_shared<Player>("Player1");
    shared_ptr<Player> P2 = make_shared<Player>("Player2");
    int x = 0;

    // Flags for Initalizing GameState
    bool setGraphics = false;
    bool Link1order = false;
    bool Link2order = false;
    bool Ability1 = false;
    bool Ability2 = false;

    // Initializing Variables :
    vector<shared_ptr<Link>> p1_links;
    vector<shared_ptr<Link>> p2_links;
    vector<shared_ptr<Ability>> p1_abilities;
    vector<shared_ptr<Ability>> p2_abilities;

    // Checking for Command Line Arguments 
    while(x < argc){
        string arg = args[x];
        if(arg == "-link1"){
            // Add Order for Link for Player 1
            Link1order = true;
            x++;
            char ascii = 'a';
            p1_links = setupLinks(P1, args[x], ascii);
        }else if(arg == "-link2"){
            // Add Order for Link for Player 2
            Link2order = true;
            x++;
            char ascii = 'A';
            p2_links = setupLinks(P2, args[x], ascii);
        }else if(arg == "-graphics" ){
            // Enabling Graphical Observer
            setGraphics = true;
        }else if(arg == "-ability1"){
            // Adding Abilities for Player 1
            Ability1 = true;
            x++;
            // p1_abilities = setupAbility(P1);
        }else if(arg == "-ability2"){
            // Adding Abilities for Player 2
            Ability1 = true;
            x++;
        }

        x++;
    }
    
    string abilityOrder = "LFDSP";
    if(!Ability1){
        for(int x = 0; x < 5; ++x){
            p1_abilities[x] = make_shared<Ability>(abilityOrder[x],x,P1);
        }
    }
    if(!Ability2){
        for(int x = 0; x < 5; ++x){
            p1_abilities[x] = make_shared<Ability>(abilityOrder[x],x,P1);
        }
    }

    // Create Array of players
    vector<shared_ptr<Player>> players = { P1, P2 };;

    // Initializing GameState
    shared_ptr<GameState> game = make_shared<GameState>(players);
    if(setGraphics){
        shared_ptr<GraphicalObserver> graphicDisplay = make_shared<GraphicalObserver>(game);
        game->attach(graphicDisplay);
    }else{
        shared_ptr<TextObserver> textDisplay = make_shared<TextObserver>(game);
        game->attach(textDisplay);
    }

    // GAME LOOP
    string command;
    while(cin >> command){
        if(command == "quit"){
            // Exit game
            break;
        }else if(command == "move"){
            // Move a Link
            char link;
            string direction;
            if(cin >> link >> direction){
                game->moveLink(link, direction)
            }
        }else if (command == "ability"){
            // Use an Ability
            int id;
            if(cin >> id){
                game->ExecuteAbility(id, cin);
            } 
        }else if (command == "board"){
            // Print Board
            game->notifyObservers();
        }else if(command == "abilities"){
            // Print All Abilities
            vector<shared_ptr<Ability>> abilities = game->GetCurrentPlayer()->getAbilities();
            for(int x = 0; x < 5; ++x){
                cout << "ID: " << x << ", " ;
                cout << "Ability: " <<  abilities[x]->getName();
                if(abilities[x]->isUsed()){
                    cout << " ( Used )" << endl;
                }else {
                    cout << endl;
                }
            }
        }
    }
}