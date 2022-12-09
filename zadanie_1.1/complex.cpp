#include "complex.hpp"

#include <cmath>
#include <cctype>
#include <limits>

Complex::Complex(double _re, double _im): __re(_re), __im(_im) {}

Complex::~Complex() {}

std::ostream& operator<<(std::ostream& _s, const Complex& _c)
{
    return _s << _c.__re << (_c.__im < 0 ? "" : "+") << _c.__im << "i";
}

enum struct Parsing_Error
{
    Real, Imag, Char, None
};

std::istream& operator>>(std::istream& s, Complex& _c) noexcept(false)
{
    double a;
    double b;
    char i;

    enum Parsing_Error err = Parsing_Error::None;

    if (!(s >> a)) err = Parsing_Error::Real;
    if (!(s >> b)) err = Parsing_Error::Imag;
    if (!(s >> i) || std::tolower(i) != 'i') err = Parsing_Error::Char;

    switch (err)
    {
    case Parsing_Error::Real: throw std::invalid_argument("Invalid character in *real* part of complex number");
    case Parsing_Error::Imag: throw std::invalid_argument("Invalid character in *imaginary* part of complex number");
    case Parsing_Error::Char: throw std::invalid_argument("Invalid character for *i* constant");
    case Parsing_Error::None: break;
    }

    _c.__re = a;
    _c.__im = b;

    return s;
}

Complex operator""_i(long double _im)
{
    return Complex(0, static_cast<double>(_im));
}

Complex operator""_i(unsigned long long _im)
{
    return Complex(0, static_cast<double>(_im));
}

Complex operator+(const double _re, const Complex& _c)
{
    return Complex(_re + _c.__re, _c.__im);
}

Complex operator-(const double _re, const Complex& _c)
{
    return Complex(_re - _c.__re, -_c.__im);
}

Complex operator +(const Complex& _c1, const Complex& _c2)
{
    return Complex(
        _c1.__re + _c2.__re,
        _c1.__im + _c2.__im
    );
}
Complex operator -(const Complex& _c1, const Complex& _c2)
{
    return Complex(
        _c1.__re - _c2.__re,
        _c1.__im - _c2.__im
    );
}
Complex operator *(const Complex& _c1, const Complex& _c2)
{
    return Complex(
        _c1.__re * _c2.__re - _c1.__im * _c2.__im,
        _c1.__im * _c2.__re + _c1.__re * _c2.__im
    );
}
Complex operator /(const Complex& _c1, const Complex& _c2)
{
    double den = std::pow(_c2.__re, 2) + std::pow(_c2.__im, 2);
    if (den == 0)
    {
        return Complex(
            std::numeric_limits<double>::infinity(),
            std::numeric_limits<double>::infinity()
        );
    }
    return Complex(
        (_c1.__re * _c2.__re + _c1.__im * _c2.__im) / den,
        (_c1.__im * _c2.__re - _c1.__re * _c2.__im) / den
    );
}