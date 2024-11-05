module decorator;
import pizza;

Decorator::Decorator(Pizza *component): component{component} {}

Decorator::~Decorator() { delete component; }
