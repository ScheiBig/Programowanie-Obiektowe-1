#include "nums.hpp"

#include <cstring>
#include <stdexcept>
#include <climits>

#include "util/bformat.hpp"

int parse_int(const char* _str) noexcept(false)
{
    const char* str = _str;
    size_t len{ std::strlen(_str) };
    int num{ 0 };
    bool pos{ true };
    if (_str[0] == '-')
    {
        pos = false;
        len--;
        str++;
    }
    for (size_t i{ 0 }; i < len; i++)
    {
        int n = str[i] - '0';
        if (0 > n || n > 9)
        {
            throw std::invalid_argument(
                util::bformat("Invalid character '$' at position [$]", str[i], i)
            );
        }
        num *= 10;
        num += n;
        if (num < 0)
        {
            throw std::out_of_range(
                util::bformat("String '$' out of range of int ($..$)", _str, INT_MIN, INT_MAX)
            );
        }
    }
    return num * (pos ? 1 : -1);
}
