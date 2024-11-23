#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <iostream>

class Cell;
class Link;
class Player;
class Position;

class Board {
public:
    std::shared_ptr<Cell> getCell(Position pos);
    void moveLink(Position from, Position to);
    void addLink(std::shared_ptr<Link> Link, Position pos);
    void removeLink(std::shared_ptr<Link> Link, Position pos);
    bool ValidMove(Position from, Position to, std::shared_ptr<Player> player);
    bool hasOppLink(Position pos, std::shared_ptr<Player> player);
    bool isOppServer(Position pos, std::shared_ptr<Player> player);
    bool offEdge(Position pos, std::shared_ptr<Player> player);
    int getHeight();
    int getWidth();

    friend std::ostream& operator<<(std::ostream& out, const Board& board);

private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Cell>>> board;
};

#endif 
