#include <iostream>

int main()
{
    const char test[] = "hello";
    // const char* test = "hello";
    *const_cast<char*>(test) = 'H';
    std::cout << test << std::endl;
}