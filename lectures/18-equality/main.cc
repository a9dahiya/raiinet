import <iostream>;
import list;
using namespace std;

int main() {
  List l;
  l.addToFront(1);
  l.addToFront(2);
  l.addToFront(3);

  for (int  i = 0; i < 3; ++i) {
    cout << l.ith(i) << endl;
  }

  List l2;
  l2.addToFront(1);

  std::cout << std::boolalpha;
  std::cout << (l == l2) << std::endl;
  std::cout << (l != l2) << std::endl;
}
