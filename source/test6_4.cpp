#include <iostream>

class A
{
public:
    A() {
        std::cout << "Call A()" << std::endl;
    }
    virtual void cleanup() {
        delete this;
    }

protected:
    virtual ~A() {
        std::cout << "Call ~A()" << std::endl;
    }
};

class B: public A
{
};

int main()
{
    B temp;
}