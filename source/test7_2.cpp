#include <iostream>

int main()
{
    switch (size_t bits = sizeof(void*))
    {
    case 4:
        std::cout << "这是一个32位程序" << std::endl;
        break;
    case 8:
        std::cout << "这是一个64位程序" << std::endl;
        break;
    default:
        std::cout << "这是一个" << bits * 8 << "位程序" << std::endl;
        break;
    }
    // 上面代码等效于
    // std::cout << "这是一个" << sizeof(void*) * 8 << "位程序" << std::endl;
}