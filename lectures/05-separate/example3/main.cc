import <iostream>;
import vector;
import linearAlg;

using namespace std;

int main () {
  Vec v = {1,2};
  v = v + v;
  int n = v * v;
  cout << v.x << " " << v.y << " " << n << endl;
}

