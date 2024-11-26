#ifndef SCAN_H
#define SCAN_H

#include <memory>
#include "Ability.h"
#include "Link.h"


class Scan : public Ability {
    std::shared_ptr<Link> targetLink;
public:
    void execute(shared_ptr<GameState> game) override;
    Scan(string name, int id, shared_ptr<Player> owner);
    void setTargetLink(shared_ptr<Link> link) override;
    
}
#endif // SCAN_H