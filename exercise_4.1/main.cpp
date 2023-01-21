#include <iostream>

#include "solid.hpp"

int main()
{
    sphere s;
    s._r = 5;
    std::cout << "sphere area: " << s.area() << "\n";
    std::cout << "sphere volume: " << s.volume() << "\n";
    std::cout << "sphere diagonal: " << s.diagonal() << "\n\n";

    cuboid c;
    c._a = 5;
    c._b = 6;
    c._c = 7;
    std::cout << "cuboid area: " << c.area() << "\n";
    std::cout << "cuboid volume: " << c.volume() << "\n";
    std::cout << "cuboid diagonal: " << c.diagonal() << "\n\n";

    pyramid p;
    p._a = 5;
    p._b = 6;
    p._h = 8;
    std::cout << "pyramid area: " << p.area() << "\n";
    std::cout << "pyramid volume: " << p.volume() << "\n";
    std::cout << "pyramid diagonal: " << p.diagonal() << "\n\n";
    return 0;
}
