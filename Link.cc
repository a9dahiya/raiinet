#include "Link.h"


Link::Link(std::shared_ptr<Player> Owner, char letter, string name, bool Data, int strength)
: Owner{Owner}, letter{letter}, name{name}, Data{Data}, strength{strength} {}

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

bool Link::isActive(){
    return onBoard;
}
void Link::setInactive(){
    onBoard = false;
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
    }else if (dir == "down"){
        return Position{position.getRow() + dist, position.getCol()};
    }else if (dir == "left"){
        return Position{position.getRow(), position.getCol() - dist};
    }else{
        return Position{position.getRow(), position.getCol() + dist};
    }
}