#ifndef ENABLE_IF_H
#define ENABLE_IF_H
#include <iostream>

namespace ft{

template <bool Cond, class T = void>
struct enable_if {
    //typedef T type; //defined only if Cond is true

}; // end of class enable

} // end of namespace ft


#endif