#include <iostream>
#include <fstream>
#include <limits>
#include <string>

#include "people.hpp"
#include "util/split.hpp"
#include "util/ansi_text.hpp"

enum struct menu
{
    ADD = 1, REMOVE, PRINT, CLOSE = 0
};


int main()
{
    People people;
    std::string cur_line;

    std::ifstream file("People.txt");
    if (file.is_open())
    {
        while (std::getline(file, cur_line))
        {
            people.add_person(Person::parse_person(cur_line >>= util::split(", ")));
        }

        std::cout
            << ANSI::b_blue << "Loaded from file:" << util::nl
            << ANSI::reset << people << util::nl;

        file.close();
    }

    int choice;
    bool running = true;
    unsigned long l_buf;
    while (running)
    {
        std::cout
            << ANSI::b_magenta << "(1: add person, 2: remove person, 3: print people, 0: exit)" << util::nl
            << ANSI::b_cyan << "What do you want do do next: "
            << ANSI::reset;

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), util::nl);

        switch (choice)
        {
        case (int)menu::ADD: {
            Person pr;
            std::cout
                << ANSI::b_cyan << "Name: "
                << ANSI::reset;
            std::getline(std::cin, pr.name);

            std::cout
                << ANSI::b_cyan << "Surname: "
                << ANSI::reset;
            std::getline(std::cin, pr.surname);

            std::cout
                << ANSI::b_cyan << "Address: "
                << ANSI::reset;
            std::getline(std::cin, pr.address);

            std::cout
                << ANSI::b_cyan << "PESEL: "
                << ANSI::reset;
            std::cin >> pr.PESEL;
            try
            {
                people.add_person(pr);
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr
                    << ANSI::red << e.what() << util::nl
                    << ANSI::reset;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), util::nl);
            break;
        }
        case (int)menu::REMOVE: {
            std::cout
                << ANSI::b_cyan << "PESEL of person to remove: "
                << ANSI::reset;
            std::cin >> l_buf;

            try
            {
                people.remove_person(l_buf);
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr
                    << ANSI::b_red << e.what() << util::nl
                    << ANSI::reset;
            }

            break;
        }
        case (int)menu::PRINT: {
            std::cout
                << ANSI::b_green << "Currently stored: "
                << ANSI::reset << people << util::nl;
            break;
        }
        case (int)menu::CLOSE: {
            running = false;
            break;
        }
        default: {
            std::cerr
                << ANSI::b_red << "Unknown option (" << choice << ")" << util::nl
                << ANSI::reset;
            break;
        }
        }
    }

    return 0;
}
