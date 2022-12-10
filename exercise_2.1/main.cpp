#include <iostream>

#include "euc_vector.hpp"
#include "util/ansi_text.hpp"

int main()
{

    euc_vector v1{
        point{1,1}, point{5,6}
    };
    {

        {
            euc_vector v2{
                point{-2,-2}, point{2,1}
            };

            std::cout << "v1 + v2" << v1 + v2 << util::nl;
            std::cout << "v1 - v2" << v1 - v2 << util::nl;
        }

        euc_vector v3{
            point{4, 5}, point{5,6}
        };

        std::cout << "v1 + v3" << v1 + v3 << util::nl;
        std::cout << "v1 - v3" << v1 - v3 << util::nl;
    }
    std::cout << "v1 * 8" << v1 * 8 << util::nl;
    std::cout
        << ANSI::b_magenta << "Objects created: "
        << ANSI::reset << euc_vector::created_vectors() << util::nl;

    return 0;
}
