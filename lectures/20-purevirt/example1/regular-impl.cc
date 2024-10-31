module regular;

Regular::Regular(int numCourses): Student(numCourses) {}

int Regular::getFees() { return numCourses * 700; }

