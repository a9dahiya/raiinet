#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <vector>
#include <string>

// Forward declarations
class Link;
class Ability;
class Position;


using namespace std;


class Player {
    string name;
    vector<shared_ptr<Link>> myLinks;
    vector<shared_ptr<Ability>> Abilities;
    int downloadedData = 0;
    int downloadedVirus = 0;
    int abilitiesLeft = 0;
    vector<Position> serverPorts;

public:
    void downloadLink(shared_ptr<Link> link);
    vector<shared_ptr<Link>> getAllLinks();
    vector<shared_ptr<Ability>> getAbilities();
    string getName();
    shared_ptr<Link> getLink(char id);
    int numAbilityLeft();
    int getData(); //is this num
    int getVirus();
    bool isOwnLink(shared_ptr<Link> link);
    void setServerPort(Position pos);
    bool isOwnServerPort(Position pos);
    void addLink(shared_ptr<Link> link);
    void addAbility(shared_ptr<Ability> ability);
    bool operator!= (shared_ptr<Player> other);
    void reduceAbilityCount();

    Player(string name);
};

#endif // PLAYER_H
