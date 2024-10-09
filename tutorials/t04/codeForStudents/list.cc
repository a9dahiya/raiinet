export module list;

import <iostream>;
import <string>;
import task;

export class List {
    Task *root;
    Task *cur;
    Task *clip;
    void printCurrent();
  public:
    List();
    ~List();
    void print();                             // tests Task::print
    void addChild(std::string option);        // tests Task::addChild
    void deleteCur();                         // tests Task::removeChild
    void parent();                            // tests Task::getParent
    void up();                                // goes back to the Document level
    void setDescription(std::string option);  // tests Task::setDescription
    void setDone(bool done);                  // tests Task::setDone
    void findChild(std::string option);       // tests Task::findChild
    void findChildId(int option);             // tests Task::findChildId
    void cut();                               // moves current task to internal clipboard (tests move operations)
    void copy();                              // copies current task to internal clipboard (tests copy operations)
    void paste();                             // adds task from internal clipboard as a new child
};

