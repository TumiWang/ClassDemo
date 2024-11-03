#include <iostream>

namespace M
{
    namespace N
    {
        int a = 1;
    }
    using namespace N;
}

int main()
{
    std::cout << M::a << std::endl; // 1
    std::cout << M::N::a << std::endl; // 1
}