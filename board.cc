#include "Position.h"
#include "Cell.h"
#include "board.h"

Board::Board(std::vector<std::shared_ptr<Player>> players) : board(height, std::vector<std::shared_ptr<Cell>>(width, nullptr)) {
    serverPorts = {
        Position(0, width / 2 - 1),
        Position(0, width / 2),
        Position(height - 1, width / 2 - 1),
        Position(height - 1, width / 2)
    };

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            board[y][x] = std::make_shared<Cell>(Position{x, y}, nullptr);
        }
    }

    for (size_t playerIdx = 0; playerIdx < players.size(); ++playerIdx) {
        auto player = players[playerIdx];
        auto links = player->getAllLinks();

        int mainRow = (playerIdx == 0) ? 0 : height - 1;
        int altRow = (playerIdx == 0) ? 1 : height - 2;

        int linkIdx = 0;
        for (int x = 0; x < width; ++x) {
            Position currentPos(mainRow, x);
            bool isServerPort = false;

            for (const auto& port : serverPorts) {
                if (port == currentPos) {
                    isServerPort = true;
                    break;
                }
            }

            if (isServerPort) {
                board[altRow][x]->setLink(links[linkIdx++]);
            } else {
                board[mainRow][x]->setLink(links[linkIdx++]);
            }

            if (linkIdx >= links.size()) break;
        }
    }
}
