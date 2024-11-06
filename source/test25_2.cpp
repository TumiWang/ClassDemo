#include <iostream>

class A
{
public:
    void f() {}
    char n_;
    void test(int m_) {
        int f = n_;
        std::cout << n_ << std::endl;
        std::cout << m_ << std::endl;
    }
private:
    // int n_;
    // int f;
    int m_;
};

// 不展示main函数
int main()
{
}