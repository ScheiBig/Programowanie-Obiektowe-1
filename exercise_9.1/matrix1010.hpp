#include <array>
#include <cstdlib>

class matrix
{
private:
    std::array< std::array<double, 10>, 10> __m = {};
public:

    double& operator() (size_t _i, size_t _j);
};
