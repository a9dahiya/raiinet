export module bettor;
import <string>;
import observer;
import horserace;

export class Bettor: public Observer {
  HorseRace *subject;
  const std::string name;
  const std::string myHorse;

 public:
  Bettor(HorseRace *hr, std::string name, std::string horse);
  void notify() override;
  ~Bettor();
};
