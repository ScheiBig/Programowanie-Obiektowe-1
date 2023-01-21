#include <vector>
#include <cstdlib>

class matrix
{
private:
    std::vector<std::vector<double>> __m;
public:
    matrix(size_t _m, size_t _n);

    double& operator() (size_t _i, size_t _j);
};
