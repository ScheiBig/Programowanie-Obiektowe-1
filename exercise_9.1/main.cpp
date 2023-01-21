#include "matrix1010.hpp"

int main()
{
    matrix m;

    m(6, 9) = 420; // ok

    m(11, -2) = 8; // throws

    return 0;
}
