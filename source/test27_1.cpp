#include <iostream>

int main()
{
    const volatile int j = 15;
    const_cast<int&>(j) = 10;
    std::cout << "j = " << j << std::endl;
}