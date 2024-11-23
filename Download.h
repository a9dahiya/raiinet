#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <memory>
#include "Ability.h"
class Link;
class GameState;
class Player;

class Download : public Ability {
public:
    void execute(Game* game, const std::vector<std::string>& para) override;

private:
    std::shared_ptr<Link> targetLink;
};

#endif // DOWNLOAD_H
