#include "matrix.hpp"

int main()
{
    matrix m{ 3,7 };

    m(2, 1) = 128; // ok
    
    m(6, 9) = 420; // throws

    return 0;
}
