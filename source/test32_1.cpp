#include <iostream>

class A
{
public:
    void f1() {
        std::cout << "Call f1" << std::endl;
    }
    virtual void f2() {
        std::cout << "Call f2" << std::endl;
    }
    void f3() {
        std::cout << "Call f3 -- " << n_ << std::endl;
    }
private:
    int n_;
};

int main()
{
    A* p = nullptr;
    p->f1();
    // p->f2(); // 运行时导致崩溃
    // p->f3(); // 运行时导致崩溃
}