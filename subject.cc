#include "subject.h"
#include "Observer.h"
using namespace std;

void Subject::attach(shared_ptr<Observer> observer) {
    observers.emplace_back(shared_ptr<Observer>(observer));
}

void Subject::detach(std::shared_ptr<Observer> observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) { 
            observers.erase(it);
            break;
        }
    }
}


void Subject::notifyObservers() {
    for (const auto& observer : observers) {
        observer->notify();
    }
}

Subject::~Subject(){}
