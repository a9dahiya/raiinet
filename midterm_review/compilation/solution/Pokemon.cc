export module Pokemon;
import <iostream>;
import <compare>;
import <string>;

export struct Pokemon {
    std::string name;
    int level;
    Pokemon(std::string name, int level);
};

export std::strong_ordering combat(const Pokemon &p1, const Pokemon &p2);
