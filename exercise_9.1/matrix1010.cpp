#include "matrix1010.hpp"

#include <stdexcept>

#include "util/bformat.hpp"

double& matrix::operator() (size_t _i, size_t _j)
{
    if (0 > _i || _i > 9 || 0 > _j || _j > 9)
    {
        throw std::out_of_range(
            util::bformat("Indices [$, $]", _i, _j)
        );
    }
    return this->__m[_i][_j];
}
