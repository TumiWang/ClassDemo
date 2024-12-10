#include <cstdint>
#include <iostream>

class A
{
public:
    int a;
    void f() {}
    virtual void g() {}
    virtual void h() {}
    int b;
};

template<class T>
void print_addr(T t) {
    union MyAddr
    {
        std::uintptr_t addr;
        T t;
    };
    MyAddr addr;
    addr.t = t;
    std::cout << std::hex << addr.addr << std::dec << std::endl;
}

int main()
{
    print_addr(&A::a);
    print_addr(&A::f);
    print_addr(&A::g);
    print_addr(&A::h);
    print_addr(&A::b);
}