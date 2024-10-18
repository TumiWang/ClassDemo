#include <iostream>

int main()
{
    const int j = 15;
    const_cast<int&>(j) = 10;
    std::cout << "j = " << j << std::endl;
}