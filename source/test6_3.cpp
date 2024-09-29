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
    ~A() {
        std::cout << "Call ~A()" << std::endl;
    }
};

int main()
{
    // A temp;
    A* a = new A;
    // delete a;
    a->cleanup();
}