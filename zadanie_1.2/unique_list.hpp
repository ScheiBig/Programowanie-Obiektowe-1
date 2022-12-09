#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <algorithm>

#include "utils.hpp"

template<typename T>
class UniqueList
{
private:
    struct Node
    {
        Node* prev;
        Node* next;
        T value;
    };
public:
    UniqueList();

    UniqueList(const UniqueList<T>& _from);

    UniqueList<T>& operator =(const UniqueList<T>& _from);

    ~UniqueList();

    UniqueList& add_element(T _id);

    UniqueList& add_element(T _id, T _prev_id);

    UniqueList& remove_element(T _id);

    T& pop_element(T _id);

    UniqueList sorted();

    friend std::ostream& operator <<(std::ostream& _s, const UniqueList& _l)
    {
        _s << "UniqueList: [" << util::nl;
        for (const typename UniqueList<T>::Node* cur = _l.head; cur != nullptr; cur = cur->next)
        {
            _s << "  " << cur->value << util::nl;
        }
        return _s << "]";
    }

private:
    Node* head;
    Node* tail;
    size_t size;

    Node* find_element(T _id);
};




template<typename T>
UniqueList<T>::UniqueList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<typename T>
UniqueList<T>::UniqueList(const UniqueList<T>& _from)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    for (Node* n{ _from.head }; n != nullptr; n = n->next)
    {
        this->add_element(n->value);
    }
}

template<typename T>
UniqueList<T>& UniqueList<T>::operator=(const UniqueList<T>& _from)
{
    for (Node* n{ _from.head }; n != nullptr; n = n->next)
    {
        this->add_element(n->value);
    }
    return *this;
}

template<typename T>
UniqueList<T>::~UniqueList()
{
    switch (this->size)
    {
    case 0: break;
    case 1: {
        delete this->head;
        break;
    }
    default: {
        for (Node* pn{ this->tail->prev }; pn != nullptr; pn = pn->prev)
        {
            delete pn->next;
        }
        delete this->head;
    }
    }
}

template<typename T>
UniqueList<T>& UniqueList<T>::add_element(T _id)
{
    if (this->size == 0)
    {
        this->head = this->tail = new Node{ nullptr, nullptr, _id };
        this->size++;

        return *this;
    }

    Node* new_element{ new Node{ this->tail, nullptr, _id } };
    this->tail->next = new_element;
    this->tail = new_element;
    this->size++;

    return *this;
}

template<typename T>
UniqueList<T>& UniqueList<T>::add_element(T _id, T _prev_id)
{
    if (this->size == 0)
    {
        std::stringstream error_message;
        error_message << "Cannot add element (" << _id <<
            ") after previous one (" << _prev_id << "): list is empty";
        throw std::invalid_argument(error_message.str());
    }

    Node* prev{ this->find_element(_prev_id) };
    if (prev == nullptr)
    {
        std::stringstream error_message;
        error_message << "Cannot add element (" << _id <<
            ") after previous one (" << _prev_id << "): no such element";
        throw std::invalid_argument(error_message.str());
    }

    Node* new_element{ new Node{ prev, nullptr, _id } };

    if (prev->next != nullptr)
    {
        Node* next{ prev->next };
        new_element->next = next;
        next->prev = new_element;
    }
    else { this->tail = new_element; }

    prev->next = new_element;
    this->size++;

    return *this;
}

template<typename T>
UniqueList<T>& UniqueList<T>::remove_element(T _id)
{
    this->pop_element(_id);

    return *this;
}

template<typename T>
T& UniqueList<T>::pop_element(T _id)
{
    if (this->size == 0)
    {
        std::stringstream error_message;
        error_message << "Cannot remove element: list is empty" << _id;
        throw std::invalid_argument(error_message.str());
    }
    Node* n{ this->find_element(_id) };
    if (n->value == _id)
    {
        Node* next{ n->next };
        Node* prev{ n->prev };
        if (next != nullptr) { next->prev = prev; }
        if (prev != nullptr) { prev->next = next; }

        if (this->head == n) { this->head = next; }
        if (this->tail == n) { this->tail = prev; }
        T& v{ n->value };

        delete n;

        return v;
    }

    std::stringstream error_message;
    error_message << "Cannot remove element: no such element"
        << _id;
    throw std::invalid_argument(error_message.str());
}

template<typename T>
UniqueList<T> UniqueList<T>::sorted()
{
    UniqueList new_list;

    T** elements{ new T * [this->size] };

    size_t i{};
    for (Node* n{ this->head }; n != nullptr; n = n->next)
    {
        elements[i++] = &(n->value);
    }

    std::sort(elements, elements + this->size, [](T* a, T* b) { return *a < *b; });

    for (i = 0; i < this->size; i++)
    {
        new_list.add_element(*(elements[i]));
    }

    delete[] elements;

    return new_list;
}

template<typename T>
typename UniqueList<T>::Node* UniqueList<T>::find_element(T _id)
{
    for (Node* n{ this->head }; n != nullptr; n = n->next)
    {
        if (n->value == _id) { return n; }
    }

    return nullptr;
}
