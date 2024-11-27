#include "GraphicalObserver.h"
#include "board.h"
#include "Position.h"
#include "Ability.h"
#include "Link.h"
#include "Firewall.h"
#include "Cell.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

GraphicalObserver::GraphicalObserver(std::shared_ptr<GameState> subject, std::shared_ptr<Player> Viewer)
    : subject{subject}, Viewer{Viewer} 
{
    // Initialize board dimensions
    auto board = subject->GetBoard();
    height = board->getHeight();
    width = board->getWidth();

    // Initialize XWindow with extra space for UI elements (player info on top and bottom)
    int windowWidth = width * PixelSize;
    int windowHeight = height * PixelSize + 2 * InfoHeight; // Top and bottom info areas

    window = std::make_shared<Xwindow>(windowWidth, windowHeight);

    // Set background to white
    window->fillRectangle(0, 0, windowWidth, windowHeight, White);

    // Initial drawing
    notify();
}

GraphicalObserver::~GraphicalObserver() {
    // Xwindow destructor handles cleanup
}

void GraphicalObserver::notify() {
    clearWindow();
    // Draw Player 1 Info at the Top
    auto players = subject->getPlayers();
    if (players.size() < 2) {
        cerr << "Error: Less than two players in the game state." << endl;
        return;
    }

    auto player1 = players[0];
    auto player2 = players[1];

    // Determine if Viewer is Player 1 or Player 2
    bool isViewerPlayer1 = (Viewer == player1);
    bool isViewerPlayer2 = (Viewer == player2);

    // Draw Player 1 Info
    drawPlayerInfo(player1, 20, isViewerPlayer1);

    // Draw the Game Board
    drawBoard();

    // Draw Player 2 Info
    drawPlayerInfo(player2, height * PixelSize + InfoHeight + 20, isViewerPlayer2);

}

void GraphicalObserver::clearWindow() {
    // Clear the window by filling it with white
    window->fillRectangle(0, 0, width * PixelSize, height * PixelSize + 2 * InfoHeight, White);
}

void GraphicalObserver::drawBoard() {
    auto board = subject->GetBoard();
    auto players = subject->getPlayers();
    auto player1 = players[0];
    auto player2 = players[1];

    // Iterate through each cell to draw the board
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            // Calculate pixel coordinates
            int x = col * PixelSize;
            int y = InfoHeight + row * PixelSize;

            auto cell = board->getCell(Position(row, col));
            auto link = cell->getLink();

            if (link) {
                // Always display the link's letter on the board
                string linkLetter = string(1, link->getLetter());

                // Choose color based on owner
                Color linkColor = (link->getOwner() == player1) ? Red : Green;

                // Fill the cell with the link color
                window->fillRectangle(x, y, PixelSize, PixelSize, linkColor);

                // Draw the link letter
                window->drawString(x + 20, y + 30, linkLetter);
            }
            else if (cell->isFirewall()) {
                auto firewallOwner = cell->getFirewall()->getOwner();  
                Color firewallColor = (firewallOwner == player1) ? Green : Yellow;
                window->fillRectangle(x, y, PixelSize, PixelSize, firewallColor);
                window->drawString(x + 20, y + 30, "F");
            }
            else if (cell->isServerPort()) {
                window->fillRectangle(x, y, PixelSize, PixelSize, Magenta);
                window->drawString(x + 20, y + 30, "S");
            }
            else {
                // Empty cell
                window->fillRectangle(x, y, PixelSize, PixelSize, White);
                window->drawString(x + 20, y + 30, ".");
            }

            // Draw cell borders
            window->fillRectangle(x, y, PixelSize, 1, Black); // Top border
            window->fillRectangle(x, y, 1, PixelSize, Black); // Left border
        }
    }
}

void GraphicalObserver::drawPlayerInfo(std::shared_ptr<Player> player, int yOffset, bool isViewer) {
    // Display Player Name
    std::string playerName = player->getName();
    window->drawString(10, yOffset, playerName);

    // Display Downloaded Data and Virus Count
    std::string dataVirus = "Downloaded: " + std::to_string(player->getData()) +
                            "D, Virus: " + std::to_string(player->getVirus()) + "V";
    window->drawString(10, yOffset + 30, dataVirus);

    // Display Abilities Left
    std::string abilitiesLeft = "Abilities: " + std::to_string(player->numAbilityLeft());
    window->drawString(10, yOffset + 60, abilitiesLeft);

    // Display Links
    std::string linksDisplay = "Links:  ";
    auto links = player->getAllLinks();
    char label = isViewer ? 'a' : 'A'; // Lowercase for Player 1, Uppercase for Player 2

    // Display first four links
    for(size_t i = 0; i < links.size(); ++i){
        std::string linkName = (isViewer || links[i]->isRevealed()) ? links[i]->getName() : "?";
        linksDisplay += std::string(1, label++) + ": " + linkName + " ";
    }
    window->drawString(10, yOffset + 90, linksDisplay);

    /*
    // Display Abilities
    std::string abilitiesDisplay = "Abilities: ";
    auto abilities = player->getAbilities();
    for(auto &ability : abilities){
        abilitiesDisplay += ability->getName();
        if(ability->isUsed()){
            abilitiesDisplay += " (Used)";
        }
        abilitiesDisplay += ", ";
    }
    // Remove trailing comma and space
    if (abilitiesDisplay.size() > 10) {
        abilitiesDisplay.erase(abilitiesDisplay.size() - 2, 2);
    }
    window->drawString(10, yOffset + 130, abilitiesDisplay);*/
}
