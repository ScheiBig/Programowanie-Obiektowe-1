#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

#include "util/memory.hpp"

// template<typename T>
// T* resize_buffer(T* _buf, size_t _n_old, size_t _n_new)
// {
//     T* new_buf = new T[_n_new];
//     std::copy_n(_buf, std::min(_n_old, _n_new), new_buf);
//     delete[] _buf;
//     return new_buf;
// }

struct Person
{
    std::string name;
    std::string surname;
    std::string address;
    unsigned long PESEL;

    Person();
    
    Person( 
        std::string _name,
        std::string _surname,
        std::string _address,
        unsigned long _PESEL
    );

    friend std::ostream& operator <<(std::ostream& _s, const Person& _p);

    static Person parse_person(const std::vector<std::string>& _vec);
};

#define INIT_COUNT 2
#define RESIZE 2

class People
{
public:
    People();
    People(const People& _p);
    ~People();

    People& operator =(const People& _p);
    friend std::ostream& operator <<(std::ostream& _s, const People& _p);

    People& add_person(const Person& _p) noexcept(false);
    People& remove_person(unsigned long _PESEL) noexcept(false);

private:
    util::mem<Person> people;
    size_t count;

    ssize_t locate_person(unsigned long _PESEL);
};
