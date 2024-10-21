#include <stdio.h>

#include <memory>

class MyObject
{
public:
    // 默认构造函数
    MyObject(): buff_(nullptr), buff_size_(0) {
        printf("创建默认构造函数 -- %p\n", this);
    }

    // 有参构造函数
    MyObject(char* buff, size_t buff_size): buff_(buff), buff_size_(buff_size) {
        printf("创建有参构造函数1 -- %p, buff:%p size:%zd\n", this, buff_, buff_size_);
    }

    // 有参构造函数
    MyObject(size_t buff_size): buff_(new char[buff_size]), buff_size_(buff_size) {
        printf("创建有参构造函数2 -- %p, buff:%p size:%zd\n", this, buff_, buff_size_);
    }

    // 拷贝构造函数
    MyObject(const MyObject& other) {
        buff_size_ = other.buff_size_;
        buff_ = new char[buff_size_];
        memcpy(buff_, other.buff_, buff_size_);
        printf("创建拷贝构造函数 -- %p, buff:%p size:%zd, from %p\n", this, buff_, buff_size_, &other);
    }

    // 移动构造函数
    MyObject(MyObject&& other) {
        buff_ = other.buff_;
        buff_size_ = other.buff_size_;
        other.buff_ = nullptr;
        other.buff_size_ = 0;
        printf("创建移动构造函数 -- %p, buff:%p size:%zd, from %p\n", this, buff_, buff_size_, &other);
    }

    // 析构函数
    ~MyObject() {
        printf("析构函数 -- %pp, buff:%p size:%zd\n", this, buff_, buff_size_);
        if (buff_) {
            delete[] buff_;
            buff_ = nullptr;
        }
    }

    // 拷贝绑定操作
    MyObject& operator=(const MyObject& other) {
        if (buff_) {
            delete[] buff_;
            buff_ = nullptr;
        }
        buff_size_ = other.buff_size_;
        buff_ = new char[buff_size_];
        memcpy(buff_, other.buff_, buff_size_);
        printf("拷贝绑定操作 -- %p, buff:%p size:%zd, from %p\n", this, buff_, buff_size_, &other);
        return *this;
    }

    // 移动绑定操作
    MyObject& operator=(MyObject&& other) {
        if (buff_) {
            delete[] buff_;
            buff_ = nullptr;
        }
        buff_ = other.buff_;
        buff_size_ = other.buff_size_;
        other.buff_ = nullptr;
        other.buff_size_ = 0;
        printf("移动绑定操作 -- %p, buff:%p size:%zd, from %p\n", this, buff_, buff_size_, &other);
        return *this;
    }

private:
    char* buff_;
    size_t buff_size_;
};

int main()
{
    MyObject a(10);
    MyObject b;
    MyObject c;
    b = a;
    c = std::move(a);
}