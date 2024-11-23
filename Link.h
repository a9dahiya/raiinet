#ifndef LINK_H
#define LINK_H

#include <memory>
#include <string>
#include "Position.h"

class Player;
class Position;

class Link {
public:
    std::shared_ptr<Player> getOwner();
    int getStrength();
    bool getIsData();
    Position getPos();
    void switchType();
    bool getLinkBoost();
    void setLinkBoost();
    bool getIsBattleGod();
    void setBattleGod();
    char getName();
    bool IsRevealed();
    bool IsDownloaded();
    void setRevealed();

private:
    std::shared_ptr<Player> Owner;
    bool isData;
    int strength;
    bool isBattleGod;
    char name;
    bool hasLinkBoost;
    Position position;
    bool revealed;
    bool Downloaded;
};

#endif 
