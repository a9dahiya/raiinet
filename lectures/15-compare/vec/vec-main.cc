import <iostream>;
import vec;

using std::cout;

int main() {
  Vec v1{1, 2}, v2{1, 3};

  auto cmp = v1 <=> v2;

  if (cmp < 0) cout << "Less\n";
  else if (cmp == 0) cout << "Equal\n";
  else cout << "Greater\n";
}
