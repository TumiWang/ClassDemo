#include <stdio.h>

#include <memory>

#include <type_traits>

#include <iostream>

class MyObject
{
public:
    // 默认构造函数
    MyObject(): index_(0) {
        printf("创建默认构造函数 -- %p\n", this);
    }

    // 有参构造函数
    explicit MyObject(int index): index_(index) {
        printf("创建有参构造函数 -- %p, index:%d\n", this, index_);
    }

    // // 拷贝构造函数
    // MyObject(const MyObject& other) {
    //     printf("创建拷贝构造函数 -- %p, from %p\n", this, &other);
    //     index_ = other.index_;
    // }

    // // 移动构造函数
    // MyObject(MyObject&& other) noexcept {
    //     printf("创建移动构造函数 -- %p, from %p\n", this, &other);
    //     index_ = other.index_;
    //     other.index_ = 0;
    // }

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

void test_unique_ptr(std::unique_ptr<MyObject> ptr) {
    if (!!ptr) {
        printf("test_unique_ptr ptr is nullptr\n");
        return;
    }
    ptr->show();
}

int main()
{
    // printf("场景1:\n");
    // {
    //     std::unique_ptr<MyObject> a(new MyObject(1));
    //     std::unique_ptr<MyObject> b = std::move(a);
    //     printf("tttt\n");
    // }
    // printf("场景2:\n");
    // {
    //     std::unique_ptr<MyObject> a = std::make_unique<MyObject>(2);
    //     test_unique_ptr(std::move(a));
    // }
    std::cout << std::is_move_constructible<MyObject>::value << std::endl;
}