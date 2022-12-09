// #include <iostream>
// #include <fstream>
// #include <limits>
// #include <string>

// #include "unique_list.hpp"
// #include "utils.hpp"

// using std::cin;
// using std::cout;
// using std::cerr;
// using std::string;
// using std::ifstream;

// using util::nl;


// template<>
// UniqueList<string> UniqueList<string>::sorted()
// {
//     UniqueList new_list;

//     string** elements = new string* [this->size];

//     size_t i = 0;
//     for (UniqueList<string>::Node* n = this->head; n != nullptr; n = n->next)
//     {
//         elements[i++] = &(n->value);
//     }

//     std::sort(elements, elements + this->size, [](string* a, string* b) { return *a < *b; });

//     for (i = 0; i < this->size; i++)
//     {
//         new_list.add_element(*(elements[i]));
//     }

//     delete[] elements;

//     return new_list;
// }


// namespace menu
// {
//     enum options
//     {
//         ADD = 1, REMOVE, PRINT, SORT, CLOSE
//     };
// }

// int main()
// {
//     UniqueList<string> list;
//     list.add_element("3")
//         .add_element("1", "3")
//         .add_element("4", "1")
//         .add_element("2", "4");

//     cout << list << nl;

//     UniqueList<string> sorted = list.sorted();

//     cout << sorted;

//     list.remove_element("2")
//         .remove_element("4");

//     cout << list << nl;

//     UniqueList<string> other(list);

//     list = sorted;

//     cout << list << nl;
//     cout << other << nl;
// }

