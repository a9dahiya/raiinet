module coop;

Coop::Coop(int numCourses): Student(numCourses) {}

int Coop::getFees() { return numCourses * 800; }

