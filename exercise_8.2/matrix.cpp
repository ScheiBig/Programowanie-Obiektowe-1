#include "matrix.hpp"

#include <stdexcept>

#include "util/bformat.hpp"

matrix::matrix(size_t _m, size_t _n): __m(_m)
{
    for (auto& v : this->__m)
    {
        v = std::vector<double>(_n);
    }
}

double& matrix::operator() (size_t _i, size_t _j)
{
    if (0 > _i || _i > this->__m.size() || 0 > _j || _j > this->__m[0].size())
    {
        throw std::out_of_range(
            util::bformat("Indices [$, $] out of bounds for [$, $]", _i, _j, this->__m.size(), this->__m[0].size())
        );
    }
    return this->__m[_i][_j];
}
