#include "Link.h"

// Constructor: Initializes a Link object.
// Inputs: shared_ptr<Player> Owner - Owner of the Link,
//         char letter - Link's unique letter identifier,
//         string name - Link's name, 
//         bool Data - True if Link is a Data Link, 
//         int strength - Link's strength value.
Link::Link(shared_ptr<Player> Owner, char letter, string name, bool Data, int strength)
    : Owner{Owner}, letter{letter}, name{name}, Data{Data}, strength{strength} {}

// Returns the owner of the Link.
shared_ptr<Player> Link::getOwner() {
    return Owner;
}

// Returns the strength of the Link.
int Link::getStrength() {
    return strength;
}

// Returns true if the Link is a Data Link.
bool Link::isData() {
    return Data;
}

// Returns the position of the Link on the board.
Position Link::getPos() {
    return position;
}

// Switches the type of the Link (Data or Virus).
void Link::switchType() {
    Data = !Data;
}

// Returns true if the Link has a Link Boost.
bool Link::getLinkBoost() {
    return hasLinkBoost;
}

// Sets the Link Boost status to true.
void Link::setLinkBoost() {
    hasLinkBoost = true;
}

// Returns true if the Link is a Battle God.
bool Link::isBattleGod() {
    return BattleGod;
}

// Sets the Link as a Battle God.
void Link::setBattleGod() {
    BattleGod = true;
}

// Returns the name of the Link.
string Link::getName() {
    return name;
}

// Returns the unique letter identifier of the Link.
char Link::getLetter() {
    return letter;
}

// Returns true if the Link is revealed to the opponent.
bool Link::isRevealed() {
    return revealed;
}

// Sets the Link as revealed.
void Link::setRevealed() {
    revealed = true;
}

// Returns true if the Link is active on the board.
bool Link::isActive() {
    return onBoard;
}

// Sets the Link as inactive (removed from the board).
void Link::setInactive() {
    onBoard = false;
}

// Updates the Link's position on the board.
// Inputs: Position pos - New position for the Link.
void Link::setPos(Position pos) {
    position = pos;
}

// Equality operator: Compares two Links based on their name and owner.
// Inputs: shared_ptr<Link> other - The Link to compare against.
// Outputs: bool - True if the Links are equivalent, false otherwise.
bool Link::operator==(shared_ptr<Link> other) {
    return (getName() == other->getName() && getOwner() == other->getOwner());
}

// Calculates a new position based on direction and distance.
// Inputs: string dir - Direction ("up", "down", "left", "right"),
//         int dist - Distance to move.
// Outputs: Position - The calculated new position.
Position Link::getNewPos(string dir, int dist) {
    if (dir == "up") {
        return Position{position.getRow() - dist, position.getCol()};
    } else if (dir == "down") {
        return Position{position.getRow() + dist, position.getCol()};
    } else if (dir == "left") {
        return Position{position.getRow(), position.getCol() - dist};
    } else { // Assume "right" by default.
        return Position{position.getRow(), position.getCol() + dist};
    }
}
