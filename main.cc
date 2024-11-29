#include <iostream>
#include "Player.h"
#include "Ability.h"
#include "subject.h"
#include "GameState.h"
#include "Observer.h"
#include "GraphicalObserver.h"
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
#include <algorithm>
#include <random>
using namespace std;

bool setupAbility(shared_ptr<Player> player, string abilities){
    // Helper to initialize Abilities
    int firewall = 0;
    int scan = 0;
    int linkBoost = 0;
    int download = 0;
    int polarize = 0;
    int unlimitedVoid = 0;
    int rRoulette = 0;
    int BGod = 0;
    vector<shared_ptr<Ability>> abilities_list;
    for (int x = 0; x < 5; ++x){
        if(abilities[x] == 'F'){
            if(firewall > 2) return false;
            abilities_list.emplace_back(make_shared<Firewall>("Firewall", x, player));
            firewall++;
        }else if(abilities[x] == 'S'){
            if (scan > 2) return false;
            abilities_list.emplace_back(make_shared<Scan>("Scan", x, player));
            scan++;
        }else if(abilities[x] == 'L'){
            if(linkBoost > 2) return false;
            abilities_list.emplace_back(make_shared<LinkBoost>("Link Boost", x, player));
            linkBoost++;
        }else if(abilities[x] == 'D'){
            if(download > 2) return false;
            abilities_list.emplace_back(make_shared<Download>("Download", x, player));
            download++;
        }else if(abilities[x] == 'P'){
            if(polarize > 2) return false;
            abilities_list.emplace_back(make_shared<Polarize>("Polarize", x, player));
            polarize++;
        }else if(abilities[x] == 'U'){
            if(unlimitedVoid > 2) return false;
            abilities_list.emplace_back(make_shared<UnlimitedVoid>("Unlimited Void", x, player));
            unlimitedVoid++;
        }else if(abilities[x] == 'R'){
            if(rRoulette > 2) return false;
            abilities_list.emplace_back(make_shared<RussianRoulette>("Russian Roulette", x, player));
            rRoulette++;
        }else if(abilities[x] == 'B'){
            if(BGod > 2) return false;
            abilities_list.emplace_back(make_shared<BattleGod>("Battle God", x, player));
            BGod++;
        }else{
            cerr << "Cannot setup player abilities, using default..." << endl;
            return false;
        }
    }

    player->addAbility(abilities_list);
    return true;
}

bool setupLinks(shared_ptr<Player> player, string File, char index){
    // Helper to initialize Links
    ifstream f{File};
    if (!f.is_open()) { // If file not accessible
        cerr << "File not accessible. Please enter a valid file!" << endl;
        return false;
    }
    string token;
    bool isData = false;
    vector<shared_ptr<Link>> player_links;
    while(f >> token){
        if(token.size() != 2){
            cerr << "Cannot setup provided Link Order, randomizing Links..." << endl;
            return false;
        }
        if(token[0] != 'D' || token[0] != 'd' || token[0] != 'V' || token[0] != 'v'){
            cerr << "Cannot setup provided Link Order, randomizing Links..." << endl;
            return false;
        }
        if(token[1] != '1' || token[1] != '2' || token[1] != '3' || token[1] != '4'){
            cerr << "Cannot setup provided Link Order, randomizing Links..." << endl;
            return false;
        }
        if(token[0] == 'd' || token[0] == 'D'){
            isData = true;
        }
        int strength = token[1];
        player_links.emplace_back(make_shared<Link>(player, index, token, isData, strength));
        index++;
    }  
    if(player_links.size() != 8) return false;
    player->addLink(player_links);
    return true;
}

void randomizeLinks(shared_ptr<Player> player, char index, vector<string>& links) {
    random_device rd;
    mt19937 g(rd());
    shuffle(links.begin(), links.end(), g);
    vector<shared_ptr<Link>> player_links;
    for (int i = 0; i < 8; ++i) {
        string token = links[i];
        bool isData = false;
        if(token[0] == 'd' || token[0] == 'D'){
            isData = true;
        }
        int strength = token[1];
        player_links.emplace_back(make_shared<Link>(player, index, token, isData, strength));
        player->addLink(player_links);
        index++;
    }
}

