#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>

class Observer;

class Subject {
public:
    void notifyObservers();
    void attach(shared_ptr<Observer> observer);
    void detach(shared_ptr<Observer> observer);

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

#endif 
