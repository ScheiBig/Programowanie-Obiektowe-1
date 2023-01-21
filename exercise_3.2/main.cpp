#include "people.hpp"

int main()
{
    std::tm date1{ 56, 34, 12, 01, 01, 1970 - 1900 };
    std::mktime(&date1);

    person john_smith{ "John", "Smith", date1 };
    john_smith.print_to(std::cout) << "\n\n";

    student bob_doe{ 2, 10, 214365,"Robert", "Doe", date1 };
    bob_doe.print_to(std::cout) << "\n\n";

    player mary_williams{ 3, "Holy Smokes", 21, "Mary", "Williams", date1 };
    mary_williams.print_to(std::cout) << "\n\n";

    std::cout << "Scored a goal, now: " << mary_williams.score_goal() << "\n";

    return 0;
}
