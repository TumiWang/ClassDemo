#include <stdio.h>

class MyObject
{
public:
    explicit MyObject(int index): index1_(index), index2_(-1) {
        printf("创建一个参数构造函数 -- %p, ndex1:%d, index2:%d\n", this, index1_, index2_);
    }

    explicit MyObject(int index1, int index2): index1_(index1), index2_(index2) {
        printf("创建两个参数构造函数 -- %p, ndex1:%d, index2:%d\n", this, index1_, index2_);
    }

    ~MyObject() {
        printf("析构函数 -- %p, index1:%d, index2:%d\n", this, index1_, index2_);
    }

    void show() const {
        printf("展示信息 -- %p, index1:%d, index2:%d\n", this, index1_, index2_);
    }

private:
    int index1_;
    int index2_;
};

void f(MyObject o) {
    printf("调用函数f的第一个重载\n");
    o.show();
}

void f(MyObject o, int) {
    printf("调用函数f的第二个重载\n");
    o.show();
}

int main()
{
    // f(1); // 这句会编译失败
    printf("  ----------  \n");
    // f(1, 2); // 这句会编译失败
    printf("  ----------  \n");
    // f({1, 2}); // 这句会编译失败
}