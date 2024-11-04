namespace N
{
    void f(int) {
        // ...
    }

    void g(int) {
        // ...
    }
}

int main()
{
    using N::f;
    f(1);
    // g(1);
}