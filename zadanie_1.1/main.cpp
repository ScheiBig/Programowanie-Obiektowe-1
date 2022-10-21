#include <iostream>
#include <limits>
#include <string>

#include "complex.hpp"

using std::cin;
using std::cout;
using std::string;

static const char* nl = "\n";

int main()
{
    // Complex c1;
    // Complex c2(1);
    // Complex c3(2, 3);

    // Complex c4 = 4;
    // Complex c5 = 5_i;

    // Complex c6 = 6 + 7_i;
    // Complex c7 = 8 - 9_i;

    cout << "Enter a first number (A±Bi): ";
    Complex c1;
    cin >> c1;

    cout << "Enter a second  number (A±Bi): ";
    Complex c2;
    cin >> c2;

    cout << c1 << " + " << c2 << " = " << c1 + c2 << nl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << nl;
    cout << c1 << " * " << c2 << " = " << c1 * c2 << nl;
    cout << c1 << " / " << c2 << " = " << c1 / c2 << nl;
    
    return 0;
}
