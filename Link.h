#ifndef LINK_H
#define LINK_H

#include <memory>
#include <string>
#include "Position.h"
using namespace std;

class Player;
class Position;

class Link {
    shared_ptr<Player> Owner;
    char letter;
    string name;
    bool Data;
    int strength;
    bool BattleGod = false;
    Position position;
    bool hasLinkBoost = false;
    bool onBoard = true;
    bool revealed = false;

public:
    Link(std::shared_ptr<Player> Owner, char letter, string name, bool Data, int strength);
    shared_ptr<Player> getOwner();
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
    bool isActive();
    void setInactive();
    void setRevealed();
    bool operator==(shared_ptr<Link> other);
    void setPos(Position pos);
    Position getNewPos(string dir, int dist); // do this
    
};

#endif 
