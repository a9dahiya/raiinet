#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <memory>
#include "Ability.h"
class Link;
class GameState;
class Player;

class Download : public Ability {
public:
    void execute(shared_ptr<GameState> game) override;

private:
    std::shared_ptr<Link> targetLink;
    // YASHILA IS OVER HERE AND DISHAS BD IS HERE AND SHE DIDNT INVITE HER WHAT DO U WANNA 
    // 2 options, we can invite her to the daru party honestly, or we just vibes
};

#endif // DOWNLOAD_H
