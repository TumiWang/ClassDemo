#include <iostream>

template<class T1, class T2>
struct S
{
    T1 a;
    T2 b;
};

int main()
{
    S<int, int> s1{1};
    S<char, unsigned char> s3{.b = 'b'};
}