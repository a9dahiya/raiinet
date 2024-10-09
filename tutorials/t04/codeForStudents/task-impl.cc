module task;

import <utility>;

/* === Task class === */

/* --- Big 5 operations --- */

Task::Task(const std::string &description): 
  description{description}, id{nextId++}, done{false}, parent{nullptr}, children{new Task*[childrenCapacity]}, childrenLength{0} {
}

Task::Task(): 
  description{""}, id{0}, done{false}, parent{nullptr}, children{new Task*[childrenCapacity]}, childrenLength{0} {
}

Task::Task(const Task &other):
  //Add your code here
}

Task::Task(Task &&other):
  //Add your code here
}

Task &Task::operator=(const Task &other) {
  //Add your code here
}

Task &Task::operator=(Task &&other) {
  //Add your code here
}

Task::~Task() {
    for (int i = 0; i < childrenLength; ++i) {
        delete children[i];
    }
    delete [] children;
}

int nextId = 0;

/* --- Accessor and mutator methods --- */

const std::string &Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string &_desc){
    description = _desc;
}

const int &Task::getId() const {
    return id;
}

void Task::setId(const int &_id) {
    id = _id;
}

const bool Task::getDone() const {
    return done;
}

void Task::setDone(const bool &_done) {
    done = _done;
}

Task *Task::getParent() const {
    return parent;
}

void Task::setParent(Task *_parent) {
    parent = _parent;
}

const int Task::getLength() const {
    return childrenLength;
}

void Task::print(std::ostream &out, int identLevel) const {
    for (int i = 0; i < identLevel; ++i) {
        out << "  ";
    }
    if (id != 0) {
        out << this->id << ". [";
        if (this->getDone()) out << 'X';
        out << "] " << this->description << std::endl;
    } else {
        out << this->description << std::endl;
    }
    for (int i = 0; i < childrenLength; ++i) {
        children[i]->print(out, identLevel + 1);
    }
    
}

/* --- Operations with children --- */

void Task::addChild(Task *other) {
    children[childrenLength] = other;
    ++childrenLength;
}

void Task::removeChild(Task *other) {
    for (int i = 0; i < childrenLength; ++i) {
        if (children[i] == other) {
            for (int j = i; j < childrenLength-1; ++j) {
                children[j] = children[j+1];
            }
            children[childrenLength-1] = nullptr;
            --childrenLength;
            break;
        }
    }
}

Task *Task::findChild(std::string &description) {
    for (int i = 0; i < childrenLength; ++i) {
        if (children[i]->getDescription() == description) {
            return *(children+i);
        }
    }
    return nullptr;
}

Task *Task::findChildId(int &id) {
    for (int i = 0; i < childrenLength; ++i) {
        if (children[i]->getId() == id) {
            return *(children+i);
        }
    }
    return nullptr;
}

/* === Task output operator === */

std::ostream &operator<<(std::ostream &out, const Task &task) {
    task.print(out);
    return out;
}
