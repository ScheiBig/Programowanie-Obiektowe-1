#include <iostream>
#include <random>

#include "fib.hpp"
#include "util/ansi_text.hpp"

int main()
{
    std::cout << "First 13 elements: ";
    for (size_t i = 0; i < 13; i++)
    {
        std::cout << fib<int>::value_no(i) << " ";
    }
    std::cout << "\n\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> range(0, 100);


    std::cout << "Random 15 numbers: \n";
    for (size_t i = 0; i < 15; i++)
    {
        int num = range(gen);
        bool is_val = fib<int>::is_value(num);

        std::cout
            << (is_val ? ANSI::green : ANSI::red)
            << "Liczba " << num << (is_val ? "" : " nie") << " należy do ciągu fibonacci\n"
            << ANSI::reset;
    }

    return 0;
}
