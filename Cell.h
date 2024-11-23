#ifndef CELL_H
#define CELL_H

#include <memory>
#include "Position.h"

class Position;
class Link;

class Cell {
public:
    Position getPos();
    std::shared_ptr<Link> getLink();
    void removeLink();
    void setLink(std::shared_ptr<Link> link);
    void setFirewall();
    void removeFirewall();
    bool isFirewall();

private:
    Position pos;
    std::shared_ptr<Link> link;
    bool isFirewall;
};

#endif
