#include <iostream>

int main()
{
    volatile int a = 1;
    decltype((a)) b(a);
    std::cout << b << std::endl;
}