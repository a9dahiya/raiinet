module Pokemon;

Pokemon::Pokemon(std::string name, int level): name{name}, level{level} {}

std::strong_ordering combat(const Pokemon &p1, const Pokemon &p2) { return p1.level <=> p2.level; }
