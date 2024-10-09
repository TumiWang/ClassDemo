#include <iostream>
#include <utility>

void f(int& v) {
    std::cout << "使用了左值" << std::endl;
}

void f(int&& v) {
    std::cout << "使用了右值" << std::endl;
}

template<typename T>
void wrap1(T&& v) {
    f(v);
}

template<typename T>
void wrap2(T&& v) {
    f(std::forward<T>(v));
}

int main()
{
    int a = 1;
    int& b = a;
    f(a); // 左值
    f(b); // 左值
    f(3); // 右值
    // 函数wrap1都转发为左值了
    wrap1(a); // 左值
    wrap1(b); // 左值
    wrap1(3); // 左值
    // 函数wrap2都转发后 参数的左值还是右值都没有改变
    wrap2(a); // 左值
    wrap2(b); // 左值
    wrap2(3); // 右值
}