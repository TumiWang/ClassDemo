#include <cassert>
#include <cstring>

int main()
{
    int a = 0x3f400000;
    // a 的二进制为 0011 1111 0100 0000 0000 0000 0000 0000
    float b;
    memcpy(&b, &a, sizeof(a));
    assert(b == 0.75);
    assert((float)a != 0.75);
    assert((int)b != a);
    int c = 0x3FFFFFFF;
    // a 的二进制为 0011 1111 1111 1111 1111 1111 1111 1111
    float d;
    memcpy(&d, &c, sizeof(c));
    float e = 2.0;
    // e 的内存值(十六进制)为 40 00 00 00
    // 如果调试时查看，因为CPU是小端(Little-Endian)
    // 看到是内存值为 00 00 00 40
    int f;
    memcpy(&f, &e, sizeof(e));
    assert(d != e);
    assert(f == c + 1); // 0x40000000 == 0x3FFFFFFF + 1
}