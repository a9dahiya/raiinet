module Pokemon;
import <iostream>;
import <compare>;
import <string>;

struct Pokemon {
    std::string name;
    int level;
    Pokemon(std::string name, int level);
};

std::strong_ordering combat(const Pokemon &p1, const Pokemon &p2);
