// 模板模板参数例子
template<template<typename> typename C>
class MyData
{
public:
    C<int> v_;
};

// 下面为使用举例
template<typename T>
class A{};

int main()
{
    MyData<A> data;
}