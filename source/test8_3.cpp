#include <stdio.h>

class MyObject
{
public:
    // 默认构造函数
    MyObject() noexcept : index_(0) {
        printf("创建默认构造函数 -- %p\n", this);
    }

    // 有参构造函数
    explicit MyObject(int index) noexcept : index_(index) {
        printf("创建有参构造函数 -- %p, index:%d\n", this, index_);
    }

    // 拷贝构造函数
    MyObject(const MyObject& other) noexcept {
        printf("创建拷贝构造函数 -- %p(index:%d), from %p(index:%d)\n", this, index_, &other, other.index_);
        index_ = other.index_;
    }

    // 移动构造函数
    MyObject(MyObject&& other) noexcept {
        printf("创建移动构造函数 -- %p(index:%d), from %p(index:%d)\n", this, index_, &other, other.index_);
        index_ = other.index_;
        other.index_ = 0;
    }

    // 析构函数
    ~MyObject() {
        printf("析构函数 -- %p\n", this);
    }

    // 拷贝绑定操作
    MyObject& operator=(const MyObject& other) noexcept {
        printf("拷贝绑定操作 -- %p(index:%d), from %p(index:%d)\n", this, index_, &other, other.index_);
        index_ = other.index_;
        return *this;
    }

    // 移动绑定操作
    MyObject& operator=(MyObject&& other) noexcept {
        printf("移动绑定操作 -- %p(index:%d), from %p(index:%d)\n", this, index_, &other, other.index_);
        index_ = other.index_;
        other.index_ = 0;
        return *this;
    }

private:
    int index_;
};

MyObject& GetMyObject()
{
    MyObject test(1);
    MyObject result(2);
    return result;
}

int main()
{
    int a = 3;
    MyObject b = GetMyObject();
    int c = 4;
    printf("a变量的地址是 %p\n", &a);
    printf("c变量的地址是 %p\n", &c);
}