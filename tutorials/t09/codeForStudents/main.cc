import <iostream>;
import <string>;
import <vector>;
import <cmath>;

using namespace std;

class Component {
    public:
        virtual std::vector<float> calculate(const std::vector<float>& input) const = 0;
        virtual ~Component() = default;
};

class Decorator : public Component {
    // Add any fields necessary

    public:
        explicit Decorator(Component* next); // Fill out constructor
        ~Decorator(); // Fill out destructor
};

class Input : public Component {
    public:
        // Fill out calculate method
        std::vector<float> calculate(const std::vector<float>& input) const override;
};

class Bias : public Decorator {
    // Add any private fields necessary

    public:
        // Fill out constructor
        Bias(const std::vector<float>& bias, Component* next);

        // Fill out calculate method
        std::vector<float> calculate(const std::vector<float>& input) const override;
};

class Weight : public Decorator {
    // Add any private fields necessary
    public:
        // Fill out constructor
        Weight(const std::vector<std::vector<float>>& weights, Component* next);

        // Fill out calculate method
        std::vector<float> calculate(const std::vector<float>& input) const override;
};

template <typename Func> class ActivationFunction : public Decorator {
    // The template means we don't have to remember function pointer syntax!
    Func fn;
    public:
        // Fill out constructor
        ActivationFunction(const Func& fn, Component* next);

        // Fill out calculate method
        std::vector<float> calculate(const std::vector<float>& input) const override;
};


float step_function(float x) {
    return x >= 0.5 ? 1 : 0;
}

// Rectified Linear Unit (see https://en.wikipedia.org/wiki/Rectifier_(neural_networks))

float relu(float x) {
    return std::max<float>(0, x);
}

int main() {
    float x, y;

    Component* AndOperation = new ActivationFunction{
        &step_function,
        new Bias{
            std::vector<float>{-1.5},
            new Weight{
                std::vector<std::vector<float>>({std::vector<float>{1.0, 1.0}}),
                new Input{}
            }
        }
    };


    Component* OrOperation = new ActivationFunction{
        &step_function,
        new Bias{
            std::vector<float>{-0.5},
            new Weight{
                std::vector<std::vector<float>>({std::vector<float>{1.0, 1.0}}),
                new Input{}
            }
        }
    };

    Component* NotOperation = new ActivationFunction{
        &step_function,
        new Bias{
            std::vector<float>{0.5},
            new Weight{
                std::vector<std::vector<float>>({std::vector<float>{-1.0}}),
                new Input{}
            }
        }
    };

    Component* XorOperation = new ActivationFunction{
        &step_function,
        new Weight{
            std::vector<std::vector<float>>{std::vector<float>{1, -2}},
            new ActivationFunction{
                &relu,
                new Bias{
                    std::vector<float>{0, -6},
                    new Weight{
                        std::vector<std::vector<float>>{std::vector<float>{1, 2}, std::vector<float>{3, 6}},
                        new Input{}
                    }
                }
            }
        }
    };

    while (cin >> x >> y) {
        cout << "Input: " << x << " " << y << endl;
        cout << "AND: " << AndOperation->calculate(std::vector<float>{x, y})[0] << endl;
        cout << "OR: " << OrOperation->calculate(std::vector<float>{x, y})[0] << endl;
        cout << "NOT: x: " << NotOperation->calculate(std::vector<float>{x})[0]
            << " y: " << NotOperation->calculate(std::vector<float>{y})[0] << endl;

        cout << "XOR: " << XorOperation->calculate(std::vector<float>{x, y})[0] << endl;

    }

    delete AndOperation;
    delete OrOperation;
    delete NotOperation;
    delete XorOperation;
}
