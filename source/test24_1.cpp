#include <iostream>

namespace A
{
    int i = 10;
    int j = 11;
}

namespace B
{
    int i = 20;
    int k = 22;
    namespace C
    {
        namespace D
        {
            using namespace A;
            int k = 42;
            int l = i; // i为B::i
            int m = j; // j为A::j
        }
        using namespace D;
        int l = 30;
        int n = i; // i为B::i
        int p = k; // k为D::k
        // int q = l;
    }
}

int main()
{
    std::cout << "B::C::D::i=" << B::C::D::i << std::endl;
    std::cout << "B::C::D::l=" << B::C::D::l << std::endl;
    std::cout << "B::C::D::m=" << B::C::D::m << std::endl;
    std::cout << "B::C::m=" << B::C::m << std::endl;
    std::cout << "B::C::l=" << B::C::l << std::endl;
    std::cout << "B::C::n=" << B::C::n << std::endl;
    std::cout << "B::C::k=" << B::C::k << std::endl;
}