#include <iostream>

int a = 11;
int b = 12;

namespace N
{
    int a = 21;
}

namespace
{
    int b = 22;
    
}

namespace N
{
    int getA() {
        return a;
    }
}

namespace
{
    int getA() {
        return a;
    }
    int getB() {
        return b;
    }
}

int main()
{
    std::cout << N::getA() << std::endl; // 21
    std::cout << getB() << std::endl; // 22
    std::cout << getA() << std::endl; // 11
}