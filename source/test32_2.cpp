#include <cstdint>
#include <iomanip>
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
    void h() {
        std::cout << "Call A::h --" << m_ << std::endl;
    }
    virtual void i() {
        std::cout << "Call A::i --" << n_ << std::endl;
    }
    int m_;
    int n_;
};

template<class T>
void print_addr(T t, const char* info) {
    union Addr
    {
        std::uintptr_t addr;
        T t;
    };
    Addr addr;
    addr.t = t;
    std::cout << info
              << "0x"
              << std::hex
              << std::setw(16)
              << std::setfill('0')
              << addr.addr
              << std::hex
              << std::endl;
}

int main()
{
    print_addr(&A::f, "A::f  -> ");
    print_addr(&A::g, "A::g  -> ");
    print_addr(&A::h, "A::h  -> ");
    print_addr(&A::i, "A::i  -> ");
    print_addr(&A::m_, "A::m_ -> ");
    print_addr(&A::n_, "A::n_ -> ");
}
