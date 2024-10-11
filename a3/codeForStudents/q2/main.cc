import address;
import <iostream>;
import <string>;
using namespace std;

int main() {
    const size_t MAX_ADDRESSES = 5;
    Address addresses[MAX_ADDRESSES];
    char command;
    size_t idx1, idx2;
    string junk;

    while ( cin >> command ) {
        switch( command ) {
        case 'r':
            cin >> idx1;
            getline(cin, junk); // throw away rest of text, if any, on line
            cin >> addresses[idx1];
            break;
        case 'p':
            cin >> idx1;
            cout << addresses[idx1] << endl;
            break;
        case 'c':
            cin >> idx1 >> idx2;
            auto result = addresses[idx1] <=> addresses[idx2];
            if ( result == 0 ) cout << "equal" << endl;
            else if ( result < 0 ) cout << "less" << endl;
            else cout << "greater" << endl;
            break;
        } // switch
    } // while

} // main
