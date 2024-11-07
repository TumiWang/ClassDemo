struct A
{
    A(int a) {n = a;}
    int n;
};

struct B
{
    B(int b) {n = b;}
    mutable int n;
};

int main()
{
    A a1(0);
    a1.n = 10;
    const A a2(0);
    // a2.n = 10;
    B b1(0);
    b1.n = 10;
    const B b2(0);
    b2.n = 10;
}