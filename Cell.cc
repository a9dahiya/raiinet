#include "Cell.h"
#include "Position.h"
#include <memory>

Cell::Cell(Position pos, std::shared_ptr<Link> link) : 
    pos{pos}, link{link} {}


Position Cell::getPos() {
    return pos;
}

std::shared_ptr<Link> Cell::getLink() {
    return link;
}

void Cell::removeLink() {
    link = nullptr;
}

void Cell::setLink(std::shared_ptr<Link> li) {
    link = li;
}

void Cell::setFirewall(std::shared_ptr<Firewall> firee) {
    isfirewall = true;
    fire = firee;
}

void Cell::removeFirewall() {
    isfirewall = false;
    fire = nullptr;
}

bool Cell::isServerPort() {
    return isserverPort;
}

bool Cell::isFirewall(){
    return isfirewall;
}
