export module dippingsauce;
import pizza;
import decorator;
import <string>;

export class DippingSauce: public Decorator {
  std::string flavour;
 public:
  DippingSauce(std::string flavour, Pizza *component);
  float price() override;
  std::string description() override;
};
