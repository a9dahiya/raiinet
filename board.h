#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <iostream>

class Cell;
class Link;
class Player;
class Position;
class GameState;


using namespace std;

class Board {
public:
    Board(std::vector<std::shared_ptr<Player>> players);
    std::shared_ptr<Cell> getCell(Position pos) const;
    void removeLink(Position pos);
    bool ValidMove(Position from, Position to, std::shared_ptr<Player> player);
    bool hasOppLink(Position pos, std::shared_ptr<Player> player);
    bool isOppServer(Position pos, std::shared_ptr<Player> player);
    bool offEdge(Position pos, std::shared_ptr<Player> player);
    int getHeight() const;
    int getWidth() const;
    std::shared_ptr<Link> tatake(std::shared_ptr<Link> attacker, std::shared_ptr<Link> defender);
    void moveLink(std::shared_ptr<Link> link, Position from, Position to, shared_ptr<GameState> game);

private:
    int width = 8;
    int height = 8;
    std::vector<std::vector<std::shared_ptr<Cell>>> board;
    std::vector<Position> serverPorts;

};

#endif
