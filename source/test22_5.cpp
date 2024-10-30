#include <iostream>

namespace
{
    int a = 1;
}

int a = 2;

int main()
{
    {
        int a = 3;
        std::cout << a  << std::endl; // 3
    }
    std::cout << ::a  << std::endl; // 2
    // std::cout << a  << std::endl;
}