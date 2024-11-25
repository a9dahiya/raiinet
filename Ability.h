#ifndef ABILITY_H
#define ABILITY_H

#include <memory>
#include <string>
#include <vector>

class Game;
class Link;

class Ability {
public:
    virtual void execute(Game* game, const std::vector<std::string>& param);
    bool isUsed();
    void setUsed();
    std::string getName();
    int getId();

private:
    std::string name;
    int id;
    std::shared_ptr<Link> Owner;
    bool used = false;
};

#endif // ABILITY_H
