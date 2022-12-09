#include <iostream>
#include <limits>
#include <string>

#include "complex.hpp"
#include "util/ansi_text.hpp"

int main()
{
    // Complex c1;
    // Complex c2(1);
    // Complex c3(2, 3);

    // Complex c4 = 4;
    // Complex c5 = 5_i;

    // Complex c6 = 6 + 7_i;
    // Complex c7 = 8 - 9_i;

    std::cout
        << ANSI::cyan << "Enter a first number (A±Bi): "
        << ANSI::reset;
    Complex c1;
    std::cin >> c1;

    std::cout
        << ANSI::b_cyan << "Enter a second  number (A±Bi): "
        << ANSI::reset;
    Complex c2;
    std::cin >> c2;

    std::cout 
        << c1 
        << ANSI::b_black << " + " 
        << ANSI::reset << c2 
        << ANSI::b_black << " = " 
        << ANSI::reset << c1 + c2 << util::nl;
    std::cout 
        << c1 
        << ANSI::b_black << " - " 
        << ANSI::reset << c2 
        << ANSI::b_black << " = " 
        << ANSI::reset << c1 - c2 << util::nl;
    std::cout 
        << c1 
        << ANSI::b_black << " * " 
        << ANSI::reset << c2 
        << ANSI::b_black << " = " 
        << ANSI::reset << c1 * c2 << util::nl;
    std::cout 
        << c1 
        << ANSI::b_black << " / " 
        << ANSI::reset << c2 
        << ANSI::b_black << " = " 
        << ANSI::reset << c1 / c2 << util::nl;
    
    return 0;
}
