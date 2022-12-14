#include "klass.hpp"

#include <iostream>

#include "util/ansi_text.hpp"

int const& klass::integer() const
{
    return this->__integer;
}

char const& klass::character() const
{
    return this->__character;
}

double const& klass::floating_point() const
{
    return this->__floating_point;
}

auto klass::integer()
{
    return __integer_s;
}

auto klass::character()
{
    return __character_s;
}

auto klass::floating_point()
{
    return __floating_point_s;
}

klass::klass()
{
    std::cout
        << ANSI::b_magenta << "Default constructor called"
        << ANSI::reset << util::nl;
}

klass::klass(int _integer)
{
    std::cout
        << ANSI::b_magenta << "Overloaded constructor called (int)"
        << ANSI::reset << util::nl;
    std::cout
        << ANSI::b_magenta << "Integer value: "
        << ANSI::reset << _integer << util::nl;
    this->integer() = _integer;
}

klass::klass(char _character)
{
    std::cout
        << ANSI::b_magenta << "Overloaded constructor called (char)"
        << ANSI::reset << util::nl;
    std::cout
        << ANSI::b_magenta << "Character value: "
        << ANSI::reset << _character << util::nl;
    this->character() = _character;
}

klass::klass(double _floating_point)
{
    std::cout
        << ANSI::b_magenta << "Overloaded constructor called (double)"
        << ANSI::reset << util::nl;
    std::cout
        << ANSI::b_magenta << "Floating point value: "
        << ANSI::reset << _floating_point << util::nl;
    this->floating_point() = _floating_point;
}
