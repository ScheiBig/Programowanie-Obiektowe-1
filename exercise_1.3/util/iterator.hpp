/* ========================================================================== */
/* Author: Marcin Jeznach || plz no steal 😭                                  */
/*                                                                            */
/* Classes that can be used as iterators ( for (auto x: y) notation )         */
/* ========================================================================== */
#pragma once

namespace util
{   
    template<typename T>
    class ptr_iterator
    {
    private:
        T* __ptr;
    public:
        explicit ptr_iterator(T* _ptr): __ptr(_ptr) {}

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

        bool operator==(ptr_iterator _other) const { return this->__ptr == _other.__ptr; }

        bool operator!=(ptr_iterator _other) const { return !(*this == _other); }

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
}
