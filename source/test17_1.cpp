#include <iostream>

class A
{
public:
    virtual ~A() = default;
    virtual void show() {
        std::cout << "This is a A" << std::endl;
    }
    void assertA() {
        std::cout << "I belong to A" << std::endl;
    }
private:
    int v_;
};

class B
{
public:
    virtual ~B() = default;
    virtual void info() {
        std::cout << "This is a B" << std::endl;
    }
    void assertB() {
        std::cout << "I belong to B" << std::endl;
    }
private:
    int v_;
};

class C: public A, public B
{
public:
    void show() override {
        std::cout << "This is a C" << std::endl;
    }
    void info() override {
        std::cout << "This is a A + B" << std::endl;
    }
};

int main()
{
    std::cout << "场景一" << std::endl;
    {
        A* a = new A;
        C* c = dynamic_cast<C*>(a);
        if (c == nullptr) {
            std::cout << "Failed to c from a" << std::endl;
        } else {
            c->show();
        }
        delete a;
    }
    std::cout << "场景二" << std::endl;
    {
        A* a = new C;
        C* c = dynamic_cast<C*>(a);
        if (c == nullptr) {
            std::cout << "Failed to c from a" << std::endl;
        } else {
            c->show();
        }
        delete a;
    }
    std::cout << "场景三" << std::endl;
    {
        A* a = new A;
        a->assertA();
        B* b = dynamic_cast<B*>(a);
        if (b == nullptr) {
            std::cout << "Failed to b from a" << std::endl;
        } else {
            b->assertB();
            b->info();
        }
        delete a;
    }
    std::cout << "场景四" << std::endl;
    {
        A* a = new C;
        a->assertA();
        B* b = dynamic_cast<B*>(a);
        if (b == nullptr) {
            std::cout << "Failed to b from a" << std::endl;
        } else {
            b->assertB();
            b->info();
        }
        delete a;
    }
}