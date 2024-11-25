#include "Link.h"

std::shared_ptr<Player> Link::getOwner(){
    return Owner;
}

int Link::getStrength(){
    return strength;
}

bool Link::getIsData(){
    return isData;
}

 Position Link::getPos(){
    return position;
 }

 void Link::switchType(){
    isData = !isData;
 }

 bool Link::getLinkBoost(){
    return hasLinkBoost;
 }

 void Link::setLinkBoost(){
    hasLinkBoost = true;
 }

 bool Link::isBattleGod(){
    return BattleGod;
 }

 void Link::setBattleGod(){
    BattleGod = true;
 }

 char Link::getName(){
    return name;
 }

 bool Link::isRevealed(){
    return revealed;
 }
 
bool Link::isDownloaded(){
    return Downloaded;
}

void Link::setRevealed(){
    revealed = true;
}

void Link::setPos(Position pos){
    position = pos;
}

bool Link::operator==(shared_ptr<Link> other){
    if (getName() != other->getName() || getOwner() != other->getOwner()){
        return false;
    }
    else{
        return true;
    }
}
