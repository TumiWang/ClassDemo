#include <iostream>

class MyObject
{
public:
    MyObject(int index): index_(index) {}
    MyObject(const MyObject& other) = delete;

    ~MyObject() {}

    int GetValue() const {
        return index_;
    }

private:
    int index_;
};

int main()
{
    MyObject a(10);
    MyObject b = a;
    std::cout << a.GetValue() << " " << b.GetValue() << std::endl;
}