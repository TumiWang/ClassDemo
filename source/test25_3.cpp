#include <iostream>

const int x = 7;

int main()
{
    enum TEST
    {
        x = x + 1,
        y = x + 1
    };
    std::cout << x << std::endl; // 8
    std::cout << TEST::y << std::endl; // 9
}