#include <cstdint>
#include <iostream>

namespace A
{
    void g(std::int16_t) {
        std::cout << "Call g in the A -- std::int16_t" << std::endl;
    }
    void l(int) {
        std::cout << "Call l in the A -- int" << std::endl;
    }
}

namespace B
{
    void l(float) {
        std::cout << "Call f in the B -- float" << std::endl;
    }
}

namespace M
{
    using namespace A;
    void f(int) {
        std::cout << "Call f in the B -- int" << std::endl;
    }
    void g(float) {
        std::cout << "Call g in the M -- float" << std::endl;
    }
    void h(float) {
        std::cout << "Call h in the M -- float" << std::endl;
    }
}

namespace N
{
    using namespace B;
    void f() {
        std::cout << "Call f in the N" << std::endl;
    }
    void g(int) {
        std::cout << "Call g in the N -- int" << std::endl;
    }
}

namespace MN
{
    using namespace M;
    using namespace N;
    void f() {
        std::cout << "Call f in the MN" << std::endl;
    }
    void h(int) {
        std::cout << "Call h in the MN -- int" << std::endl;
    }
}

int main()
{
    MN::f();
    // MN::f(1);
    MN::g(1);
    MN::g(1.0f);
    MN::g(static_cast<std::int16_t>(1));
    // MN::g(1.0);
    // MN::g(static_cast<std::int64_t>(1));
    M::g(static_cast<std::int64_t>(1));
    A::g(static_cast<std::int64_t>(1));
    MN::h(1);
    MN::h(1.0);
    MN::l(1);
    MN::l(1.0f);
}