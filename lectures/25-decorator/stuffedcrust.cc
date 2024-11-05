export module stuffedcrust;
import pizza;
import decorator;
import <string>;

export class StuffedCrust: public Decorator {
 public:
  StuffedCrust(Pizza *component);
  float price() override;
  std::string description() override;
};
