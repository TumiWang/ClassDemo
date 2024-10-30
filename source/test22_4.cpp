#include <iostream>

namespace mydata
{
    int a = 1;
}

int a = 2;

int main()
{
    {
        int a = 3;
        {
            int a = 4;
            std::cout << mydata::a  << std::endl; // 1
            std::cout << ::a  << std::endl; // 2
            std::cout << a  << std::endl; // 4
        }
        std::cout << ::a  << std::endl; // 2
        std::cout << a  << std::endl; // 3
    }
    std::cout << ::a  << std::endl; // 2
    std::cout << a  << std::endl; // 2
}