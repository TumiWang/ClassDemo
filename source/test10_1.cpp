#include <iostream>

class A
{
public:
    void test(const int lineno) const {
        std::cout << "line:" << lineno << " Call test() with const" << std::endl;
    }
    void test(const int lineno) {
        std::cout  << "line:" << lineno << " Call test() without const" << std::endl;
    }
};

int main()
{
    A a0;
    a0.test(__LINE__);
    const A a1;
    a1.test(__LINE__);
    auto a2 = a1;
    a2.test(__LINE__);
    decltype(a1) a3 = a1;
    a3.test(__LINE__);
    decltype(a0) a4 = a0;
    a4.test(__LINE__);
}