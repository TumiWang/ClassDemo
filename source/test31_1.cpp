#include <type_traits>

class A
{
friend void f();

public:
    void f1() {}

protected:
    void f2() {}
    static void f3() {}

private:
    int n_;
};

void f() {
    static_assert(std::is_member_function_pointer<decltype(&A::f2)>::value);
    static_assert(std::is_member_pointer<decltype(&A::n_)>::value);
    static_assert(std::is_member_object_pointer<decltype(&A::n_)>::value);
    static_assert(std::is_pointer<decltype(&A::f3)>::value);
    static_assert(std::is_function<decltype(A::f3)>::value);
}

int main()
{
    static_assert(std::is_member_function_pointer<decltype(&A::f1)>::value);
    static_assert(std::is_member_pointer<decltype(&A::f1)>::value);
    static_assert(not std::is_member_object_pointer<decltype(&A::f1)>::value);
    static_assert(not std::is_function<decltype(&A::f1)>::value);
    static_assert(not std::is_member_pointer<decltype(&f)>::value);
    // static_assert(std::is_member_function_pointer<decltype(&A::f2)>::value);
}