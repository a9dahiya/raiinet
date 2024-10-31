export module regular;
import student;

export class Regular: public Student {
  public:
    Regular(int numCourses);

    int getFees();
};
