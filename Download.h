#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <memory>
#include "Ability.h"

class Link;
class GameState;
class Player;

using namespace std;

class Download : public Ability {
    shared_ptr<Link> targetLink;
public:
    void execute(shared_ptr<GameState> game) override;
    Download(string name, int id, shared_ptr<Player> owner);
    void setTargetLink(shared_ptr<Link> link) override;
};

#endif // DOWNLOAD_H
