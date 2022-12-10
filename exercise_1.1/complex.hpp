#pragma once

#include <iostream>

class complex
{
public:
    complex(double _re = 0, double _im = 0);
    ~complex();

    friend std::ostream& operator<<(std::ostream& s, const complex& _c);
    /// @throw std::invalid_argument
    friend std::istream& operator>>(std::istream& s, complex& _c) noexcept(false);

    friend complex operator+(double const _re, complex const& _c);
    friend complex operator-(double const _re, complex const& _c);

    friend complex operator +(complex const& _c1, complex const& _c2);
    friend complex operator -(complex const& _c1, complex const& _c2);
    friend complex operator *(complex const& _c1, complex const& _c2);
    friend complex operator /(complex const& _c1, complex const& _c2);

    double __re;
    double __im;
};

complex operator""_i(long double _im);
complex operator""_i(unsigned long long _im);
