#include <iostream>
#include <fstream>
#include <limits>
#include <string>

#include "people.hpp"
#include "utils.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::ifstream;

using util::nl;

namespace menu
{
    enum options
    {
        ADD = 1, REMOVE, PRINT, CLOSE
    };
}

int main()
{
    ifstream file("People.txt");

    People people;
    string cur_line;

    while (std::getline(file, cur_line))
    {
        people.add_person(Person::parse_person(cur_line >>= util::split(", ")));
    }

    cout << ANSI::b_cyan;
    cout << "Loaded from file:" << nl << people << nl;
    cout << ANSI::reset;

    int choice;
    bool running = true;
    unsigned long l_buf;
    while (running)
    {
        cout << ANSI::yellow;
        cout << "(1: add person, 2: remove person, 3: print people, 4: exit)" << nl;
        cout << ANSI::b_yellow;
        cout << "What do you want do do next: ";
        cout << ANSI::reset;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case menu::ADD: {
            Person pr;
            cout << "Name: ";
            std::getline(cin, pr.name);
            
            cout << "Surname: ";
            std::getline(cin, pr.surname);

            cout << "Address: ";
            std::getline(cin, pr.address);

            cout << "PESEL: ";
            cin >> pr.PESEL;
            try
            {
                people.add_person(pr);
            }
            catch (const std::invalid_argument& e)
            {
                cerr << ANSI::red;
                cerr << e.what() << nl;
                cerr << ANSI::reset;
            }
            break;
        }
        case menu::REMOVE: {
            cout << ANSI::b_yellow;
            cout << "PESEL of person to remove: ";
            cout << ANSI::reset;
            cin >> l_buf;
            
            try
            {
                people.remove_person(l_buf);
            }
            catch (const std::invalid_argument& e)
            {
                cerr << ANSI::red;
                cerr << e.what() << nl;
                cerr << ANSI::reset;
            }

            break;
        }
        case menu::PRINT: {
            cout << ANSI::b_green;
            cout << people << util::nl;
            cout << ANSI::reset;
            break;
        }
        case menu::CLOSE: {
            running = false;
            break;
        }
        default: {
            cerr << ANSI::red;
            cerr << "Unknown option (" << choice << ")" << nl;
            cerr << ANSI::reset;
            break;
        }
        }
    }

    return 0;
}
