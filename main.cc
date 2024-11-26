#include <iostream>
#include "Player.h"

#include "Ability.h"
#include "subject.h"
#include "GameState.h"
#include "Observer.h"
// #include "GraphicalObserver.h"
#include "TextObserver.h"
#include "Link.h"

#include "Firewall.h"
#include "Scan.h"
#include "LinkBoost.h"
#include "Download.h"
#include "Polarize.h"
#include "UnlimitedVoid.h"
#include "RussianRoulette.h"
#include "BattleGod.h"

#include <memory>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void setupAbility(shared_ptr<Player> player, string abilities){
    // Helper to initialize Abilities
    for (int x = 0; x < 5; ++x){
        if(abilities[x] == 'F'){
            shared_ptr<Ability> ability= make_shared<Firewall>("Firewall", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'S'){
            shared_ptr<Ability> ability= make_shared<Scan>("Scan", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'L'){
            shared_ptr<Ability> ability= make_shared<LinkBoost>("Link boost", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'D'){
            shared_ptr<Ability> ability= make_shared<Download>("Download", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'P'){
            shared_ptr<Ability> ability= make_shared<Polarize>("Polarize", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'U'){
            shared_ptr<Ability> ability= make_shared<UnlimitedVoid>("Unlimited Void", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'R'){
            shared_ptr<Ability> ability= make_shared<RussianRoulette>("Russian Roulette", x, player);
            player->addAbility(ability);
        }else if(abilities[x] == 'B'){
            shared_ptr<Ability> ability= make_shared<BattleGod>("Battle God", x, player);
            player->addAbility(ability);
        }
    }
}

void setupLinks(shared_ptr<Player> player, string File, char index){
    // Helper to initialize Links
    ifstream f{File};
    string token;
    bool isData = false;

    while(f >> token){
        if(token[0] == 'd' || token[0] == 'D'){
            isData = true;
        }
        int strength = token[1];
        shared_ptr<Link> link = make_shared<Link>(player, index, token, isData, strength);
        player->addLink(link);
        index++;
    }
}

int main(int argc, char* args[]) {
    // Initializing Players and GameState
    shared_ptr<Player> P1 = make_shared<Player>("Player 1");
    shared_ptr<Player> P2 = make_shared<Player>("Player 2");
    int x = 0;

    // Flags for Initalizing GameState
    bool setGraphics = false;
    bool Link1order = false;
    bool Link2order = false;
    bool Ability1 = false;
    bool Ability2 = false;

    // Checking for Command Line Arguments 
    while(x < argc){
        string arg = args[x];
        if(arg == "-link1"){
            // Add Order for Link for Player 1
            Link1order = true;
            x++;
            arg = args[x];
            char ascii = 'a';
            setupLinks(P1, arg, ascii);
        }else if(arg == "-link2"){
            // Add Order for Link for Player 2
            Link2order = true;
            x++;
            arg = args[x];
            char ascii = 'A';
            setupLinks(P2, arg, ascii);
        }else if(arg == "-graphics" ){
            // Enabling Graphical Observer
            setGraphics = true;
        }else if(arg == "-ability1"){
            // Adding Abilities for Player 1
            Ability1 = true;
            x++;
            arg = args[x];
            setupAbility(P1, arg);
        }else if(arg == "-ability2"){
            // Adding Abilities for Player 2
            Ability1 = true;
            x++;
            arg = args[x];
            setupAbility(P2, arg);
        }

        x++;
    }
    
    if(!Link1order && !Link2order){
        // ur mom
    }
    // Setting default 5 abilities if not chosen
    string abilityOrder = "LFSDP";
    if(!Ability1){
        setupAbility(P1, abilityOrder);
    }
    if(!Ability2){
        setupAbility(P2, abilityOrder);
    }
    
    // Create Array of players
    vector<shared_ptr<Player>> players = { P1, P2 };;

    // Initializing GameState
    shared_ptr<GameState> game = make_shared<GameState>(players);
    if(setGraphics){
       // shared_ptr<GraphicalObserver> graphicDisplay = make_shared<GraphicalObserver>(game, P1);
        //game->attach(graphicDisplay);
        cout << "allah" << endl;
    }else{
        shared_ptr<TextObserver> textDisplay = make_shared<TextObserver>(game, P1);
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
                game->moveLink(link, direction);
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
        }else if(command == "sequence"){
            
        }
    }
}