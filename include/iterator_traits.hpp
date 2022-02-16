#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
    
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