#include Ability.h
#include <memory>
using namespace std;

Ability::Ability(string name, int id, shared_ptr<Player> Owner): name{name},id{id},Owner{Owner} {}