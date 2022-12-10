#include <iostream>
#include <fstream>
#include <limits>
#include <string>

#include "people.hpp"
#include "util/split.hpp"
#include "util/ansi_text.hpp"

enum struct menu
{
    Add = 1,
    Remove,
    Print,
    Close = 0
};


int main()
{
    people people;
    std::string cur_line;

    std::ifstream file("People.txt");
    if (file.is_open())
    {
        while (std::getline(file, cur_line))
        {
            people.add_person(person::parse_person(cur_line >>= util::split(", ")));
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
        case (int)menu::Add: {
            person pr;
            std::cout
                << ANSI::b_cyan << "Name: "
                << ANSI::reset;
            std::getline(std::cin, pr.__name);

            std::cout
                << ANSI::b_cyan << "Surname: "
                << ANSI::reset;
            std::getline(std::cin, pr.__surname);

            std::cout
                << ANSI::b_cyan << "Address: "
                << ANSI::reset;
            std::getline(std::cin, pr.__address);

            std::cout
                << ANSI::b_cyan << "PESEL: "
                << ANSI::reset;
            std::cin >> pr.__PESEL;
            try
            {
                people.add_person(pr);
            }
            catch (std::invalid_argument const& e)
            {
                std::cerr
                    << ANSI::red << e.what() << util::nl
                    << ANSI::reset;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), util::nl);
            break;
        }
        case (int)menu::Remove: {
            std::cout
                << ANSI::b_cyan << "PESEL of person to remove: "
                << ANSI::reset;
            std::cin >> l_buf;

            try
            {
                people.remove_person(l_buf);
            }
            catch (std::invalid_argument const& e)
            {
                std::cerr
                    << ANSI::b_red << e.what() << util::nl
                    << ANSI::reset;
            }

            break;
        }
        case (int)menu::Print: {
            std::cout
                << ANSI::b_green << "Currently stored: "
                << ANSI::reset << people << util::nl;
            break;
        }
        case (int)menu::Close: {
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
