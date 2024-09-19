import <iostream>;
import vector;

using namespace std;

int main () {
  Vec v = {1,2};
  v = v + v;
  cout << v.x << " " << v.y << endl;
}

