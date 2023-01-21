#include <iostream>

#include "resistor.hpp"

int main()
{
    resistor r1{ 5 };
    resistor r2{ 12 };
    resistor r3;

    std::cout << r1 << "\n" << r2 << "\n" << r3 << "\n";
    std::cout << "r1 -- r2 = " << (r1 + r2) << "\n";
    std::cout << "r1 || r2 = " << (r1 * r2) << "\n";

    return 0;
}
