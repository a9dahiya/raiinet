import <iostream>;
import <fstream>;
import <string>;
import <vector>;
using namespace std;

class Observer {  // Abstract Observer
  public:
    virtual void notify() = 0;
    virtual ~Observer() {}
};

class Subject {  // Abstract Subject
    vector<Observer *> observers;

  public:
    void attach(Observer *o) {
        observers.emplace_back(o);
    }
    
    void detach(Observer *o) {  // Remove from observers
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == o) {
                observers.erase(it);
                return;
            }
        }
    }

    void notifyObservers() const {
        for (auto o : observers) o->notify();
    }

    virtual ~Subject() = 0;
};

Subject::~Subject() {}  // Even though it's pure virtual, we can implement it; in fact, we must
                        // implement it because it will be called by all subclass dtors

class HorseRace : public Subject {  // Concrete Subject
    ifstream in{"race.txt"};  // Race winners are read from this file
    string lastWinner;  // This is the state the observers are interested in
    int raceNumber = 0;

  public:
    // Simulates running a race
    bool runRace() {
        bool result { in >> lastWinner };  // Read a race winner from file
        
        if (result) {
            raceNumber++;
            cout << "Race #" << raceNumber << ": Winner is " + lastWinner << endl; 
        }
        return result;
    }

    // Called by observers to get state (the race winner)
    string getLastWinner() const {
        return lastWinner;
    } 
};

class Bettor : public Observer {  // Concrete Observer
    HorseRace *subject;
    string name, myHorse;
    
  public:
    Bettor(HorseRace *subject, string name, string myHorse)
                : subject{subject}, name{name}, myHorse{myHorse} { 
        subject->attach(this);  // Attach to subject in ctor
    }

    ~Bettor() {
        subject->detach(this);  // Detach from subject in dtor
    }

    void notify() override {
        cout << name << ": ";
        if (subject->getLastWinner() == myHorse) {
            cout << "My horse won!!!" << endl;
        } else {
            cout << "Darn! Didn't win this time." << endl;
        }
    }
};

int main() {
    HorseRace hr;

    Bettor Larry{&hr, "Larry", "RunsLikeACow"};
    Bettor Curly{&hr, "Curly", "GreasedLightning"};
    // . . . (other bettors)

    // External controller is driving the processing.
    while (hr.runRace()) {
        hr.notifyObservers();
        cout << endl;
    }
}
