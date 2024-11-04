#include <iostream>

namespace N
{
    int a = 1;
    extern int b;

    int GetA();

    int GetB() {
        return b;
    }
}

int N::b = 2;

int N::GetA()
{
    return a;
}

int main()
{
    std::cout << N::GetA() << std::endl;
    std::cout << N::GetB() << std::endl;
}