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
    bool isData;
    int strength;
    bool BattleGod = false;
    char letter;
    std::string name;
    bool hasLinkBoost = false;
    Position position;
    bool revealed = false;

public:
    Link(std::shared_ptr<Player> Owner, char letter, string name, bool isData, int strength);
    std::shared_ptr<Player> getOwner();
    int getStrength();
    bool getIsData();
    Position getPos();
    Position getNewPos(Position, from);
    void switchType();
    bool getLinkBoost();
    void setLinkBoost();
    bool isBattleGod();
    void setBattleGod();
    string getName();
    char getletter();
    bool isRevealed();
    void setRevealed();
    bool operator==(shared_ptr<Link> other);
    void setPos(Position pos);
    
};

#endif 
