#include "TextObserver.h"
#include <iostream>
#include "board.h"
#include "Link.h"

using namespace std;

TextObserver::TextObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer): subject{subject}, Viewer{Viewer}{}

void TextObserver::notify() {
    auto board = subject->GetBoard();
    auto players = subject->getPlayers();

    if(players.size() < 2){
        cerr << "Error: Not enough players to display.\n";
        return;
    }

    auto player1 = players[0];
    auto player2 = players[1];

    // Set the Viewer to Player1

    // Clear the console for better readability (optional)
    // This works on Unix/Linux systems. For Windows, use system("cls");
    // Uncomment the following line if desired:
    // system("clear");

    // Print Player 1 details
    cout << "Player 1:\n";
    cout << "Downloaded: " << player1->getData() << "D, " << player1->getVirus() << "V\n";
    cout << "Abilities: " << player1->numAbilityLeft() << "\n";

    // Display Player1's links labeled a-h with their names
    auto links1 = player1->getAllLinks();
    char label = 'a';
    for(auto &link : links1){
        cout << label++ << ": " << link->getName() << " ";
    }
    cout << "\n";

    // Print the board
    cout << *board;

    // Print Player 2 details
    cout << "Player 2:\n";
    cout << "Downloaded: " << player2->getData() << "D, " << player2->getVirus() << "V\n";
    cout << "Abilities: " << player2->numAbilityLeft() << "\n";

    // Display Player2's links labeled A-H as '?' unless revealed
    auto links2 = player2->getAllLinks();
    label = 'A';
    for(auto &link : links2){
        if(link->isRevealed()){
            cout << label++ << ": " << link->getName() << " ";
        }
        else{
            cout << label++ << ": ? ";
        }
    }
    cout << "\n";
}

