#include <iostream>

int flag = 0;

class A final
{
public:
    A(): flag_(++flag) {
        std::cout << "Construct A -- " << flag_ << std::endl;
    }
    ~A() {
        std::cout << "Destruct A -- " << flag_ << std::endl;
    }
    void info() {
        std::cout << "Run A -- "<< flag_ << std::endl;
    }
private:
    int flag_;
};

void test()
{
    std::cout << "Enter test function" << std::endl;
    static A a; // flag_ = 3
    a.info();
    std::cout << "Exit test function" << std::endl;
}

static A a1; // flag_ = 1

int main()
{
    A a2; // flag_ = 2
    test();
    a2.info();
    test();
}