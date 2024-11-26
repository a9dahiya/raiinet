#ifndef POLARIZE_H
#define POLARIZE_H

#include <memory>
#include <vector>
#include "Ability.h"
#include "Cell.h"
#include "GameState.h"
#include "Player.h"
#include "Link.h"

using namespace std;

class Polarize : public Ability {
    shared_ptr<Link> targetLink;
    public:
    void execute(shared_ptr<GameState> game) override;
    Polarize(std::shared_ptr<Ability> ability, std::shared_ptr<Link> li);
    
};

#endif

