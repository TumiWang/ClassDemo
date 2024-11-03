#include <iostream>

inline namespace N
{
    int a = 1;
}

namespace M
{
    inline namespace K
    {
        int b = 2;
        inline namespace L
        {
            int c = 3;
        }
    }
}

int main()
{
    std::cout << N::a << std::endl; // 1
    std::cout << a << std::endl; // 1
    std::cout << M::b << std::endl; // 2
    std::cout << M::K::b << std::endl; // 2
    std::cout << M::c << std::endl; // 3
    std::cout << M::K::c << std::endl; // 3
    std::cout << M::K::L::c << std::endl; // 3
    std::cout << M::L::c << std::endl; // 3
    // std::cout << b << std::endl;
    // std::cout << K::b << std::endl;
    // std::cout << c << std::endl;
}