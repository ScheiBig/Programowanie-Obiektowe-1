#include "people.hpp"

#include "util/ansi_text.hpp"

person::person(
    std::string _name,
    std::string _surname,
    std::tm _birth_date
):
    __name(_name),
    __surname(_surname),
    __birth_date(_birth_date)
{
}

std::ostream& person::print_to(std::ostream& _s)
{
    std::string date{ std::asctime(&this->__birth_date) };
    date.pop_back(); // remove '\n'

    return _s
        << ANSI::b_black << "person: { "
        << ANSI::reset
        << "name: " << this->__name
        << ", surname: " << this->__surname
        << ", date of birth: " << date
        << ANSI::b_black << " }"
        << ANSI::reset;
}

student::student(
    int _year,
    int _group,
    int _ID,
    std::string _name,
    std::string _surname,
    std::tm _birth_date
):
    person(
        _name,
        _surname,
        _birth_date
    ),
    __year(_year),
    __group(_group),
    __ID(_ID)
{
}

std::ostream& student::print_to(std::ostream& _s)
{
    _s
        << ANSI::b_black << "student: { "
        << ANSI::reset
        << "year: " << this->__year
        << ", group #:" << this->__group
        << ", student ID: " << this->__ID
        << ", base information: ";
    this->person::print_to(_s);
    return _s
        << ANSI::b_black << " }"
        << ANSI::reset;
}

player::player(
    int _position,
    std::string _club,
    int _goals,
    std::string _name,
    std::string _surname,
    std::tm _birth_date
):
    person(
        _name,
        _surname,
        _birth_date
    ),
    __position(_position),
    __club(_club),
    __goals(_goals)
{
}

int player::score_goal()
{
    return ++this->__goals;
}

std::ostream& player::print_to(std::ostream& _s)
{
    _s
        << ANSI::b_black << "student: { "
        << ANSI::reset
        << "position: " << this->__position
        << ", club:" << this->__club
        << ", scored goals: " << this->__goals
        << ", base information: ";
    this->person::print_to(_s);
    return _s
        << ANSI::b_black << " }"
        << ANSI::reset;
}
