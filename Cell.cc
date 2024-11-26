#include "Cell.h"
#include "Position.h"
#include "Link.h"
#include "Firewall.h"
#include <iostream>

Cell::Cell(Position pos, std::shared_ptr<Link> link, bool serverPort) : 
    pos{pos}, link{link}, isserverPort{serverPort} {}


Position Cell::getPos() {
    return pos;
}

std::shared_ptr<Link> Cell::getLink() {
    return link;
}

std::shared_ptr<Firewall> Cell::getFirewall(){
    return fire;
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

void Cell::setServerPort(bool isServer) {
    isserverPort = isServer;
}
