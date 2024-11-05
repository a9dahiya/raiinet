module horserace;
import <iostream>;
import <string>;
import subject;

using namespace std;

HorseRace::HorseRace(string source): in{source} {
}

HorseRace::~HorseRace() {}

bool HorseRace::runRace() {
  bool result {in >> lastWinner};

  if (result) cout << "Winner: " << lastWinner << endl;

  return result;
}

string HorseRace::getState() {
  return lastWinner;
}

