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
    void downloadLink(shared_ptr<Link> link);
    vector<shared_ptr<Link>> getAllLinks();
    vector<shared_ptr<Ability>> getAbilities();
    string getName();
    shared_ptr<Link> getLink(char id);
    vector<shared_ptr<Link>> getAllLinks();
    int numAbilityLeft();
    int getData(); //is this num
    int getVirus();
    bool isOwnLink(shared_ptr<Link> link);

    Player(string name, vector<shared_ptr<Link>> myLinks, vector<shared_ptr<Ability>> Abilities,
     int downloadedData = 0, int downloadedVirus = 0, int abilitiesLeft = 5);
};

#endif // PLAYER_H
