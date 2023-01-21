#include <iostream>
#include <cmath>
#include <tuple>
#include <complex>

#include "util/ansi_text.hpp"
#include "util/bformat.hpp"

using namespace std::complex_literals;

struct num
{
    bool isReal;
    union
    {
        double r;
        std::complex<double> c;
    };
};

std::tuple<num, num> find_roots(double _a, double _b, double _c)
{
    if (_a == 0)
    {
        if (_b == 0)
        {
            if (_c == 0)
            {
                throw std::invalid_argument("Coefficients given for zero-polynomial");
            }
            else
            {
                throw std::invalid_argument("Coefficients given for constant function");
            }
        }
        else
        {
            throw std::invalid_argument(
                util::bformat("Coefficients given for linear equation, which has a root: $", -_b / _c)
            );
            
        }
    }

    double del = _b * _b - 4 * _a * _c;
    if (del == 0)
    {
        double a = -_b / (2 * _a);
        num res{ true, {a} };
        return { res, res };
    }
    else if (del > 0)
    {
        double a = (-_b + std::sqrt(del)) / (2 * _a);
        double b = (-_b - std::sqrt(del)) / (2 * _a);
        return { {true, {a}}, {true, {b}} };
    }
    else
    {
        double ar = (-_b) / (2 * _a);
        double br = (-_b) / (2 * _a);
        double i = std::sqrt(-del) / (2 * _a);
        num n1 = { false };
        n1.c = std::complex{ ar, i };
        num n2 = { false };
        n2.c = std::complex{ br, -i };
        return { n1, n2 };
    };
}

int main()
{
    double a, b, c;

    std::cout << "Enter coefficients of quadratic formula: ";

    std::cin >> a >> b >> c;

    if (!std::cin)
    {
        std::cerr
            << ANSI::b_red << "Invalid data!"
            << ANSI::reset << "\n";
        return 1;
    }

    int choice;
    std::cout << "Do you want complex roots?: (0 for no, number for yes) ";
    std::cin >> choice;

    try
    {
        // needs c++17 !!
        auto [root1, root2] = find_roots(a, b, c);
        if (!!choice)
        {
            std::cout << "Found roots: ";
            if (root1.isReal)
            {
                std::cout << root1.r << " and " << root2.r << "\n";
            }
            else
            {
                std::cout << root1.c << " and " << root2.c << "\n";
            }
        }
        else if (root1.isReal)
        {
            std::cout << "Found roots: " << root1.r << " and " << root2.r << "\n";
        }
        else
        {
            std::cout << "Found no roots" << "\n";
        }
    }
    catch (std::exception const& e)
    {
        std::cerr
            << ANSI::b_red << e.what()
            << ANSI::reset << "\n";
        return 2;
    }

    return 0;
}
