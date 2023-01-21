#include <iostream>
#include <list>

#include "util/ansi_text.hpp"

int main()
{
    std::cout << "Enter number of pairs: ";
    int p;
    std::cin >> p;
    if (!std::cin || p <= 0)
    {
        std::cerr
            << ANSI::b_red << "Number too small!"
            << ANSI::reset << "\n";
        return 1;
    }
    int a;
    int b;
    std::list<int> list;
    for (int i{ 0 }; i < p; i++)
    {
        std::cin >> a >> b;
        if (!std::cin)
        {
            std::cerr
                << ANSI::b_red << "Invalid data!"
                << ANSI::reset << "\n";
            return 2;
        }
        if (a >= 0) { list.push_back(a); }
        else { list.push_front(a); }
        if (b >= 0) { list.push_back(b); }
        else { list.push_front(b); }
    }

    std::cout << "Your numbers are:\n";
    for (int n : list)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";
    return 0;
}
