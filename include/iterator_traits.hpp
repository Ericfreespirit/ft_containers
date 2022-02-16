#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

#include "random.hpp"

namespace ft {
template <class Iter>
struct iterator_traits {
    typedef std::ptrdiff_t difference_type;
    typedef Iter value_type;
    typedef Iter* pointer;
    typedef Iter& reference;
    typedef ft::random_access_iterator_tag iterator_category;
};
}


#endif