module;
#include <fstream>
#include <string>
export module horserace;
import subject;

export class HorseRace: public Subject {
  std::fstream in;
  std::string lastWinner;

 public:
  HorseRace(std::string source);
  ~HorseRace();

  bool runRace(); // Returns true if a race was successfully run.

  std::string getState();
};
