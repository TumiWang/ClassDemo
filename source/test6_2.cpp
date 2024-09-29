#include <iostream>

class A
{
public:
    A() {
        std::cout << "Call A()" << std::endl;
    }
    ~A()  {
        std::cout << "Call ~A()" << std::endl;
    }
};

class B
{
public:
    B() {
        std::cout << "Call B()" << std::endl;
    }
    virtual ~B()  {
        std::cout << "Call ~B()" << std::endl;
    }
};

class C: public A
{
public:
    C() {
        std::cout << "Call C()" << std::endl;
    };
    ~C() {
        std::cout << "Call ~C()" << std::endl;
    }
};

class D: public B
{
public:
    D() {
        std::cout << "Call D()" << std::endl;
    };
    ~D() {
        std::cout << "Call ~D()" << std::endl;
    }
};

int main()
{
    {
        std::cout << "场景 --- 1" << std::endl;
        C c;
    }
    {
        std::cout << std::endl;
        std::cout << "场景 --- 2" << std::endl;
        C* c = new C;
        delete c;
    }
    {
        std::cout << std::endl;
        std::cout << "场景 --- 3" << std::endl;
        A* a = new C;
        delete a;
    }
    {
        std::cout << std::endl;
        std::cout << "场景 --- 4" << std::endl;
        B* b = new D;
        delete b;
    }
}