export module vec;

import <compare>;

export struct Vec {
  int x, y;
  auto operator<=>(const Vec &other) {
    auto n = x <=> other.x;
    return (n == 0) ? (y <=> other.y) : n;
  }
};
