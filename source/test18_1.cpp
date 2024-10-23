#include <iostream>

template<class T>
class Point final
{
public:
    Point(T x, T y) : x_(x), y_(y) {}
    void info() const {
        std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
    }
private:
    T x_;
    T y_;
};

int main()
{
    Point<float> a(0.5f, 1.2f);
    Point b(1.1f, 2.1f);
    a.info();
    b.info();
}