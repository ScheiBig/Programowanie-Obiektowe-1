/* ========================================================================== */
/* Author: Marcin Jeznach || plz no steal 😭                                  */
/*                                                                            */
/* RAII wrappers and utility functions for allocated/mapped memory            */
/* ========================================================================== */
#pragma once

#include <cstdlib>
#include <new>
#include <functional>
#include <cstring>

#include "./iterator.hpp"

namespace util
{

    /**
     * @brief Temporary memory allocation, that lives for current scope
     *
     * @tparam T Type of elements
     * @tparam _n_elem Number of elements
     */
    template<typename T, size_t _n_elem>
    class temp_alloc final
    {
    public:
        /// Creates and allocates new array of `_n_elem` number of `T` elements
        temp_alloc()
        {
            __ptr = new T[_n_elem];
        }

        /// Dealocates this memory
        ~temp_alloc()
        {
            delete[] __ptr;
        }

        /// @return Pointer to first element in this memory array
        T* first()
        {
            return __ptr;
        }

        /// @return Pointer to last element in this memory array
        T* last()
        {
            return __ptr + _n_elem;
        }

        /// @return Number of elements int this memory array
        size_t length()
        {
            return _n_elem;
        }

    private:
        T* __ptr;
    };

    /**
     * @brief Class representing memory allocated using `std::calloc(..)` function.
     *
     * @tparam T type of allocated memory items
     */
    template<typename T>
    class mem
    {
    private:
        T* __ptr;
        size_t __len;
        mem(T* _ptr, std::size_t _len): __ptr(_ptr), __len(_len) {}
    public:

        mem(): __ptr(nullptr), __len(0) {}

        /**
         * @brief Wraps existing allocated memory
         *
         * @param _ptr pointer to memory
         * @param _n_elem number of elements
         */
        static mem<T> wrap(T* _ptr, size_t _n_elem)
        {
            return mem<T>{ _ptr, _n_elem };
        }

        /**
         * @brief Allocates new memory
         *
         * @param _n_elem number of elements
         */
        static mem<T> calloc(size_t _n_elem)
        {
            return mem<T>{ (T*)std::calloc(_n_elem, sizeof(T)), _n_elem };
        }

        /**
         *@brief
         *
         */
        static mem<char> strdup(const char* _cstr)
        {
            size_t s = std::strlen(_cstr) + 1;
            mem<char> m = mem<char>::calloc(s);
            std::memcpy(m.ptr(), _cstr, sizeof(char) * s);
            return m;
        }

        /**
         * @brief Reallocates `this->ptr` using `std::realloc(..)`.
         *
         * @throw `std::bad_alloc` if reallocation fails;
         *        `std::bad_function_call` if this memory is already deallocated;
         */
        void realloc(size_t _n_elem)
        {
            if (this->__ptr == nullptr) { throw std::bad_function_call(); }
            void* new_mem = std::realloc(__ptr, _n_elem * sizeof(T));
            if (new_mem == nullptr) { throw std::bad_alloc(); }
            this->__ptr = (T*)new_mem;
            this->__len = _n_elem;
        }

        /**
         * @brief Deallocates `this->ptr`
         *
         * @return `true` if there was memory to deallocate
         */
        bool free()
        {
            if (this->__ptr != nullptr) { std::free(__ptr); }
            else { return false; }
            this->__ptr = nullptr;
            this->__len = 0;
            return true;
        }

        T* ptr() const { return this->__ptr; }
        size_t len() const { return this->__len; }

        /**
         * @return iterator to the first element of this array
         */
        ptr_iterator<T> begin() { return ptr_iterator{ this->__ptr }; }

        /**
         * @return iterator to the next-after last element of this array
         */
        ptr_iterator<T> end() { return ptr_iterator{ this->__ptr + this->__len }; }

        /**
         * @return iterator to the first element of this array
         */
        cptr_iterator<T> begin() const { return cptr_iterator{ this->__ptr }; }

        /**
         * @return iterator to the next-after last element of this array
         */
        cptr_iterator<T> end() const { return cptr_iterator{ this->__ptr + this->__len }; }

        T& operator[] (size_t _index) noexcept(false)
        {
            if (_index > this->__len)
            {
                throw std::out_of_range(
                    "Index ["
                    + std::to_string(_index)
                    + "] out of bounds (0.."
                    + std::to_string(this->__len)
                    + ")"
                );
            }
            return this->__ptr[_index];
        }

        T const& operator[] (std::size_t _index) const noexcept(false)
        {
            if (_index > this->__len)
            {
                throw std::out_of_range(
                    "Index ["
                    + std::to_string(_index)
                    + "] out of bounds (0.."
                    + std::to_string(this->__len)
                    + ")"
                );
            }
            return this->__ptr[_index];
        }
    };

    template<typename T>
    T* t_calloc(size_t _n_elem)
    {
        return (T*)std::calloc(_n_elem, sizeof(T));
    }
}

constexpr size_t operator ""_z(unsigned long long _n)
{
    return (size_t)_n;
}
