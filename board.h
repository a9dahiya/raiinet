#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <iostream>
#include "Cell.h"
#include "link.h"
#include "Player.h"
#include "Position.h"

class Board {
public:
    Board(int width, int height);

    std::shared_ptr<Cell> getCell(Position pos);
    void moveLink(Position from, Position to);
    void addLink(std::shared_ptr<Link> link, Position pos);
    void removeLink(std::shared_ptr<Link> link, Position pos);
    bool ValidMove(Position from, Position to, std::shared_ptr<Player> player);
    bool hasOppLink(Position pos, std::shared_ptr<Player> player);
    bool isOppServer(Position pos, std::shared_ptr<Player> player);
    bool offEdge(Position pos, std::shared_ptr<Player> player);
    int getHeight() const;
    int getWidth() const;

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Cell>>> board;
};

#endif
