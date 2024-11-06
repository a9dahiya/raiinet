#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Widget {
 protected:
  string name;
 public:
  virtual void identify() const {
    cout << "I am a widget!  My name is " << name << "!" << endl;
  }
  Widget(const string &name): name{name} {}
  Widget(const Widget &other) {
    cout << "I am a widget being copied!" << endl;
  }
  Widget(Widget &&other) {
    cout << "I am a widget being moved!" << endl;
  }
  virtual ~Widget() {};
};

class Wudget: public Widget {
 protected:
  string nickname;
 public:
  void identify() const override {
    cout << "I am a wudget!  My name is " << name << "!  My nickname is " << nickname << "!" << endl;
  }
  Wudget(const string &name, const string &nickname): Widget{name}, nickname{nickname} {}
  Wudget(const Wudget &other) {
    cout << "I am a wudget being copied!" << endl;
  }
  Wudget(Wudget &&other) {
    cout << "I am a wudget being moved!" << endl;
  }
};

class WidgetGathering {
  Widget chiefWidget;
  Wudget chiefWudget;
  int numAttendees;
  Widget **attendees;

 public:
  WidgetGathering(const string &chiefWidgetName, const string &chiefWudgetName,
                  const string &nickname, int numAttendees):
    chiefWidget{chiefWidgetName},
    chiefWudget{chiefWudgetName, nickname},
    numAttendees{numAttendees},
    attendees{new Widget*[numAttendees]} {
    for (int i=0; i < numAttendees; ++i) {
      cout << "Widget or wudget?" << endl;
      string which;
      cin >> which;
      if (which == "widget") {
        string name;
        cout << "Name?" << endl;
        cin >> name;
        attendees[i] = new Widget{name};
      }
      else { // wudget
        string name, nickname;
        cout << "Name and nickname?" << endl;
        cin >> name >> nickname;
        attendees[i] = new Wudget{name, nickname};
      }
    }
  }
  void identify() const {
    cout << "Chief widget:" << endl;
    chiefWidget.identify();
    cout << "Chief wudget:" << endl;
    chiefWudget.identify();
    cout << "Attendees:" << endl;
    for (int i = 0; i < numAttendees; ++i) {
      attendees[i]->identify();
    }
  }
  ~WidgetGathering() {
    for (int i = 0; i < numAttendees; ++i) {
      delete attendees[i];
    }
    delete [] attendees;
  }
};

int main() {
  string chiefWidgetName, chiefWudgetName, nickname;
  cout << "Chief widget name?" << endl;
  cin >> chiefWidgetName;
  cout << "Chief wudget name and nickname?" << endl;
  cin >> chiefWudgetName >> nickname;
  int n = 0;
  cout << "Number of attendees?" << endl;
  cin >> n;
  WidgetGathering wg{chiefWidgetName, chiefWudgetName, nickname, n};

  cout << "The gathering:" << endl;
  wg.identify();

  cout << "Copying the gathering:" << endl;
  WidgetGathering wg2 = wg;

  cout << "The copied gathering:" << endl;
  wg.identify();

  cout << "Moving the gathering" << endl;
  WidgetGathering wg3 = std::move(wg);

  cout << "The moved gathering:" << endl;
  wg3.identify();

  cout << "The moved-from gathering:" << endl;
  wg.identify();
}
