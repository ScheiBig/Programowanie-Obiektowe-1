#include "resistor.hpp"

#include "util/ansi_text.hpp"

resistor::resistor(): __r(0) {}

resistor::resistor(double _r): __r(_r) {}

double& resistor::r() { return this->__r; }
double resistor::r() const { return this->__r; }

std::ostream& operator<< (std::ostream& _s, resistor const& _r)
{
    return _s
        << ANSI::b_black << "resistor: { "
        << ANSI::reset
        << "resistance [ohm]: " << _r.r()
        << ANSI::b_black << " }"
        << ANSI::reset;
}

resistor operator+ (resistor const& _r1, resistor const& _r2)
{
    return _r1.r() + _r2.r();
}

resistor operator* (resistor const& _r1, resistor const& _r2)
{
    return (_r1.r() * _r2.r())
        /
        (_r1.r() + _r2.r());
}
