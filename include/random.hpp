#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>

namespace ft {

template <class T>
struct random_access_iterator_tag : public iterator_traits{
        typedef random_access_iterator_tag<T> iterator;
        iterator();
        ~iterator();
        iterator(const iterator &ref);

        iterator &operator=(const iterator &ref);
        iterator &operator==(const iterator &ref);
        iterator &operator!=(const iterator &ref);
        iterator &operator*(void);
        iterator &operator->(const iterator &ref);
        iterator &operator*(const iterator &ref);

        iterator &operator++();
        iterator &operator++(int);
        iterator &operator++();
        iterator &operator++(int);
        //*a++

        iterator &operator--();
        iterator &operator--(int);
        iterator &operator--();
        iterator &operator--(int);
        //*a--

        //[...] https://www.cplusplus.com/reference/iterator/RandomAccessIterator/


    }; //end of class definition 

        template <class T>
        iterator &iterator::operator++(){

        }

} //end of namespace ft
#endif