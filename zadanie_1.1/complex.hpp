#pragma once

#include <iostream>

class Complex
{
public:
    Complex(double _re = 0, double _im = 0);
    ~Complex();

    friend std::ostream& operator<<(std::ostream& s, const Complex& _c);
    friend std::istream& operator>>(std::istream& s, Complex& _c);

    friend Complex operator+(const double _re, const Complex& _c);
    friend Complex operator-(const double _re, const Complex& _c);

    friend Complex operator +(const Complex& _c1, const Complex& _c2);
    friend Complex operator -(const Complex& _c1, const Complex& _c2);
    friend Complex operator *(const Complex& _c1, const Complex& _c2);
    friend Complex operator /(const Complex& _c1, const Complex& _c2);

    double re;
    double im;
};

Complex operator""_i(long double _im);
Complex operator""_i(unsigned long long _im);
