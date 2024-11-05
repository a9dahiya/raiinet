export module decorator;
import pizza;

export class Decorator: public Pizza {
 protected:
  Pizza *component;
 public:
  Decorator(Pizza *component);
  virtual ~Decorator();
};
