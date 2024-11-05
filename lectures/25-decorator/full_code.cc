import <iostream>;
import <string>;
using namespace std;

class Pizza { // Interface only; functionality of the main object
  public:
    virtual float price() const = 0;
    virtual string desc() const = 0;
    virtual ~Pizza() {}  // Dtor must be implemented because it's a base class
};

class CrustAndSauce : public Pizza {  // Concrete component; implements the interface
  public:
    float price() const override { return 5.99; }
    string desc() const override { return "Basic pizza"; }
};

class Decorator : public Pizza {  // Base class for all decorators; a Decorator is a Pizza
  protected:
    Pizza *component;  // The object the decorator wraps
  public:
    Decorator(Pizza *p) : component{p} {}
    virtual ~Decorator() { delete component; }  // In this implementation, the decorator is
                                                // responsible for deleting the object it
};                                              // wraps

class StuffedCrust : public Decorator {
  public:
    StuffedCrust(Pizza *p) : Decorator{p} {}
    float price() const override {
        return component->price() + 2.69;  // “Replaces” the price with a new price
    }
    string desc() const override {
        return component->desc() + " with stuffed crust";  // Same for description
    }
};

class Topping : public Decorator {
    string theTopping;  // Decorator may have its own data fields
  public:
    Topping(Pizza *p, string topping) : Decorator{p}, theTopping{topping} {}
    float price() const override {
        return component->price() + 0.75;
    }
    string desc() const override {
        return component->desc() + " with " + theTopping;  // Here’s where we use the field
    }
};

int main() {
    Pizza *p = new CrustAndSauce;
    p = new StuffedCrust(p);
    p = new Topping(p, "cheese");
    p = new Topping(p, "mushrooms");
    
    cout << "Your " << p->desc() << " costs " << p->price() << endl;
}
