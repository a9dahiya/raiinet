export module coop;
import student;

export class Coop: public Student {
  public:
    Coop(int numCourses);

    int getFees();
};
