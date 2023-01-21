#include "capacitor.hpp"

#include "util/ansi_text.hpp"

capacitor::capacitor(): __c(0) {}

capacitor::capacitor(double _c): __c(_c) {}

double capacitor::c() const { return this->__c; }
double& capacitor::c() { return this->__c; }

std::ostream& operator<< (std::ostream& _s, capacitor const& _c)
{
    return _s
        << ANSI::b_black << "capacitor: { "
        << ANSI::reset
        << "capacitance [F]: " << _c.c()
        << ANSI::b_black << " }"
        << ANSI::reset;
}

capacitor operator+ (capacitor const& _c1, capacitor const& _c2)
{
    return capacitor((_c1.c() * _c2.c())
        /
        (_c1.c() + _c2.c()));
}

capacitor operator* (capacitor const& _c1, capacitor const& _c2)
{
    return capacitor(_c1.c() + _c2.c());
}
