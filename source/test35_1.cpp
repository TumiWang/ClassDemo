#include <iostream>

struct S
{
    int a;
    int b;
    int c;
};

void print_s(const S& s) {
    std::cout << "a = " << s.a;
    std::cout << " b = " << s.b;
    std::cout << " c = " << s.c;
    std::cout << std::endl;
}

int main()
{
    S s1{1, 2};
    S s2;
    S s3{.b = 3};
    print_s(s1);
    print_s(s2);
    print_s(s3);
}