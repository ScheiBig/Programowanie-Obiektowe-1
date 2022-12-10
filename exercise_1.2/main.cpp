#include <iostream>
#include <fstream>
#include <limits>
#include <string>

#include "unique_list.hpp"
#include "util/ansi_text.hpp"


enum struct menu
{
    Add = 1,
    Remove,
    Print,
    Sort,
    Close = 0
};

static int sorting_comparator(std::string const& _a, std::string const& _b)
{
    size_t s = _a.length() - _b.length();
    if (s != 0) { return s; }
    return _a.compare(_b);
}

int main()
{

    std::cout << std::string("2").compare("13");
    std::cout << std::string("2").compare("21");
    
    unique_list<std::string> list;
    std::string cur_val;
    std::string prev_val;

    std::ifstream file("UniqueList.txt");
    if (file.is_open())
    {
        while (std::getline(file, cur_val))
        {
            list.add_element(cur_val);
        }

        std::cout
            << ANSI::b_blue << "Loaded from file:" << util::nl
            << ANSI::reset << list << util::nl;

        file.close();
    }

    int choice;
    bool running = true;
    while (running)
    {
        std::cout
            << ANSI::b_magenta << "(1: add value, 2: remove value, 3: print all alues, 4: sort values, 0: exit)" << util::nl
            << ANSI::b_cyan << "What do you want do do next: "
            << ANSI::reset;

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), util::nl);
        switch (choice)
        {
        case (int)menu::Add: {
            std::cout
                << ANSI::b_cyan << "Value: "
                << ANSI::reset;
            std::getline(std::cin, cur_val);

            std::cout
                << ANSI::b_cyan << "Value to add after: "
                << ANSI::reset;
            std::getline(std::cin, prev_val);

            try
            {
                list.add_element(cur_val, prev_val);
            }
            catch (std::invalid_argument const& e)
            {
                std::cerr
                    << ANSI::b_red << e.what() << util::nl
                    << ANSI::reset;
            }
            break;
        }
        case (int)menu::Remove: {
            std::cout
                << ANSI::b_cyan << "Value to remove: "
                << ANSI::reset;
            std::getline(std::cin, cur_val);
            try
            {
                list.remove_element(cur_val);
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
                << ANSI::reset << list << util::nl;
            break;
        }
        case (int)menu::Sort: {
            std::cout
                << ANSI::b_green << "After sorting: "
                << ANSI::reset << list.sort(sorting_comparator) << util::nl;
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

