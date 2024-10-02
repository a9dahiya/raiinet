import <iostream>;
import <utility>;
using namespace std;

struct Node {
  int data;
  Node *next;
  void swap(Node &other) {
    using std::swap;
    swap(data, other.data);
    swap(next, other.next);
  }
  Node (int data, Node *next): data{data}, next{next} {
    cout << "Basic ctor" << endl;
  }
  Node (const Node &other) : data{other.data},
   next{other.next ? new Node {*other.next} : nullptr} {
    cout << "Copy ctor" << endl;
  }
  Node &operator=(const Node &other) {
    cout << "Copy assignment" << endl;
    Node n {other};
    swap(n);
    return *this;
  }
  Node &operator=(Node &&other) {
    cout << "Move assignment" << endl;
    swap(other);
    return *this;
  }
  Node (Node &&other) : data{other.data}, next{other.next} {
    other.next = nullptr;
    cout << "Move ctor" << endl;
  }
  ~Node() { delete next; }
};

Node oddsOrEvens () {
  Node odds {1, new Node {3, new Node {5, nullptr}}};
  Node evens {2, new Node {4, new Node {6, nullptr}}};
  char c;
  cin >> c;
  if (c == '0') return evens;
  else return odds;
}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) out << ' ' << *n.next;
  return out;
}

int main() {
  Node n {oddsOrEvens()};

  n = oddsOrEvens();

  cout << n << endl;
}
