#include <iostream>

short a;
const char b = '@';
int c = 45;
int* p = nullptr;

void test() {
    // ...
}

int main()
{
    p = &c;
    std::cout << static_cast<void*>(p) << std::endl;
    int d = c;
    p = &d;
    std::cout << static_cast<void*>(p) << std::endl;
    {
        int d = 15;
        int& e = c;
        std::cout << d << std::endl;
    }
    std::cout << d << std::endl;
}