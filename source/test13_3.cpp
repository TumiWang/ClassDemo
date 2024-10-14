#include <cassert>
#include <cstring>

#include <stdio.h>

int main()
{
    float a = 8.0;
    int b = 0x35000000;
    // b的二进制为0011 0101 0000 0000 0000 0000 0000 0000
    float c;
    memcpy(&c, &b, sizeof(b));
    assert(c != 0.0);
    printf("  a = %.8f\n", a);
    printf("  c = %.8f\n", c);
    assert(a + c == a);
    printf("a+c = %.8f\n", a + c);
}