export module Pokemon;

import <iostream>;
import <compare>;
import <string>;

class Pokemon {
  public:
    inline static const unsigned int MAX_POKEMON = 6;
    enum class Type {FIRE, WATER, GRASS};
    std::string name;
    int level;
    Type type;

    auto operator<=>(const Pokemon& opponent) const;
    std::string convertType(const Type& type) const;
};

std::ostream& operator<<(std::ostream& out, const Pokemon& p);
std::istream& operator>>(std::istream& in, Pokemon& p);
