#include "Firewall.cc"

Firewall::Firewall(shared_ptr<Ability> ability, shared_ptr<Cell> targetCell): Ability{ability}, targetCell{targetCell}