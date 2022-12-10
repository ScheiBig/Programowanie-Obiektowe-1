#include "people.hpp"

#include <string>

#include "util/ansi_text.hpp"

person::person(): __name(""), __surname(""), __address(""), __PESEL(0) {}

person::person(
    std::string _name,
    std::string _surname,
    std::string _address,
    unsigned long _PESEL
): __name(_name), __surname(_surname), __address(_address), __PESEL(_PESEL)
{
}

std::ostream& operator <<(std::ostream& _s, person const& _p)
{
    return _s
        << ANSI::b_black << "person: { name: "
        << ANSI::reset << _p.__name
        << ANSI::b_black << ", surname: "
        << ANSI::reset << _p.__surname
        << ANSI::b_black << ", address: "
        << ANSI::reset << _p.__address
        << ANSI::b_black << ", PESEL: "
        << ANSI::reset << _p.__PESEL
        << ANSI::b_black << "}"
        << ANSI::reset;
}

person person::parse_person(std::vector<std::string> const& _vec)
{
    return person(_vec[0], _vec[1], _vec[2], stoul(_vec[3]));
}

people::people()
{
    this->__people = util::mem<person>::calloc(INIT_COUNT);
    this->__count = 0u;
}

people::people(people const& _p)
{
    this->__people = util::mem<person>::calloc(_p.__people.len());
    std::copy_n(_p.__people.ptr(), _p.__count, this->__people.ptr());
    this->__count = _p.__count;
}

people::~people()
{
    this->__people.free();
}

people& people::operator =(people const& _p)
{
    if (this != &_p)
    {

        util::mem<person> new_people = util::mem<person>::calloc(_p.__people.len());
        std::copy_n(_p.__people.ptr(), _p.__count, new_people.ptr());

        this->__people.free();

        this->__people = new_people;
        this->__count = _p.__count;
    }
    return *this;
}

std::ostream& operator <<(std::ostream& _s, people const& _p)
{
    _s
        << ANSI::b_black << "people: ["
        << ANSI::reset << util::nl;

    for (size_t i = 0; i < _p.__count; i++)
    {
        _s << "  " << _p.__people[i] << util::nl;
    }

    return _s
        << ANSI::b_black << "]"
        << ANSI::reset;
}

people& people::add_person(person const& _p) noexcept(false)
{
    if (this->locate_person(_p.__PESEL) != -1)
    {
        throw std::invalid_argument("person with PESEL exist: " + std::to_string(_p.__PESEL));
    }

    if (this->__people.len() == this->__count)
    {
        this->__people.realloc(this->__people.len() * RESIZE);
    }
    this->__people[this->__count++] = _p;

    return *this;
}

people& people::remove_person(unsigned long _PESEL) noexcept(false)
{
    ssize_t i = this->locate_person(_PESEL);
    if (i < 0)
    {
        throw std::invalid_argument("Not found: " + std::to_string(_PESEL));
    }

    for (size_t j = static_cast<size_t>(i); j < this->__count - 1; j++)
    {
        this->__people[j] = this->__people[j + 1];
    }
    this->__count--;

    return *this;
}

ssize_t people::locate_person(unsigned long _PESEL) const
{
    for (size_t i = 0; i < this->__count; i++)
    {
        if (this->__people[i].__PESEL == _PESEL)
        {
            return static_cast<ssize_t>(i);
        }
    }
    return -1;
}
