#ifndef CELL_H
#define CELL_H

#include <memory>
#include "Position.h"

class Position;
class Link;
class Firewall;

class Cell {
public:
    Cell(Position pos, std::shared_ptr<Link> link, bool serverPort = false);
    Position getPos();
    std::shared_ptr<Link> getLink();
    void removeLink();
    void setLink(std::shared_ptr<Link> li);
    void setFirewall(std::shared_ptr<Firewall> firee);
    void removeFirewall();
    bool isFirewall();
    bool isServerPort();
    void setServerPort(bool isServer);
    std::shared_ptr<Firewall> getFirewall();


    

private:
    Position pos;
    std::shared_ptr<Link> link;
    bool isfirewall = false;
    bool isserverPort = false;
    std::shared_ptr<Firewall> fire = nullptr;
};

#endif
