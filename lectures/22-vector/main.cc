import <iostream>;
import <vector>;

using namespace std;

int main() {
  vector v1 {1, 5, 2, 5, 5, 3, 5, 5, 5, 4, 5, 5, 5, 5};

  v1.emplace_back(6);
  v1.emplace_back(7);

  for(auto i: v1) cout << i << ' ';
  cout << endl;

  for(auto it = v1.rbegin(); it != v1.rend(); ++it) cout << *it << ' ';
  cout << endl;

  vector v2 = v1;

  for(auto it = v1.begin(); it != v1.end(); ++it) {
    if (*it == 5) v1.erase(it);
  }

  for(auto i : v1) cout << i << ' ';
  cout << endl;

  for(auto it = v2.begin(); it != v2.end();) {
    if (*it == 5) it = v2.erase(it);
    else ++it;
  }

  for(auto i : v2) cout << i << ' ';
  cout << endl;
}
