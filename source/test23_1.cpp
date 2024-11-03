#include <iostream>

// 全局命名空间
int a = 11;
int d = 14;

// 命名空间 N
namespace N
{
    int b = 22;
}

// 匿名命名空间
namespace
{
    int c = 33;
    int d = 34;
    int getD() {
        return d;
    }
}

int main()
{
    std::cout << a << std::endl; // 11
    std::cout << N::b << std::endl; // 22
    std::cout << c << std::endl; // 33
    {
        using namespace N;
        std::cout << b << std::endl; // 22
    }
    // std::cout << b << std::endl;
    // std::cout << d << std::endl;
    std::cout << ::d << std::endl; // 14
    std::cout << getD() << std::endl; // 34
}