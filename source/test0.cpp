#include <stdio.h>

#include <memory>

class MyObject
{
public:
    // 方法1: 默认构造函数
    MyObject(): index_(0) {
        printf("创建默认构造函数 -- %p\n", this);
    }

    // 方法2: 有参构造函数
    // explicit
    MyObject(int index): index_(index) {
        printf("创建有参构造函数 -- %p, index:%d\n", this, index_);
    }

    // 方法3: 拷贝构造函数
    MyObject(const MyObject& other) {
        printf("创建拷贝构造函数 -- %p, from %p\n", this, &other);
        index_ = other.index_;
    }

    // 方法4: 移动构造函数
    MyObject(MyObject&& other) noexcept {
        printf("创建移动构造函数 -- %p, from %p\n", this, &other);
        index_ = other.index_;
        other.index_ = 0;
    }

    // 方法5: 析构函数
    ~MyObject() {
        printf("析构函数 -- %p\n", this);
    }

    // 方法6: 拷贝绑定操作
    MyObject& operator=(const MyObject& other) {
        printf("拷贝绑定操作 -- %p, from %p\n", this, &other);
        index_ = other.index_;
        return *this;
    }

    // 方法7: 移动绑定操作
    MyObject& operator=(MyObject&& other) {
        printf("移动绑定操作 -- %p, from %p\n", this, &other);
        index_ = other.index_;
        other.index_ = 0;
        return *this;
    }

private:
    int index_;
};

int main()
{
    MyObject a;
    MyObject b(1);
    MyObject c = b;
    MyObject d = std::move(b);
    b = c;
    a = std::move(c);
}