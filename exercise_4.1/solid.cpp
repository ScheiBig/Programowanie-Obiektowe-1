#include "solid.hpp"

#include <cmath>

double sphere::area() { return M_PI * 4 * this->_r * this->_r; }
double sphere::volume() { return M_PI * 4 / 3 * this->_r * this->_r * this->_r; }
double sphere::diagonal() { return this->_r * 2; }

double cuboid::area()
{
    return (2 * this->_a * this->_b) +
        (2 * this->_a * this->_c) +
        (2 * this->_b * this->_c);
}
double cuboid::volume() { return this->_a * this->_b * this->_c; }
double cuboid::diagonal() { return std::sqrt(this->_a * this->_a + this->_b * this->_b + this->_c * this->_c); }

double pyramid::area()
{
    return (this->_a * this->_b) +
        (this->_a / 2 * sqrt(this->_b * this->_b + 4 * this->_h * this->_h)) +
        (this->_b / 2 * sqrt(this->_a * this->_a + 4 * this->_h * this->_h));
}
double pyramid::volume() { return this->_h / 3 * this->_a * this->_b; }
double pyramid::diagonal() { return sqrt((this->_a * this->_a + this->_b * this->_b) / 4 + this->_h * this->_h); }
