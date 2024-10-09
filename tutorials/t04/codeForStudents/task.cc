export module task;

import <iostream>;
import <string>;

export const int childrenCapacity = 5;

export extern int nextId;  // global varible counting created Task

export class Task {
    std::string description;   // the description of the Task
    int id;                   // the id attribute of the Task
    bool done;                // the done status of the Task
    Task *parent;             // pointer to the parent Task (or nullptr for the ToDo Task, which does not have a parent)
    Task **children;          // array of children Task pointers
    int childrenLength;       // current number of children Tasks

    //You can add extra private members here

    
  public:
    // Normal constructor
    Task(const std::string &description);
    Task();
    // Copy constructor
    Task(const Task &other);
    // Move constructor
    Task(Task &&other);
    // Copy assignment operator
    Task &operator=(const Task &other);
    // Move assignment operator
    Task &operator=(Task &&other);
    // Destructor
    ~Task();

    // Returns the value of the id field
    const int &getId() const;
    // Sets the value of the id field
    void setId(const int &_id);
    // Returns the value of the value field
    const std::string &getDescription() const;
    // Sets the value of the value field
    void setDescription(const std::string &_desc);
    // Returns the value of the parent field
    Task *getParent() const;
    // Sets the value of the parent field
    void setParent(Task *_parent);
    // Returns the value of the done field
    const bool getDone() const;
    // Sets the value of the done field
    void setDone(const bool &_done);
    // Returns the value of the childrenLength field
    const int getLength() const;

    // Prints this Task to out in the following format:
    // [] 1. Task description
    //      [] 2. Children 1
    //      [] ...
    // Note that the indentLevel starts at 0 for the first Task,
    // so, the first Task is printed without any trailing spaces.
    // For each children level, increase the indentLevel by 1.
    // For each indentLevel, add two spaces to the beginning of the line
    // If the id or value attributes are empty (""), do not print them.
    // If this Task does not have children, don't print anything for the ...children line.
    void print(std::ostream &out, int indentLevel = 0) const;

    // Adds other to the children array.
    void addChild(Task *other);
    // Removes other from the children array.
    // If other is not in the array, does nothing.
    // (Does NOT delete other).
    void removeChild(Task *other);
    // Returns the first Task in the children array whose description is equal to the supplied parameter.
	  // If no such Task is found, returns nullptr.
    Task *findChild(std::string &description);
    // Returns the first Task in the children array whose id is equal to the supplied parameter.
	  // If no such Task is found, returns nullptr.
    Task *findChildId(int &id);

    
};

// Prints the Task to out by calling its print() method.
export std::ostream &operator<<(std::ostream &out, const Task &Task);

