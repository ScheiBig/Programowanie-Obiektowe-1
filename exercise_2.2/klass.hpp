#pragma once

#include "util/setter.hpp"

class klass
{
private:
    int __integer{};
    util::setter<int> __integer_s{ __integer };
    char __character{};
    util::setter<char> __character_s{ __character };
    double __floating_point{};
    util::setter<double> __floating_point_s{ __floating_point };
public:
    int const& integer() const;
    char const& character() const;
    double const& floating_point() const;

    auto integer();
    auto character();
    auto floating_point();

    klass();
    klass(int _integer);
    klass(char _character);
    klass(double _floating_point);
};