#ifndef LINK_H
#define LINK_H

#include <memory>
#include <string>
#include "Position.h"

class Player;
class Position;

class Link {
    std::shared_ptr<Player> Owner;
    bool isData;
    int strength;
    bool BattleGod;
    char name;
    bool hasLinkBoost;
    Position position;
    bool revealed;
    bool Downloaded;

public:
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
    char getName();
    bool isRevealed();
    bool isDownloaded();
    void setRevealed();
    bool operator==(shared_ptr<Link> other);
    
};

#endif 
