#include <type_traits>

template<int vertex_count, 
         typename std::enable_if<(vertex_count > 1), bool>::type = true>
struct Shape
{
    // ...
};

int main()
{
    Shape<3> triangle;
    Shape<4> quad;
    // Shape<2.5> s1;
    // Shape<-5> s2;
}