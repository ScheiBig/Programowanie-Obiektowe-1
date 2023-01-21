#pragma once

#include <cstdlib>

template <typename T>
class fib
{
public:
    static T value_no(size_t _n)
    {
        if (_n == 0) { return (T)0; }
        if (_n == 1) { return (T)1; }
        return value_no(_n - 1) + value_no(_n - 2);
    }

    static bool is_value(T _v)
    {
        T v{ 0};
        for (size_t i{ 0 }; v < _v; i++)
        {
            v = value_no(i);
            if (v == _v) { return true; }
        }
        return false;
    }
};
