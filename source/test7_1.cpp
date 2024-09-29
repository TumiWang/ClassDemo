#include <iostream>

int main()
{
    size_t a = 1;
    size_t b = sizeof(++a);
    std::cout << "a=" << a << " b=" << b << std::endl;
}