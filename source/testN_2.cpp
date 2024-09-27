#include <stdio.h>

#include <algorithm>
#include <memory>
#include <vector>

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

    // 析构函数
    ~MyObject() {
        printf("析构函数 -- %p\n", this);
    }

    // 拷贝绑定操作
    MyObject& operator=(const MyObject& other) {
        printf("拷贝绑定操作 -- %p(index:%d), from %p(index:%d)\n", this, index_, &other, other.index_);
        index_ = other.index_;
        return *this;
    }

    // 移动绑定操作
    MyObject& operator=(MyObject&& other) {
        printf("移动绑定操作 -- %p(index:%d), from %p(index:%d)\n", this, index_, &other, other.index_);
        index_ = other.index_;
        other.index_ = 0;
        return *this;
    }

    int GetValue() const {
        return index_;
    }

private:
    int index_;
};

int main()
{
    printf("准备初始化 items\n");
    std::vector<MyObject> items;
    items.reserve(4);
    items.emplace_back(1);
    items.emplace_back(2);
    items.emplace_back(3);
    printf("初始化 items 完成\n");
    auto needToRemove = [](const MyObject& o) -> bool {
        return o.GetValue() % 2 == 0;
    };
    auto itor = std::remove_if(items.begin(), items.end(), needToRemove);
    items.erase(itor, items.end());
}