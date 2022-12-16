#pragma once

#include <string>
#include <ctime>

class employee
{
private:
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

    virtual std::string to_string();
};

class manager: public employee
{
private:
    size_t _number_of_subordinates;
    std::string _management_type;
    unsigned int _supplement_ptc;
public:
    std::string to_string() override;
    void add_subordinate(employee const& _subordinate);
};