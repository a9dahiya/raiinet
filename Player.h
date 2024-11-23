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
    string name;
    vector<shared_ptr<Link>> myLinks;
    vector<shared_ptr<Ability>> Abilities;
    int downloadedData;
    int downloadedVirus;
    int abilitiesLeft;

public:
    void downloadLink(std::shared_ptr<Link> link);
    vector<shared_ptr<Link>> getAllLinks();
    string getName();
    Link getLink(char id);

    Player(string name, vector<shared_ptr<Link>> myLinks, vector<shared_ptr<Ability>> Abilities,
     int downloadedData = 0, int downloadedVirus = 0, int abilitiesLeft = 5);
};

#endif // PLAYER_H
