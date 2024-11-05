export module pizza;
import <string>;

export class Pizza {
 public:
  virtual float price() = 0;
  virtual std::string description() = 0;
  virtual ~Pizza();
};
