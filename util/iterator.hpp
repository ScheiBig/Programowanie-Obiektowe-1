/* ========================================================================== */
/* Author: Marcin Jeznach || plz no steal 😭                                  */
/*                                                                            */
/* Classes that can be used as iterators ( for (auto x: y) notation )         */
/* ========================================================================== */
#pragma once

#include <cstdlib>
#include <iterator>

using std::ptrdiff_t;

namespace util
{
    template<typename T>
    class ptr_iterator
    {
    private:
        T* __ptr;
    public:
        // for iterator_traits to refer
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        explicit ptr_iterator(T* _ptr): __ptr(_ptr) {}

        // Required by std::sort
        ptrdiff_t operator+ (ptr_iterator _other) { return this->__ptr + _other.__ptr; }
        // Required by std::sort
        ptr_iterator operator+ (ptrdiff_t _n) { return ptr_iterator{ this->__ptr + _n }; }

        // Required by std::sort
        ptrdiff_t operator- (ptr_iterator _other) { return this->__ptr - _other.__ptr; }
        // Required by std::sort
        ptr_iterator operator- (ptrdiff_t _n) { return ptr_iterator{ this->__ptr - _n }; }

        ptr_iterator& operator++()
        {
            this->__ptr++;
            return *this;
        }

        ptr_iterator operator++(int)
        {
            ptr_iterator result{ *this };
            ++(*this);
            return result;
        }

        // Required by std::sort
        ptr_iterator& operator--()
        {
            this->__ptr--;
            return *this;
        }

        // Requred by std::sort
        ptr_iterator operator--(int)
        {
            ptr_iterator result{ *this };
            --(*this);
            return result;
        }

        bool operator==(ptr_iterator const _other) const { return this->__ptr == _other.__ptr; }

        bool operator!=(ptr_iterator const _other) const { return !(*this == _other); }

        bool operator<(ptr_iterator const& _other) const { return this->__ptr < _other.__ptr; }
        bool operator>(ptr_iterator const& _other) const { return this->__ptr > _other.__ptr; }

        T& operator*() const { return *(this->__ptr); }
    };

    template<typename T>
    class cptr_iterator
    {
    private:
        T const* __ptr;
    public:
        explicit cptr_iterator(T const* _ptr): __ptr(_ptr) {}

        cptr_iterator& operator++()
        {
            this->__ptr++;
            return *this;
        }

        cptr_iterator operator++(int)
        {
            ptr_iterator result{ *this };
            ++(*this);
            return result;
        }

        bool operator==(cptr_iterator _other) const { return this->__ptr == _other.__ptr; }

        bool operator!=(cptr_iterator _other) const { return !(*this == _other); }

        T const& operator*() const { return *(this->__ptr); }
    };

    template<typename T>
    class rev
    {
        T& __iterable;

        rev(T&& _iterable): __iterable(_iterable) {}

        auto begin() { return __iterable.rbegin(); }
        auto end() { return __iterable.rend(); }
    };
}
