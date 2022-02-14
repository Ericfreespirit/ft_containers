#ifndef ITERATOR_H
#define ITERATOR_H


    template <class Category, class T, class Distance = std::ptrdiff_t,
              class Pointer = T*, class Reference = T&>
    class iterator {
    public:
        typedef Category  iterator_category;
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;

        iterator(){};
        ~iterator(){};
    };

#endif