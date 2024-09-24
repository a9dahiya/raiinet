export module node;
import <iostream>;

export struct Node {
  int data;
  Node *next;
  Node(int data, Node *next = nullptr);

  Node(const Node &n);
};

export std::ostream &operator<<(std::ostream &out, const Node &n);

