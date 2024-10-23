export module list;

export class List {
  class Node;
  Node *theList = nullptr;

 public:
  void addToFront(int n);
  int ith(int i);
  ~List();
};
