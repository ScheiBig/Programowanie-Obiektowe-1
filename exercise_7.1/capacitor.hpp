#pragma once

#include <iostream>

class capacitor
{
private:
    double __c;
public:
    capacitor();
    capacitor(double _c);

    double c() const;
    double& c();

    friend std::ostream& operator<<(std::ostream& _s, capacitor const& _c);
    friend capacitor operator+(capacitor const& _c1, capacitor const& _c2);
    friend capacitor operator*(capacitor const& _c1, capacitor const& _c2);
};
