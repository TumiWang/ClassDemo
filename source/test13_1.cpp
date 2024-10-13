#include <cstring>
#include <iostream>

int main()
{
    int a = 0x43308000;
    float b;
    memcpy(&b, &a, sizeof(a));
    std::cout << b << std::endl;
}