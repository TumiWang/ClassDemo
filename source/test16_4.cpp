#include <iostream>

class A
{
public:
    void testA() {
        std::cout << "This is a A" << std::endl;
    }
private:
    int v_;
};

class B
{
public:
    void testB() {
        std::cout << "This is a B" << std::endl;
    }
};

int main()
{
    A a;
    B* b1 = reinterpret_cast<B*>(&a);
    b1->testB();
}