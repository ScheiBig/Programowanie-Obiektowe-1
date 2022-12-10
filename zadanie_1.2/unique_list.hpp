#pragma once

#include <stdexcept>
#include <iostream>

#include "util/ansi_text.hpp"
#include "util/bformat.hpp"

template<typename T>
class unique_list
{
private:
    struct node
    {
        node* __prev;
        node* __next;
        T __value;
    };
public:

    unique_list();

    unique_list(const unique_list<T>& _from);

    unique_list<T>& operator =(const unique_list<T>& _from);

    ~unique_list();

    unique_list& add_element(T _id);

    /// @throw std::invalid_argument 
    unique_list& add_element(T _id, T _prev_id) noexcept(false);

    unique_list& remove_element(T _id);

    /// @throw std::invalid_argument
    T& pop_element(T _id) noexcept(false);

    unique_list& sort(int (*_comp)(T const& _a, T const& _b));

    template<typename U>
    friend std::ostream& operator <<(std::ostream& _s, const unique_list<U>& _l);

private:
    node* __head;
    node* __tail;
    size_t __size;

    node* find_element(T _id);
};




template<typename T>
unique_list<T>::unique_list():__head(nullptr), __tail(nullptr), __size(0) {}

template<typename T>
unique_list<T>::unique_list(const unique_list<T>& _from) : unique_list()
{
    for (unique_list<T>::node* n = _from.__head; n != nullptr; n = n->__next)
    {
        this->add_element(n->__value);
    }
}

template<typename T>
unique_list<T>& unique_list<T>::operator=(const unique_list<T>& _from)
{
    this->~unique_list();
    this->__size = 0;
    
    for (unique_list<T>::node* n = _from.__head; n != nullptr; n = n->__next)
    {
        this->add_element(n->__value);
    }
    return *this;
}

template<typename T>
unique_list<T>::~unique_list()
{
    switch (this->__size)
    {
    case 0: break;
    case 1: {
        delete this->__head;
        break;
    }
    default: {
        for (node* pn{ this->__tail->__prev }; pn != nullptr; pn = pn->__prev)
        {
            delete pn->__next;
        }
        delete this->__head;
    }
    }
}

template<typename T>
unique_list<T>& unique_list<T>::add_element(T _id)
{
    if (this->__size == 0)
    {
        this->__head = this->__tail = new node{ nullptr, nullptr, _id };
        this->__size++;

        return *this;
    }

    node* new_element{ new node{ this->__tail, nullptr, _id } };
    this->__tail->__next = new_element;
    this->__tail = new_element;
    this->__size++;

    return *this;
}

template<typename T>
unique_list<T>& unique_list<T>::add_element(T _id, T _prev_id) noexcept(false)
{
    if (this->__size == 0)
    {
        throw std::invalid_argument(util::bformat(
            "Cannot add element ($) after previous one ($): list is empty", _id, _prev_id
        ));
    }

    node* prev{ this->find_element(_prev_id) };
    if (prev == nullptr)
    {
        throw std::invalid_argument(util::bformat(
            "Cannot add element ($) after previous one ($): no such element", _id, _prev_id
        ));
    }

    node* new_element{ new node{ prev, nullptr, _id } };

    if (prev->__next != nullptr)
    {
        node* next{ prev->__next };
        new_element->__next = next;
        next->__prev = new_element;
    }
    else { this->__tail = new_element; }

    prev->__next = new_element;
    this->__size++;

    return *this;
}

template<typename T>
unique_list<T>& unique_list<T>::remove_element(T _id)
{
    this->pop_element(_id);

    return *this;
}

template<typename T>
T& unique_list<T>::pop_element(T _id) noexcept(false)
{
    if (this->__size == 0)
    {
        throw std::invalid_argument(util::bformat(
            "Cannot remove element ($): list is empty", _id
        ));
    }
    node* n{ this->find_element(_id) };
    if (n->__value == _id)
    {
        node* next{ n->__next };
        node* prev{ n->__prev };
        if (next != nullptr) { next->__prev = prev; }
        if (prev != nullptr) { prev->__next = next; }

        if (this->__head == n) { this->__head = next; }
        if (this->__tail == n) { this->__tail = prev; }
        T& v{ n->__value };

        delete n;

        this->__size--;
        
        return v;
    }

    throw std::invalid_argument(util::bformat(
        "Cannot remove element ($): no such element", _id
    ));
}

template<typename T>
unique_list<T>& unique_list<T>::sort(int (*_comp)(T const& _a, T const& _b))
{
    if (this->__size <= 1) { return *this; }

    int sw = 1;
    for (unique_list<T>::node* x = this->__tail; x != nullptr && sw != 0; x = x->__prev)
    {
        for (unique_list<T>::node* y = this->__head; y->__next != x->__next; y = y->__next)
        {
            if (_comp(y->__value, y->__next->__value) > 0)
            {
                std::swap(y->__value, y->__next->__value);
                sw++;
            }
        }
    }

    return *this;
}

template<typename T>
typename unique_list<T>::node* unique_list<T>::find_element(T _id)
{
    for (node* n{ this->__head }; n != nullptr; n = n->__next)
    {
        if (n->__value == _id) { return n; }
    }

    return nullptr;
}

template<typename U>
std::ostream& operator<< (std::ostream& _s, unique_list<U> const& _l)
{
    _s
        << ANSI::b_black << "unique_list: ["
        << ANSI::reset << util::nl;
    for (const typename unique_list<U>::node* cur = _l.__head; cur != nullptr; cur = cur->__next)
    {
        _s
            << ANSI::reset << "  " << cur->__value
            << ANSI::b_black << ","
            << ANSI::reset << util::nl;
    }
    return _s
        << ANSI::b_black << "]"
        << ANSI::reset;
}
