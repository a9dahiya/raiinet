export module node;
import <compare>;

export struct Node {
  int data;
  Node *next;

  auto operator<=>(const Node &other) const {  // Assumes non-empty lists.
    auto n = data <=> other.data;
    if (n != 0) return n;
    if (!next && !other.next) return n;
    if (!next) return std::strong_ordering::less;
    if (!other.next) return std::strong_ordering::greater;
    return *next <=> *other.next;
  }

  ~Node() { delete next; }
};
