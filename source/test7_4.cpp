#include <iostream>

// typedef int MyInt;
// typedef int MyBuff[64];
// typedef int *MyIntPtr;
// typedef int (&myfunc)(int);
// typedef int (*myfuncptr)(int);
typedef int MyInt, MyBuff[64], *MyIntPtr, (&myfunc)(int), (*myfuncptr)(int);

int test(int arg)
{
    return arg;
}

int main()
{
    // sizeof(MyInt)=4
    std::cout << "sizeof(MyInt)=" << sizeof(MyInt) << std::endl;
    // sizeof(MyBuff)=256  即sizeof(int) * 64
    std::cout << "sizeof(MyBuff)=" << sizeof(MyBuff) << std::endl;
    // sizeof(MyIntPtr)=8 MyIntPtr是指针类型，在64位系统占用8字节
    std::cout << "sizeof(MyIntPtr)=" << sizeof(MyIntPtr) << std::endl;
    myfunc func1 = test;
    std::cout << "call func1(100) and result:" << func1(100) << std::endl;
    myfuncptr func2 = &test;
    std::cout << "call func2(200) and result:" << (*func2)(200) << std::endl;
}