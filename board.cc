#include "board.h"
#include "Cell.h"
#include "Position.h"

Board::Board(Player* player1, Player* player2) {
    board = std::vector<std::vector<std::shared_ptr<Cell>>>(
        height, std::vector<std::shared_ptr<Cell>>(width, nullptr)
    );

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            board[y][x] = std::make_shared<Cell>(Position{x, y}, nullptr); 
            //meowwwww
        }
    }

    // meow
}