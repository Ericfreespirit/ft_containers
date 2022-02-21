#ifndef ENABLE_IF_H
#define ENABLE_IF_H
#include <iostream>

namespace ft{

template <bool Cond, class T = void>
struct enable_if {
        typedef T type;
};

template <typename T>
struct enable_if<true, T>{};

}; // end of namespace ft


#endif