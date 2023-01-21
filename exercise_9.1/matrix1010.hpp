#include <array>
#include <cstdlib>

class matrix1010
{
private:
    std::array< std::array<double, 10>, 10> _m = {};
public:

    double& operator() (size_t _i, size_t _j);
};
