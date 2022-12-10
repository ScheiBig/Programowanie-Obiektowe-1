#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

#include "util/memory.hpp"
struct person
{
    std::string __name;
    std::string __surname;
    std::string __address;
    unsigned long __PESEL;

    person();
    
    person( 
        std::string _name,
        std::string _surname,
        std::string _address,
        unsigned long _PESEL
    );

    friend std::ostream& operator <<(std::ostream& _s, person const& _p);

    static person parse_person(std::vector<std::string> const& _vec);
};

#define INIT_COUNT 2
#define RESIZE 2

class people
{
public:
    people();
    people(people const& _p);
    ~people();

    people& operator =(people const& _p);
    friend std::ostream& operator <<(std::ostream& _s, people const& _p);

    /// @throw std::invalid_argument
    people& add_person(person const& _p) noexcept(false);
    /// @throw std::invalid_argument
    people& remove_person(unsigned long _PESEL) noexcept(false);

private:
    util::mem<person> __people;
    size_t __count;

    ssize_t locate_person(unsigned long _PESEL) const;
};
