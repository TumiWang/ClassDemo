#include <stdio.h>

#define OffsetOfStruct(Type, attr) ((size_t)(&(((Type*)0)->attr)))

class A
{
public:
    A() = default;
    ~A() = default;

public:
    int index_;
};

class B
{
public:
    B() = default;
    virtual ~B() = default;

public:
    int index_;
};

int main()
{
    printf("Offset of A::index_ is %ld\n", OffsetOfStruct(A, index_));
    printf("Offset of B::index_ is %ld\n", OffsetOfStruct(B, index_));
}