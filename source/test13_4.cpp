#include <cassert>
#include <cstring>

// #include <stdio.h>
#include <iostream>

int main()
{
    // float a = 8.0;
    // int b = 0x35000000;
    // // b的二进制为0011 0101 0000 0000 0000 0000 0000 0000
    // float c;
    // memcpy(&c, &b, sizeof(b));
    // assert(c != 0.0);
    // printf("  a = %.8f\n", a);
    // printf("  c = %.8f\n", c);
    // assert(a + c == a);
    // printf("a+c = %.8f\n", a + c);
    float f1, f2, f3;
    int i1 = 0x41000000;
    memcpy(&f1, &i1, sizeof(i1));
    int i2 = 0x41000001;
    memcpy(&f2, &i2, sizeof(i2));
    f3 = f2 - f1;
    int i3;
    memcpy(&i3, &f3, sizeof(f3));
    std::cout << "8的最小精度的浮点数对应的内存表述: " << std::hex << std::showbase << i3 << std::endl;
    // 此时的第二部分值再除以2，就是能描述的
    i3 -= 1 << 23;
    std::cout << i3 << std::endl;
    std::cout << std::hexfloat << std::noshowbase << 8.5 << std::endl;
}