import <iostream>;
import <fstream>;
import <string>;
import <vector>;
using namespace std;

class Observer;
class Subject {
  vector<Observer*> observers;

 public:
  void attach(Observer *o) { observers.emplace_back(o); }
  void detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end();) {
      if (*it == o) it = observers.erase(it);
      else ++it;
    }
  }
  void notifyObservers();
  virtual ~Subject() = 0;
};

Subject::~Subject() {}

class NewsOutlet: public Subject {
  string name;
  ifstream source;
  string headline;
 public:
  NewsOutlet(const string &name, const string &sourceName):
    name{name}, source{sourceName} {}
  string getName() const { return name; }
  // getNews:  return statement asks for the result of converting source
  // to bool.  True indicates success, false indicates failure, i.e., there
  // is no more news.
  bool getNews() { getline(source, headline); return bool{source}; }
  string getState() const { return headline; }
};

class Observer {
 public:
  virtual void notify(Subject *whoFrom) = 0;
  virtual ~Observer() {}
};

inline void Subject::notifyObservers() { for (auto o : observers) o->notify(this); }

class InformedCitizen: public Observer {
};

int main() {
  NewsOutlet tv{"TV", "tv.txt"}, socialMedia{"Social Media", "social.txt"};

  InformedCitizen ic{"science"};
  ic.addNewsSource(&tv);
  ic.addNewsSource(&socialMedia);

  bool tvDone = false, socialMediaDone = false;
  while(!tvDone && !socialMediaDone) {
    tvDone = !tv.getNews();
    socialMediaDone = !socialMedia.getNews();

    if (!tvDone) tv.notifyObservers();
    if (!socialMediaDone) socialMedia.notifyObservers();
  }
}
