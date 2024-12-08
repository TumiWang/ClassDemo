#include <iostream>

int main()
{
    int a = 1;
    int b = { 2 };
    int c(3);
    int d{4};
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
}