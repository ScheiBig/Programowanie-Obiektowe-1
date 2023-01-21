#pragma once

#include <string>
#include <iostream>
#include <ctime>

class person
{
protected:
    std::string __name;
    std::string __surname;
    std::tm __birth_date;
public:
    person(
        std::string _name,
        std::string _surname,
        std::tm _birth_date
    );

    virtual std::ostream& print_to(std::ostream& _s);
};

class student: public person
{
protected:
    int __year;
    int __group;
    int __ID;
public:
    student(
        int _year,
        int _group,
        int _ID,
        std::string _name,
        std::string _surname,
        std::tm _birth_date
    );

    std::ostream& print_to(std::ostream& _s) override;
};

class player: public person
{
protected:
    int __position;
    std::string __club;
    int __goals;
public:
    player(
        int _position,
        std::string _club,
        int _goals,
        std::string _name,
        std::string _surname,
        std::tm _birth_date
    );

    int score_goal();

    std::ostream& print_to(std::ostream& _s) override;
};
