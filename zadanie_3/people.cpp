#include "people.hpp"

#include "iterator.hpp"

using std::ostream;
using std::string;
using std::vector;

Person::Person() : name(""), surname(""), address(""), PESEL(0) {}

Person::Person(
    string _name,
    string _surname,
    string _address,
    unsigned long _PESEL
) : name(_name), surname(_surname), address(_address), PESEL(_PESEL)
{
}

ostream& operator <<(ostream& _s, const Person& _p)
{
    return _s << "Person: { name: " << _p.name
        << ", surname: " << _p.surname
        << ", address: " << _p.address
        << ", PESEL: " << _p.PESEL
        << "}";
};

Person Person::parse_person(const vector<string>& _vec)
{
    return Person(_vec[0], _vec[1], _vec[2], stoul(_vec[3]));
}

People::People()
{
    this->people = new Person[INIT_COUNT];
    this->size = INIT_COUNT;
    this->count = 0u;
}

People::People(const People& _p)
{
    this->people = new Person[_p.size];
    std::copy_n(_p.people, _p.count, this->people);
    this->count = _p.count;
    this->size = _p.size;
}

People::~People()
{
    delete[] this->people;
}

People& People::operator =(const People& _p)
{
    if (this != &_p)
    {

        Person* new_people = new Person[_p.size];
        std::copy_n(_p.people, _p.count, new_people);

        delete[] this->people;

        this->people = new_people;

        this->count = _p.count;
        this->size = _p.size;
    }
    return *this;
}

ostream& operator <<(ostream& _s, const People& _p)
{
    _s << "People: [\n";

    for (Person p : iter::Each<Person>(_p.people, _p.count))
    {
        _s << "  " << p << "\n";
    }

    return _s << "]";
};

People& People::add_person(const Person& _p)
{
    if (this->locate_person(_p.PESEL) != -1)
    {
        throw std::invalid_argument("Person with PESEL exist: " + std::to_string(_p.PESEL));
    }
    
    if (this->size == this->count)
    {
        this->people = resize_buffer(this->people, this->size, this->size * RESIZE);
        this->size *= RESIZE;
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
