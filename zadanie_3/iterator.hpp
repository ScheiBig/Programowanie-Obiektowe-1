#pragma once

#include <cstdlib>

namespace iter
{
    template <typename T>
    class pointer_iterator
    {
    public:
        pointer_iterator(T* _ptr) : ptr(_ptr) {}
        pointer_iterator operator++() { ++ptr; return *this; }
        bool operator!=(const pointer_iterator& other) const { return ptr != other.ptr; }
        const T& operator*() const { return *ptr; }
    private:
        T* ptr;
    };

    template <typename T>
    class value_iterator
    {
    public:
        value_iterator(T _ptr, T _step) : val(_ptr), step(_step) {}
        value_iterator operator++() { val += step; return *this; }
        bool operator!=(const value_iterator& other) const { return val != other.val; }
        const T& operator*() const { return val; }
    private:
        T val;
        T step;
    };

    
    template <typename T>
    class Each
    {
    public:
        Each(T* _ptr, size_t _n)
        {
            ptr = _ptr;
            n = _n;
        }

        Each(T* _ptr_start, T* _ptr_end)
        {
            ptr = _ptr_start;
            n = _ptr_end - _ptr_start;
        }

        pointer_iterator<T> begin() const { return pointer_iterator<T>(ptr); }
        pointer_iterator<T> end() const { return pointer_iterator<T>(ptr + n); }
    private:
        size_t n;
        T* ptr;
    };

    class Range
    {
    public:
        Range(size_t _from, size_t _to, size_t _step = 1) : from(_from), to(_to), step(_step) {}

        value_iterator<size_t> begin() const { return value_iterator<size_t>(from, step); }
        value_iterator<size_t> end() const { return value_iterator<size_t>(to, step); }
    private:
        size_t from;
        size_t to;
        size_t step;
    };
}
