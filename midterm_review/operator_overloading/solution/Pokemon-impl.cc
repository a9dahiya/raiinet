module Pokemon;

using namespace std;

std::string Pokemon::convertType(const Type& type) const {
    string result;
    switch (type) {
        case (Type::FIRE): result = "FIRE"; break;
        case (Type::WATER): result = "WATER"; break;
        default: result = "GRASS"; break;  // type == Type::GRASS
    }
    return result;
}

istream& operator>>(istream& in, Pokemon& poke) {
    string n;
    in >> n;
    poke.name = n;

    int l;
    in >> l;
    if (in.good()) {
        if (l < 0 || l > 100) {
            cerr << "Invalid level!" << endl;
            return in;
        } else poke.level = l;
    } else {
        cerr << "Invalid level!" << endl;
        return in;
    }

    char t;
    in >> t;
    if (t == 'f') poke.type = Pokemon::Type::FIRE;
    else if (t == 'w') poke.type = Pokemon::Type::WATER;
    else if (t == 'g') poke.type = Pokemon::Type::GRASS;
    else {
        cerr << "Invalid type!" << endl;
        return in;
    }
    return in;
}

ostream& operator<<(ostream& out, const Pokemon& poke) {
    out << "[Name: " << poke.name 
        << "]  Level: " << poke.level 
        << "  Type: " << poke.convertType(poke.type);
    return out;
}

auto Pokemon::operator<=>(const Pokemon& opponent) const {
    auto result = level <=> opponent.level;
    if (result != 0) return result;
    if (type == opponent.type) return result;
    if (type == Type::FIRE) {
        if (opponent.type == Type::GRASS) result = strong_ordering::greater;
        else result = strong_ordering::less;
    } else if (type == Type::WATER) {
        if (opponent.type == Type::FIRE) result = strong_ordering::greater;
        else result = strong_ordering::less;
    } else {
        if (opponent.type == Type::WATER) result = strong_ordering::greater;
        else result = strong_ordering::less;
    }
    return result;
}   

void combat(const Pokemon& p1, const Pokemon& p2) {
    auto result = p1 <=> p2;
    cout << "[" << p1.name << "]";
    if ( result < 0 ) { cout << " lost to";
    } else if ( result == 0 ) { cout << " ties with";
    } else {
        cout << " won the match against";
    }
    cout << " [" << p2.name << "]" << endl;
}

int main() {
    Pokemon p[Pokemon::MAX_POKEMON];
    char c;
    unsigned int idx1 = 0, idx2 = 0;
    while ( cin >> c >> idx1 ) {
        switch(c) {
            case 'c':   // 'c' is for catching a Pokemon
                {
                    cin >> p[idx1];
                }
                break;
            case 'p':   // 'p' is for printing a Pokemon's stat
                {
                    cout << p[idx1] << endl;
                }
                break;
            case '=':  // '=' is for comparing two Pokemons
                {
                    cin >> idx2;
                    combat( p[idx1], p[idx2] );
                }
                break;
            default:
                cerr << "Unrecognized command '" << c << "'" << endl;
        } // switch
    } // while

} // main
