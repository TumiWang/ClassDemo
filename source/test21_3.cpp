#include <type_traits>

template<int vertex_count = 2, 
         typename std::enable_if<(vertex_count > 1), bool>::type = true>
struct Shape
{
    // ...
};

int main()
{
    Shape<3> triangle;
    Shape<> lineSegment1;
    Shape<2> lineSegment2;
}