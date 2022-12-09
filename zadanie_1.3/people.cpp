#include "people.hpp"

#include <string>

#include "util/ansi_text.hpp"

Person::Person(): name(""), surname(""), address(""), PESEL(0) {}

Person::Person(
    std::string _name,
    std::string _surname,
    std::string _address,
    unsigned long _PESEL
): name(_name), surname(_surname), address(_address), PESEL(_PESEL)
{
}

std::ostream& operator <<(std::ostream& _s, const Person& _p)
{
    return _s
        << ANSI::b_black << "Person: { name: "
        << ANSI::reset << _p.name
        << ANSI::b_black << ", surname: "
        << ANSI::reset << _p.surname
        << ANSI::b_black << ", address: "
        << ANSI::reset << _p.address
        << ANSI::b_black << ", PESEL: "
        << ANSI::reset << _p.PESEL
        << ANSI::b_black << "}"
        << ANSI::reset;
}

Person Person::parse_person(const std::vector<std::string>& _vec)
{
    return Person(_vec[0], _vec[1], _vec[2], stoul(_vec[3]));
}

People::People()
{
    this->people = util::mem<Person>::calloc(INIT_COUNT);
    this->count = 0u;
}

People::People(const People& _p)
{
    this->people = util::mem<Person>::calloc(_p.people.len());
    std::copy_n(_p.people.ptr(), _p.count, this->people.ptr());
    this->count = _p.count;
}

People::~People()
{
    this->people.free();
}

People& People::operator =(const People& _p)
{
    if (this != &_p)
    {

        util::mem<Person> new_people = util::mem<Person>::calloc(_p.people.len());
        std::copy_n(_p.people.ptr(), _p.count, new_people.ptr());

        this->people.free();

        this->people = new_people;
        this->count = _p.count;
    }
    return *this;
}

std::ostream& operator <<(std::ostream& _s, const People& _p)
{
    _s
        << ANSI::b_black << "People: ["
        << ANSI::reset << util::nl;

    for (size_t i = 0; i < _p.count; i++)
    {
        _s << "  " << _p.people[i] << util::nl;
    }

    return _s
        << ANSI::b_black << "]"
        << ANSI::reset;
}

People& People::add_person(const Person& _p)
{
    if (this->locate_person(_p.PESEL) != -1)
    {
        throw std::invalid_argument("Person with PESEL exist: " + std::to_string(_p.PESEL));
    }

    if (this->people.len() == this->count)
    {
        this->people.realloc(this->people.len() * RESIZE);
    }
    this->people[this->count++] = _p;

    return *this;
}

People& People::remove_person(unsigned long _PESEL)
{
    ssize_t i = this->locate_person(_PESEL);
    if (i < 0)
    {
        throw std::invalid_argument("Not found: " + std::to_string(_PESEL));
    }

    for (size_t j = static_cast<size_t>(i); j < this->count - 1; j++)
    {
        this->people[j] = this->people[j + 1];
    }
    this->count--;

    return *this;
}

ssize_t People::locate_person(unsigned long _PESEL)
{
    for (size_t i = 0; i < this->count; i++)
    {
        if (this->people[i].PESEL == _PESEL)
        {
            return static_cast<ssize_t>(i);
        }
    }
    return -1;
}
