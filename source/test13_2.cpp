#include <cassert>
#include <string.h>

int main()
{
    int a = 0x00800000;
    float b;
    memcpy(&b, &a, sizeof(a));
    assert(b != 0); // b 不等于 0
    assert(10.0 + b == 10.0); // 10 加上一个不等于0的浮点数后，还是等于10
}