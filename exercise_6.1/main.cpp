#include <iostream>
#include <string>
#include <cctype>

#include "nums.hpp"
#include "util/ansi_text.hpp"

std::string str_trim(std::string const& _str);

int main()
{
    std::cout << "Enter a number: ";
    std::string str;
    std::getline(std::cin, str);
    if (str.empty())
    {
        std::cerr
            << ANSI::b_red << "Empty line!"
            << ANSI::reset;
    }
    str = str_trim(str);
    if (str.empty())
    {
        std::cerr
            << ANSI::b_red << "Blank line!"
            << ANSI::reset;
    }
    std::cout << "'" << str << "'\n";
    try
    {
        int i = parse_int(str.c_str());
        std::cout
            << ANSI::b_blue << "Znaleziona liczba: '"
            << ANSI::reset << i
            << ANSI::b_blue << "'"
            << ANSI::reset << "\n";
            
    }
    catch (std::exception const& e)
    {
        std::cerr
            << ANSI::b_red << e.what()
            << ANSI::reset;
    }
    return 0;
}

std::string str_trim(std::string const& _str)
{
    size_t i_start{ 0 };
    size_t i_end{ _str.length() - 1 };
    bool start_found = false;

    while (i_start <= i_end)
    {
        size_t i = !start_found ? i_start : i_end;
        bool whitespace = !!isspace(_str.at(i));

        if (!start_found)
        {
            if (!whitespace) { start_found = true; }
            else i_start++;
        }
        else
        {
            if (!whitespace) { break; }
            else i_end--;
        }
    }

    return _str.substr(i_start, i_end - i_start + 1);
}
