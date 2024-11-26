#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <memory> // For shared_ptr
#include "Ability.h" // Full definition needed for inheritance

// Forward declarations
class Link;
class GameState;

class Download : public Ability {
    std::shared_ptr<Link> targetLink;

public: 
    Download(std::shared_ptr<Ability> ability, std::shared_ptr<Link> li);
    void execute(std::shared_ptr<GameState> game) override;
};

#endif // DOWNLOAD_H
