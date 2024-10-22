import <iostream>;
import <compare>;
import node;

using std::cout;

int main() {
  Node n{1, new Node{2, new Node{3}}};
  Node m{1, new Node{2, new Node{1}}};

  auto cmp = n<=>m;

  if (cmp < 0) cout << "Less\n";
  else if (cmp == 0) cout << "Equal\n";
  else cout << "Greater\n";
}