void readfromfile(shared_ptr<GameState> game, string file){
    ifstream f{file};
    if (!f.is_open()) { // If file not accessible
        cerr << "File not accessible. Please enter a valid file!" << endl;
        return;
    }
    string command;
    while(f >> command){
        if(command == "quit"){
            // Exit game
            break;
        }else if(command == "move"){
            // Move a Link
            char link;
            string direction;
            if(f >> link >> direction){
                game->moveLink(link, direction);
            }
        }else if (command == "ability"){
            // Use an Ability
            int id;
            if(f >> id){
                game->ExecuteAbility(id, f);
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
            string file;
            f >> file;
            readfromfile(game, file);
        }
        game->HasWon();
        if(game->isGameOver()){
            cout << "Game Over!, " << game->GetWinner()->getName() << " wins!" << endl;
            break;
        } 
    }
}


int main(int argc, char* args[]) {
    // Initializing Players and GameState
    shared_ptr<Player> P1 = make_shared<Player>("Player 1");
    shared_ptr<Player> P2 = make_shared<Player>("Player 2");
    int x = 1;

    // Flags for Initalizing GameState
    bool setGraphics = false;
    bool view_player2 = false;
    bool Link1order = false;
    bool Link2order = false;
    bool Ability1 = false;
    bool Ability2 = false;
    char ascii = 'a';

    // Checking for Command Line Arguments 
    while(x < argc){
        string arg = args[x];
        if(arg == "-link1"){
            // Add Order for Link for Player 1
            x++;
            arg = args[x];
            if(setupLinks(P1, arg, ascii)){
                Link1order = true;
            }
        }else if(arg == "-link2"){
            // Add Order for Link for Player 2
            x++;
            arg = args[x];
            ascii = 'A';
            if (setupLinks(P2, arg, ascii)){
                Link2order = true;
            }
        }else if(arg == "-player2"){
            // Setting Player 2 as the viewer 
            view_player2 = true;
        } else if(arg == "-graphics" ){
            // Enabling Graphical Observer
            setGraphics = true;
        }else if(arg == "-ability1"){
            // Adding Abilities for Player 1
            x++;
            arg = args[x];
            if (setupAbility(P1, arg)){
                Ability1 = true;
            }
        }else if(arg == "-ability2"){
            // Adding Abilities for Player 2
            x++;
            arg = args[x];
            if (setupAbility(P2, arg)){
                Ability2 = true;
            }
        }
        x++;
    }

    // Randomizing order of links if order not given: 
    vector<string> AllLinks = { "V1", "V2", "V3", "V4", "D1", "D2", "D3", "D4" };
    if(!Link1order){
        randomizeLinks(P1, ascii, AllLinks);
    }
    if(!Link2order){
        ascii = 'A';
        randomizeLinks(P2, ascii, AllLinks);
    }

    
    // Setting default 5 abilities if not chosen:
    string abilityOrder = "LFSDP";
    if(!Ability1){
        setupAbility(P1, abilityOrder);
    }
    if(!Ability2){
        setupAbility(P2, abilityOrder);
    }
    
    // Create Array of players
    vector<shared_ptr<Player>> players = { P1, P2 };

    // Initializing GameState
    shared_ptr<GameState> game = make_shared<GameState>(players);

    // Initializing Observers 
    if(setGraphics){
        if(view_player2){
            shared_ptr<GraphicalObserver> graphicDisplay = make_shared<GraphicalObserver>(game, P2);
            game->attach(graphicDisplay);
        }else{
            shared_ptr<GraphicalObserver> graphicDisplay = make_shared<GraphicalObserver>(game, P1);
            game->attach(graphicDisplay);
        }
    }else{
        if(view_player2){
            shared_ptr<TextObserver> textDisplay = make_shared<TextObserver>(game, P2);
            game->attach(textDisplay);
        }else{
            shared_ptr<TextObserver> textDisplay = make_shared<TextObserver>(game, P1);
            game->attach(textDisplay);
        }
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
            // Prints Board
            game->notifyObservers();
        }else if(command == "abilities"){
            // Print All Abilities
            vector<shared_ptr<Ability>> abilities = game->GetCurrentPlayer()->getAbilities();
            for(int x = 0; x < 5; ++x){
                cout << "ID: " << x << ", " ;
                cout << "Ability: " <<  abilities[x]->getName();
                if(abilities[x]->isUsed()){ // Lets user know which Abilities used
                    cout << " ( Used )" << endl;
                }else {
                    cout << endl;
                }
            }
        }else if(command == "sequence"){
            // read input from file
            string file;
            cin >> file;
            readfromfile(game, file);
        }else{
            cerr << "Invalid Command" << endl;
        }
        // check if Game is over or not
        game->HasWon();
        if(game->isGameOver()){
            // Outputs winner
            cout << "Game Over!, " << game->GetWinner()->getName() << " wins!" << endl;
            break;
        } 
    }
}
