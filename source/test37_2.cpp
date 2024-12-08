#include <iostream>

class A
{
public:
    void show() {
        std::cout << "Call show" << std::endl;
    }
    void show() const {
        std::cout << "Call const show" << std::endl;
    }
    void test() {
        auto l = [this]() {
            show();
        };
        l();
    }
};

int main()
{
    A a;
    a.test();
}