#include "GraphicalObserver.h"
#include "board.h"
#include "Cell.h"
#include "Link.h"
using namespace std;

GraphicalObserver::GraphicalObserver(shared_ptr<GameState> subject, shared_ptr<Player> Viewer): subject{subject}, Viewer{Viewer}{}

void GraphicalObserver::notify() {
    // Clear the window
    window->fillRectangle(0, 0, window->getWidth(), window->getHeight(), 0); // White background

    auto board = subject->GetBoard();
    auto players = subject->getPlayers();

    auto player1 = players[0];
    auto player2 = players[1];

    // Draw the board grid
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int x = col * PixelSize;
            int y = row * PixelSize;
            shared_ptr<Cell> cell = board->getCell(Position(row, col));
            shared_ptr<Link> link = cell->getLink();

            if (link) {
                // Determine if the link should be revealed
                string label = "?";
                if ((Viewer == player1 && link->getOwner() == player1) || 
                    (Viewer == player2 && link->getOwner() == player2) || 
                    link->isRevealed()) {
                    label = link->getLetter();
                }
                window->fillRectangle(x, y, PixelSize, PixelSize, 2); // Red for links
                window->drawString(x + PixelSize / 4, y + PixelSize / 2, label);
            } else if (cell->isFirewall()) {
                auto firewallOwner = cell->getFirewall()->getOwner();
                int color = (firewallOwner == player1) ? 3 : 4; // Green for Player 1, Blue for Player 2
                window->fillRectangle(x, y, PixelSize, PixelSize, color);
            } else if (cell->isServerPort()) {
                window->fillRectangle(x, y, PixelSize, PixelSize, 1); // Black for server ports
            } else {
                window->fillRectangle(x, y, PixelSize, PixelSize, 0); // White for empty cells
            }
        }
    }

    // Draw player information
    int infoOffsetY = height * PixelSize + 20; // Start below the board

    // Player 1 Info
    window->drawString(10, infoOffsetY, "Player 1:");
    window->drawString(10, infoOffsetY + 20, "Downloaded: " +
                        to_string(player1->getData()) + "D, " +
                        to_string(player1->getVirus()) + "V");
    window->drawString(10, infoOffsetY + 40, "Abilities left: " + 
                        to_string(player1->numAbilityLeft()));

    // Player 2 Info
    int infoOffsetX = width * PixelSize / 2;
    window->drawString(infoOffsetX, infoOffsetY, "Player 2:");
    window->drawString(infoOffsetX, infoOffsetY + 20, "Downloaded: " +
                        to_string(player2->getData()) + "D, " +
                        to_string(player2->getVirus()) + "V");
    window->drawString(infoOffsetX, infoOffsetY + 40, "Abilities left: " + 
                        to_string(player2->numAbilityLeft()));

    // Draw link details for both players
    int linkInfoY = infoOffsetY + 60;
    window->drawString(10, linkInfoY, "Links Player 1:");
    char label = 'a';
    for (auto &link : player1->getAllLinks()) {
        string display = "?";
        if (Viewer == player1 || link->isRevealed()) {
            display = link->getName();
        }
        window->drawString(10, linkInfoY + 20, string(1, label++) + ": " + display);
        linkInfoY += 20;
    }

    linkInfoY = infoOffsetY + 60;
    window->drawString(infoOffsetX, linkInfoY, "Links Player 2:");
    label = 'A';
    for (auto &link : player2->getAllLinks()) {
        string display = "?";
        if (Viewer == player2 || link->isRevealed()) {
            display = link->getName();
        }
        window->drawString(infoOffsetX, linkInfoY + 20, string(1, label++) + ": " + display);
        linkInfoY += 20;
    }
}