module list;

struct List::Node {
  int data;
  Node *next;

  Node (int data, Node *next): data{data}, next{next} {}
  ~Node() { delete next; }

  auto operator<=>(const Node &other) const {  // Assumes non-empty lists.
    auto n = data <=> other.data;
    if (n != 0) return n;
    if (!next && !other.next) return n;
    if (!next) return std::strong_ordering::less;
    if (!other.next) return std::strong_ordering::greater;
    return *next <=> *other.next;
  }
};

List::~List() { delete theList; }

void List::addToFront(int n) { theList = new Node(n, theList); ++length; }

int List::ith(int i) {
  Node *cur = theList;
  for (int j = 0; j < i && cur; ++j, cur = cur -> next);
  return cur->data;
}

std::strong_ordering List::operator<=>(const List &other) const {
  if (!theList && !other.theList) return std::strong_ordering::equal;
  if (!theList) return std::strong_ordering::less;
  if (!other.theList) return std::strong_ordering::greater;
  return *theList <=> *other.theList;
}

bool List::operator==(const List &other) const {
  if (length != other.length) return false;
  return (*this <=> other) == 0;
}
