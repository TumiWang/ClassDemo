#include <cstdint>
#include <iostream>

class A
{
public:
    void f() {
        std::cout << "Call A::f" << std::endl;
    }

    virtual void g() {
        std::cout << "Call A::g" << std::endl;
    }

};

class B: public A
{
public:
    void g() override {
        std::cout << "Call B::g" << std::endl;
    }
}; 

int main()
{
    B b;
    A* a = &b;
    a->f();
    a->g();
    auto ga = &A::g;
    auto gg = reinterpret_cast<void(A::*)()>(&A::g);
    (a->*ga)(); 
    (a->*gg)(); 
}