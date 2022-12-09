#pragma once
#include "unique_list.hpp"

#include <stdexcept>
#include <string>
#include <iostream>

#include "utils.hpp"

template<typename T>
UniqueList<T>& UniqueList<T>::add_element(T _id)
{
    if (this->size == 0)
    {
        this->head = this->tail = new Node(nullptr, nullptr, _id);
        return *this;
    }
    Node* new_element = new Node(this->tail, nullptr, _id);
    this->tail->next = new_element;
    this->tail = new_element;

    return *this;
}

// template<typename T>
// class UniqueList
// {
// private:
//     struct Node
//     {
//         Node* prev;
//         Node* next;
//         T& value;
//         Node(Node* _prev, Node* _next, T& _value) : prev(_prev), next(_next), value(_value) {}
//     };
// public:
//     UniqueList() {}

//     UniqueList& add_element(T _id, T _prev_id);

//     UniqueList& add_element(T _id);

//     UniqueList& remove_element(T _id);

//     T& pop_element(T _id);

//     UniqueList& sorted();

//     friend std::ostream& operator <<(std::ostream& _s, const UniqueList& _l);

// private:
//     Node* head;
//     Node* tail;
//     size_t size;

//     Node* find_element(T _id);

//     Node* find_smallest_element();
// };
