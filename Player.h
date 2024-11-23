#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>
#include <string>
#include <Link.h>
using namespace std;

class Link;
class Ability;

class Player {
public:
    void downloadLink(std::shared_ptr<Link> link);

private:
    string name;
    vector<shared_ptr<Link>> myLinks;
    vector<shared_ptr<Ability>> Abilities;
    int downloadedData;
    int downloadedVirus;
};

#endif // PLAYER_H
