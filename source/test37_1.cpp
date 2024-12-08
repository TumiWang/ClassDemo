#include <iostream>

class A
{
public:
    void test() {
        auto l = [this]() {
            std::cout << get_value() << std::endl;
            std::cout << m_ << std::endl;
        };
        l();
    }
protected:
    int get_value() { return 1; }
private:
    int m_ = 2;
};

int main()
{
    A a;
    a.test();
}