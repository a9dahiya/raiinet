import <iostream>;
import <sstream>;
import intset;

using namespace std;

const int MAX_INT_SETS = 5;

// Test harness for IntSet functions. You may assume that all commands entered are valid.
// Valid commands: n <ind>,  p <ind>, & <ind1> <ind2>,
//                 | <ind1> <ind2>, = <ind1> <ind2>,
//                 s <ind1> <ind2>, c <ind1> <elem>,
//                 a <ind1> <elem>, r <ind1> <elem>,
//                 q/EOF
// Silently ignores invalid commands. Doesn't check that 0 <= index < MAX_INT_SETS.
// Do not test invalid commands!

int main() { 
    IntSet *sets[MAX_INT_SETS]{nullptr}, *tmpSet{nullptr};
    char c;

    while ( cin >> c ) {
        int lhs, rhs;

        if ( c == 'q' ) break;

        switch(c) {
          case 'n':
            // Create new IntSet at index lhs after destroying the old.
            // Read in integers to add to it until hitting non-int using operator>>.
            cin >> lhs;
            delete sets[lhs];
            sets[lhs] = new IntSet;
            cin >> *sets[lhs];
            break;

          case 'p':
            // Print IntSet at lhs.
            cin >> lhs;
            cout << *sets[lhs] << endl;
            break;

          case '&':
            // Print intersection of lhs and rhs.
            cin >> lhs >> rhs; // reads in two indices
            delete tmpSet;
            tmpSet = (*sets[lhs] & *sets[rhs]);
            cout << *tmpSet << endl;
            break;

          case '|':
            // Print union of lhs and rhs.
            cin >> lhs >> rhs;
            delete tmpSet;
            tmpSet = (*sets[lhs] | *sets[rhs]);
            cout << *tmpSet << endl;
            break;

          case '=':
            // Print true if lhs == rhs, false otherwise.
            cin >> lhs >> rhs;
            cout << boolalpha << (*sets[lhs] == *sets[rhs]) << endl;
            break;

          case 's':
            // Print true if rhs is subset of lhs, false otherwise.
            cin >> lhs >> rhs;
            cout << boolalpha << sets[lhs]->isSubset( *sets[rhs] ) << endl;
            break;

          case 'c':
            // Print true if lhs contains element rhs, false otherwise.
            cin >> lhs >> rhs;
            cout << boolalpha << sets[lhs]->contains( rhs ) << endl;
            break;

          case 'a':
            // Add elem rhs to set lhs
            cin >> lhs >> rhs;
            sets[lhs]->add( rhs );
            break;

          case 'r':
            // Remove elem rhs from set lhs
            cin >> lhs >> rhs;
            sets[lhs]->remove( rhs );
            break;
            
        } // switch
    } // while

    for ( auto s : sets ) delete s;
    delete tmpSet;
} // main
