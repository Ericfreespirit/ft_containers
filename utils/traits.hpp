#ifndef TRAITS_H
#define TRAITS_H

#include "iterator_vector.hpp"

namespace ft{

/*=============
|   enable_if  |
===============*/

template <bool Cond, class T = void>
struct enable_if {
        typedef T type;
};

template <typename T>
struct enable_if<true, T>{};


/*======================
|   integral traits     |
========================*/

 template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    template <typename>
        struct is_integral_type : public is_integral_res<true, bool> {};
    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};
    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};
    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};  
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};
    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};
    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};   
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};


    template <typename T>
        struct is_integral : public is_integral_type<T> { };



/*======================
|    iterator traits    |
========================*/


struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
    
template <class Iter>
struct iterator_traits {
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
    typedef typename Iter::const_reference const_reference;
    typedef typename Iter::iterator_category iterator_category;
};



/*
 iterator_traits <T*>
 iterator_traits <const T*>

*/


template <class A, class B>
struct is_same {
    static const bool value = false;
};


template <class A>
struct is_same<A, A> {
    static const bool value = true;
};

template <bool is_iterator, class Iter>
struct is_iterator_res{
    typedef Iter type;
    static const bool value = is_iterator;
};


template<class Iter>
struct is_iterator {
    static const bool value = is_same<typename iterator_traits<Iter>::iterator_category, input_iterator_tag>::value;
};


}; // end of namespace ft

#endif