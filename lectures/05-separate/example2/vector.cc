export module vector;

export struct Vec {
  int x;
  int y;
};

export Vec operator+(const Vec &v1, const Vec &v2);

export extern int globalNum;
