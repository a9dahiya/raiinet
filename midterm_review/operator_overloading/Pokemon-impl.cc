module Pokemon;

using namespace std;

/*** Do not modify this function ***/
// You may use this as a helper when implementing the output operator
std::string Pokemon::convertType(const Type& type) const { 
    string result;
    switch (type) {
        case (Type::FIRE): result = "FIRE"; break;
        case (Type::WATER): result = "WATER"; break;
        default: result = "GRASS"; break;  // type == Type::GRASS
    }
    return result;
}

istream& operator>>(istream& , Pokemon& ) {
    /* Fill in the parameter names and Write your code here */
}

ostream& operator<<(ostream&, const Pokemon&) {
    /* Fill in the parameter names and Write your code here */
}

auto Pokemon::operator<=>(const Pokemon&) const {
    /* Fill in the parameter name and Write your code here */
}   

/*** Do not modify this function ***/
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

/*** Do not modify this function ***/
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
