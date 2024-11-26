#include <iostream>

struct A
{
    void print1() { 
        std::cout << "Call A::print1" << std::endl;
    }
    void print2() { 
        std::cout << "Call A::print2" << std::endl;
    }
    void print3() { 
        std::cout << "Call A::print3" << std::endl;
    }
};

int main()
{
    // void(A::*funcs[])() = { &A::print1, &A::print2, &A::print3 };
    using a_struct_func_pointer_type = void (A::*)();
    a_struct_func_pointer_type funcs [] = { &A::print1, &A::print2, &A::print3 };

    A a;
    for (auto& func: funcs) {
        (a.*func)();
    }
}