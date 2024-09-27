#include <stdio.h>

#include <memory>

class MyObject
{
public:
    // 默认构造函数
    MyObject(): index_(0) {
        printf("创建默认构造函数 -- %p\n", this);
    }

    // 有参构造函数
    MyObject(int index): index_(index) {
        printf("创建有参构造函数 -- %p, index:%d\n", this, index_);
    }

    // 不变拷贝构造函数
    MyObject(const MyObject& other) {
        printf("创建不变拷贝构造函数 -- %p, from %p\n", this, &other);
        index_ = other.index_;
    }

    // 可变拷贝构造函数
    MyObject(MyObject& other) {
        printf("创建可变拷贝构造函数 -- %p, from %p\n", this, &other);
        index_ = other.index_;
        other.index_ = -1;
    }

    // 析构函数
    ~MyObject() {
        printf("析构函数 -- %p\n", this);
    }

    void show() const {
        printf("展示信息 -- %p, index:%d\n", this, index_);
    }

private:
    int index_;
};

int main()
{
    const MyObject a(1);
    MyObject b(1);
    b.show();
    MyObject c = b;
    b.show();
    a.show();
    MyObject d = a;
    a.show();
    MyObject e = std::move(d);
}