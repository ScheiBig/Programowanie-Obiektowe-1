#pragma once

#include <iostream>

class resistor
{
private:
    double __r;
public:
    resistor();
    resistor(double _r);

    double& r();
    double r() const;

    friend std::ostream& operator<< (std::ostream& _s, resistor const& _r);
    friend resistor operator+ (resistor const& _r1, resistor const& _r2);
    friend resistor operator* (resistor const& _r1, resistor const& _r2);
};
