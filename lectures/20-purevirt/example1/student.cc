export module student;

export class Student {
  protected:
    int numCourses;

  public:
    Student(int numCourses);
    virtual ~Student();
 
    virtual int getFees() = 0;
};
