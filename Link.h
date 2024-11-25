#ifndef LINK_H
#define LINK_H

#include <memory>
#include <string>
#include "Position.h"
using namespace std;

class Player;
class Position;

class Link {
    std::shared_ptr<Player> Owner;
    bool Data;
    int strength;
    bool BattleGod = false;
    char letter;
    string name;
    bool hasLinkBoost = false;
    Position position;
    bool revealed = false;

public:
    Link(std::shared_ptr<Player> Owner, char letter, string name, bool isData, int strength);
    std::shared_ptr<Player> getOwner();
    int getStrength();
    bool isData();
    Position getPos();
    void switchType();
    bool getLinkBoost();
    void setLinkBoost();
    bool isBattleGod();
    void setBattleGod();
    string getName();
    char getLetter(); 
    bool isRevealed();
    void setRevealed();
    bool operator==(shared_ptr<Link> other);
    void setPos(Position pos);
    Position getNewPos(string dir, int dist); // do this
    
};

#endif 
