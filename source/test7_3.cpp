#include <stdio.h>

#define OffsetOfStruct(Type, attr) ((size_t)(&(((Type*)0)->attr)))

struct MyStructType1
{
    char a;
    char b;
};

struct MyStructType2
{
    char a;
    alignas(4) char b;
};

struct MyStructType3
{
    char a;
    alignas(4) char b;
    char c;
};

class MyClassType1
{
public:
    MyClassType1() = default;
    ~MyClassType1() = default;

public:
    char a;
    char b;
};

class MyClassType2
{
public:
    MyClassType2() = default;
    ~MyClassType2() = default;

public:
    char a;
    alignas(4) char b;
};

class MyBaseClass
{
public:
    MyBaseClass() = default;
    virtual ~MyBaseClass() = default;

public:
    virtual void show() {}
};

class MyClassType3: public MyBaseClass
{
public:
    MyClassType3() = default;
    virtual ~MyClassType3() = default;

public:
    char a;
    char b;
};

class MyClassType4: public MyBaseClass
{
public:
    MyClassType4() = default;
    virtual ~MyClassType4() = default;

public:
    char a;
    alignas(4) char b;
};

class MyClassType5: public MyBaseClass
{
public:
    MyClassType5() = default;
    virtual ~MyClassType5() = default;

public:
    char a;
    alignas(8) char b;
};

class MyClassType6: public MyClassType5
{
public:
    MyClassType6() = default;
    virtual ~MyClassType6() = default;

public:
    alignas(2) char c;
};

int main()
{
    printf("Size of MyStructType1: %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyStructType1),
        OffsetOfStruct(MyStructType1, a), OffsetOfStruct(MyStructType1, b));
    printf("Size of MyStructType2: %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyStructType2),
        OffsetOfStruct(MyStructType2, a), OffsetOfStruct(MyStructType2, b));
    printf("Size of MyStructType3: %ld, offset of a: %ld, offset of b: %ld, offset of c: %ld\n",
        sizeof(MyStructType3),
        OffsetOfStruct(MyStructType3, a), OffsetOfStruct(MyStructType3, b), OffsetOfStruct(MyStructType3, c));

    printf("Size of MyClassType1:  %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyClassType1),
        OffsetOfStruct(MyClassType1, a), OffsetOfStruct(MyClassType1, b));
    printf("Size of MyClassType2:  %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyClassType2),
        OffsetOfStruct(MyClassType2, a), OffsetOfStruct(MyClassType2, b));
    printf("Size of MyClassType3: %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyClassType3),
        OffsetOfStruct(MyClassType3, a), OffsetOfStruct(MyClassType3, b));
    printf("Size of MyClassType4: %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyClassType4),
        OffsetOfStruct(MyClassType4, a), OffsetOfStruct(MyClassType4, b));
    printf("Size of MyClassType5: %ld, offset of a: %ld, offset of b: %ld\n",
        sizeof(MyClassType5),
        OffsetOfStruct(MyClassType5, a), OffsetOfStruct(MyClassType5, b));
    printf("Size of MyClassType6: %ld, offset of a: %ld, offset of b: %ld, offset of c: %ld\n",
        sizeof(MyClassType6),
        OffsetOfStruct(MyClassType6, a), OffsetOfStruct(MyClassType6, b), OffsetOfStruct(MyClassType6, c));
}