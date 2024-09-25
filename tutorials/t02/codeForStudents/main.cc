import <iostream>;
import <string>;

using namespace std;

struct FriendList {
  string friends[8];
  int size = 0;
};

// Fill in the return type and arguments
___ operator>>(___, ___) {
  // Fill in this operator overload
}

// Fill in the return type and arguments
___ operator<<(___, ___) {
  // Fill in this operator overload
}

// For operator-, argument and return types are given
FriendList operator-(const FriendList& fl, int index) {
  // Fill in this operator overload
}

int main() {
  FriendList theList;
  char c;
  while (cin >> c) {
    // Quit Program
    if (c == 'q') {
      break;
    } else if (c == 'a') {
      // Add friend
      cin >> theList;
    } else if (c == 'p') {
      // Print friends
      cout << theList;
    } else if (c == 'r') {
      // Remove friend at index
      int index;
      cin >> index;
      theList = theList - index;
    }
  }
}
