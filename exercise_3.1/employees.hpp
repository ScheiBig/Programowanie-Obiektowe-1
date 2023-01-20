#pragma once

#include <string>
#include <ostream>
#include <ctime>

class manager;

class employee
{
protected:
    std::string __name;
    std::string __surname;
    unsigned long __NIP;
    // https://en.cppreference.com/w/cpp/chrono/c/strftime using char buf[100]
    std::tm __date_of_employment;
    unsigned int __wage;
    std::string __departament;
public:
    employee(
        std::string _name,
        std::string _surname,
        unsigned long _NIP,
        tm _date_of_employment,
        unsigned int _wage,
        std::string _departament
    );

    virtual std::ostream& print_to(std::ostream& _s);

    friend class manager;
};

class manager: public employee
{
protected:
    size_t __number_of_subordinates;
    std::string __management_type;
    unsigned int __supplement_ptc;
public:

    manager(
        size_t _number_of_subordinates,
        std::string _management_type,
        unsigned int _supplement_ptc,
        std::string _name,
        std::string _surname,
        unsigned long _NIP,
        tm _date_of_employment,
        unsigned int _wage,
        std::string _departament
    );

    void add_subordinate(employee& _subordinate);

    std::ostream& print_to(std::ostream& _s) override;
};
