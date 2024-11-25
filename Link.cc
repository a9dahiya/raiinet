#include "Link.h"

std::shared_ptr<Player> Link::getOwner(){
    return Owner;
}

int Link::getStrength(){
    return strength;
}

bool Link::isData(){
    return Data;
}

 Position Link::getPos(){
    return position;
 }

 void Link::switchType(){
    Data = !Data;
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

 string Link::getName(){
    return name;
 }

char Link::getLetter(){
    return letter;
}

 bool Link::isRevealed(){
    return revealed;
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

Position Link::getNewPos(string dir, int dist){
    if (dir == "up"){
        return Position{position.getRow() - dist, position.getCol()};
    }
    if (dir == "down"){
        return Position{position.getRow() + dist, position.getCol()};
    }
    if (dir == "left"){
        return Position{position.getRow(), position.getCol() - dist};
    }
    if (dir == "right"){
        return Position{position.getRow(), position.getCol() + dist};
    }
}