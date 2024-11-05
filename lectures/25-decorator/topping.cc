export module topping;
import pizza;
import decorator;
import <string>;

export class Topping: public Decorator {
  std::string theTopping;
  const float thePrice;
 public:
  Topping(std::string topping, Pizza *component);
  float price() override;
  std::string description() override;
};
