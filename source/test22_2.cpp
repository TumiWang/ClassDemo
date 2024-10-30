#include <iostream>

void test(int a) {
    if (bool b = a < 0)
    {
        int c = 0;
        // bool b = false;
        std::cout << b << std::endl;
    } else {
        int c = 0;
        // bool b = true;
        std::cout << b << std::endl;
    }
    // std::cout << b << std::endl;
}

int main()
{
    std::cout << std::boolalpha;
    test(-1);
    test(1);
}