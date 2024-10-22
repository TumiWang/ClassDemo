#include <iostream>

class A
{
public:
    virtual ~A() = default;
    virtual void test() {
        std::cout << "This is a A" << std::endl;
    }
private:
    int v_;
};

class B: public A
{
public:
    void test() override {
        std::cout << "This is a B" << std::endl;
    }
};

int main()
{
    A* a = new A;
    B* b1 = dynamic_cast<B*>(a);
    B* b2 = static_cast<B*>(a);
    if (b1) {
        b1->test();
    } else {
        std::cout << "b1 is nullptr" << std::endl;
    }
    if (b2) {
        b2->test();
    } else {
        std::cout << "b2 is nullptr" << std::endl;
    }
    delete a;
}