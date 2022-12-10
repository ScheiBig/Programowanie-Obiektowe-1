#include "complex.hpp"

#include <cmath>
#include <cctype>
#include <limits>

complex::complex(double _re, double _im): __re(_re), __im(_im) {}

complex::~complex() {}

std::ostream& operator<<(std::ostream& _s, complex const& _c)
{
    return _s << _c.__re << (_c.__im < 0 ? "" : "+") << _c.__im << "i";
}

enum struct parsing_error
{
    Real, Imag, Char, None
};

std::istream& operator>>(std::istream& s, complex& _c) noexcept(false)
{
    double a;
    double b;
    char i;

    enum parsing_error err = parsing_error::None;

    if (!(s >> a)) err = parsing_error::Real;
    if (!(s >> b)) err = parsing_error::Imag;
    if (!(s >> i) || std::tolower(i) != 'i') err = parsing_error::Char;

    switch (err)
    {
    case parsing_error::Real: throw std::invalid_argument("Invalid character in *real* part of complex number");
    case parsing_error::Imag: throw std::invalid_argument("Invalid character in *imaginary* part of complex number");
    case parsing_error::Char: throw std::invalid_argument("Invalid character for *i* constant");
    case parsing_error::None: break;
    }

    _c.__re = a;
    _c.__im = b;

    return s;
}

complex operator""_i(long double _im)
{
    return complex(0, static_cast<double>(_im));
}

complex operator""_i(unsigned long long _im)
{
    return complex(0, static_cast<double>(_im));
}

complex operator+(double const _re, complex const& _c)
{
    return complex(_re + _c.__re, _c.__im);
}

complex operator-(double const _re, complex const& _c)
{
    return complex(_re - _c.__re, -_c.__im);
}

complex operator +(complex const& _c1, complex const& _c2)
{
    return complex(
        _c1.__re + _c2.__re,
        _c1.__im + _c2.__im
    );
}
complex operator -(complex const& _c1, complex const& _c2)
{
    return complex(
        _c1.__re - _c2.__re,
        _c1.__im - _c2.__im
    );
}
complex operator *(complex const& _c1, complex const& _c2)
{
    return complex(
        _c1.__re * _c2.__re - _c1.__im * _c2.__im,
        _c1.__im * _c2.__re + _c1.__re * _c2.__im
    );
}
complex operator /(complex const& _c1, complex const& _c2)
{
    double den = std::pow(_c2.__re, 2) + std::pow(_c2.__im, 2);
    if (den == 0)
    {
        return complex(
            std::numeric_limits<double>::infinity(),
            std::numeric_limits<double>::infinity()
        );
    }
    return complex(
        (_c1.__re * _c2.__re + _c1.__im * _c2.__im) / den,
        (_c1.__im * _c2.__re - _c1.__re * _c2.__im) / den
    );
}