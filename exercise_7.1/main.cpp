#include <iostream>

#include "capacitor.hpp"

int main()
{
    capacitor c1{ 5 };
    capacitor c2{ 12 };
    capacitor c3;

    std::cout << c1 << "\n" << c2 << "\n" << c3 << "\n";
    std::cout << "c1 -- c2 = " << (c1 + c2) << "\n";
    std::cout << "c1 || c2 = " << (c1 * c2) << "\n";

    return 0;
}
