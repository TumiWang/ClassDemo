#include <iostream>

class A
{
public:
    void test() const {
        std::cout << "Call test() with const" << std::endl;
    }
    void test() {
        std::cout << "Call test() without const" << std::endl;
    }
};

int main()
{
    A a0;
    a0.test();
    const A a1;
    a1.test();
    auto a2 = a1;
    a2.test();
    decltype(a1) a3 = a1;
    a3.test();
    decltype(a0) a4 = a0;
    a4.test();
}