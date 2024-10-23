export module list;

import <compare>;

export class List {
  class Node;
  Node *theList = nullptr;
  int length = 0;

 public:
  void addToFront(int n);
  int ith(int i);
  ~List();

  std::strong_ordering operator<=>(const List &other) const;

  bool operator==(const List &other) const;
};
