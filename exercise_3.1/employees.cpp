#include "employees.hpp"

#include "util/ansi_text.hpp"

employee::employee(
    std::string _name,
    std::string _surname,
    unsigned long _NIP,
    tm _date_of_employment,
    unsigned int _wage,
    std::string _departament
):
    __name(_name),
    __surname(_surname),
    __NIP(_NIP),
    __date_of_employment(_date_of_employment),
    __wage(_wage),
    __departament(_departament)
{
}

std::ostream& employee::print_to(std::ostream& _s)
{
    std::string date{ std::asctime(&this->__date_of_employment) };
    date.pop_back(); // remove '\n'

    return _s
        << ANSI::b_black << "employee: { "
        << ANSI::reset
        << "name: " << this->__name
        << ", surname: " << this->__surname
        << ", NIP: " << this->__NIP
        << ", date of employment: " << date
        << ", wage: " << this->__wage
        << ", department: " << this->__departament
        << ANSI::b_black << " }"
        << ANSI::reset;
}

manager::manager(
    size_t _number_of_subordinates,
    std::string _management_type,
    unsigned int _supplement_ptc,
    std::string _name,
    std::string _surname,
    unsigned long _NIP,
    tm _date_of_employment,
    unsigned int _wage,
    std::string _departament
):
    employee(
        _name,
        _surname,
        _NIP,
        _date_of_employment,
        _wage,
        _departament
    ),
    __number_of_subordinates(_number_of_subordinates),
    __management_type(_management_type),
    __supplement_ptc(_supplement_ptc)
{
}

void manager::add_subordinate(employee& _subordinate)
{
    this->__number_of_subordinates++;
    _subordinate.__departament = this->__departament;
}

std::ostream& manager::print_to(std::ostream& _s)
{
    _s
        << ANSI::b_black << "manager: { "
        << ANSI::reset
        << "number of subordinates: " << this->__number_of_subordinates
        << ", management type:" << this->__management_type
        << ", supplement %: " << this->__supplement_ptc
        << ", base information: ";
    this->employee::print_to(_s);
    return _s
        << ANSI::b_black << " }"
        << ANSI::reset;
}
