export module vector;
import <iostream>;

export struct Vector {
  int x, y;

  explicit Vector(int x = 0, int y = 0);

  Vector operator+(const Vector &v) const;
  Vector operator*(const int k) const;
};

export Vector operator*(const int k, const Vector &v);

export std::ostream& operator<<(std::ostream &out, const Vector &v);
