#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory>
#include "Observer.h"
using namespace std;

class Subject {
     vector<shared_ptr<Observer>> observers;
public:
    void notifyObservers();
    void attach(shared_ptr<Observer> observer);
    void detach(shared_ptr<Observer> observer);
    virtual ~Subject() = 0;

};

#endif 
