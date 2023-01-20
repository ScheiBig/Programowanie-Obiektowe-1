#include <iostream>

#include "employees.hpp"

int main()
{
    std::time_t now = time(nullptr);
    std::tm today{ *std::localtime(&now) };

    employee john_smith{ "John", "Smith", 123456789, today, 3500, "egg" };

    john_smith.print_to(std::cout) << "\n\n";

    std::tm ago{ today };
    ago.tm_year -= 5;

    manager bob_doe{ 3, "junior supervisor", 15, "Robert", "Doe", 147258369, ago, 6000, "leg" };

    bob_doe.add_subordinate(john_smith);

    bob_doe.print_to(std::cout) << "\n\n";
    john_smith.print_to(std::cout) << "\n\n";

    return 0;
}
