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

    // 拷贝构造函数
    MyObject(const MyObject& other) {
        printf("创建拷贝构造函数 -- %p, from %p\n", this, &other);
        index_ = other.index_;
    }

    // 移动构造函数
    MyObject(MyObject&& other) {
        printf("创建移动构造函数 -- %p, from %p\n", this, &other);
        index_ = other.index_;
        other.index_ = 0;
    }

    // // 不可变移动构造函数
    // MyObject(const MyObject&& other) {
    //     printf("创建不可变移动构造函数 -- %p, from %p\n", this, &other);
    //     index_ = other.index_;
    // }

    // 析构函数
    ~MyObject() {
        printf("析构函数 -- %p\n", this);
    }

private:
    int index_;
};

int main()
{
    const MyObject a(1);
    MyObject b(2);
    MyObject c = std::move(b);
    MyObject d = std::move(a);
}