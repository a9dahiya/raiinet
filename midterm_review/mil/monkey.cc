import <iostream>;
class Monkey {
    bool happy = true;
    public:
        bool isHappy(int &bananas) {
            if (happy && bananas > 0) std::cout << "ook ook." << std::endl;
            else std::cout << "OOH OOH AAH AAH." << std::endl;
            return happy;
        }
        Monkey(bool h) : happy{h} {}
};

class Johnny {
    Monkey monkey;
    const int bananas;
    int bananas2;
    int& bananas3;
    public:
        void speak() {
            if (monkey.isHappy(bananas3)) std::cout << "yay!" << std::endl;
            else std::cout << "no!" << std::endl;
        }
        Johnny() {
            monkey = monkey{true};
            bananas = 100;
            bananas2 = bananas;
            bananas3 = bananas2; 
        }
};