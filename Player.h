#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>
class Link;
class Ability;

class Player {
public:
    void downloadLink(std::shared_ptr<Link> link);

private:
    std::vector<std::shared_ptr<Link>> myLinks;
    std::vector<std::shared_ptr<Ability>> Abilities;
    int downloadedData;
    int downloadedVirus;
};

#endif // PLAYER_H
