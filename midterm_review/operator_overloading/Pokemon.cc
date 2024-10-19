export module Pokemon;

import <iostream>;
import <compare>;
import <string>;

// *** No need to change the header file *** //
class Pokemon {
  public:
    inline static const unsigned int MAX_POKEMON = 6;
    enum class Type {FIRE, WATER, GRASS};
    std::string name;
    int level;
    Type type;
    auto operator<=>(const Pokemon&) const; // to implement
    std::string convertType(const Type& type) const;
};

std::ostream& operator<<(std::ostream&, const Pokemon&); // to implement
std::istream& operator>>(std::istream&, Pokemon&); // to implement
