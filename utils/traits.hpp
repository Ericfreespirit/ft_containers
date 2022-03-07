#ifndef TRAITS_H
#define TRAITS_H

#include "../include/iterator_vector.hpp"

namespace ft{

/*=============
|   enable_if  |
===============*/

template<bool Cond, class T = void>
struct enable_if {

};

template<class T>
struct enable_if<true, T> { 
    typedef T type;};

/*
template <bool Cond, class T = void>
struct enable_if {
};
*/

/*======================
|   integral traits     |
========================*/

 template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};
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


//  template <bool is_iterator, typename T>
//         struct is_iterator_res {
//             typedef T type;
//             static const bool value = is_iterator;
// };

// template <typename>
//         struct is_iterator_type : public is_iterator_res<false, bool> {};
// template <class T>
//         struct is_iterator_type<bool> : public is_iterator_res<true, iterator_traits<T>::iterator_category<T> > {};
/*
template <typename T>
    struct is_integral : public is_integral_type<T> { };

template <class T, class = void>
bool is_iterator_v = false;

template <class T>
bool is_iterator_v<T, iterator_traits<Iter>::iterator_category<T> = true;
*/
// template <typename T, typename Alloc>
// template <class InputIterator, std::enable_if_t<is_iterator_v<InputIterator>, int> = 0>
// void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)

/*======================
|    iterator traits    |
========================*/


struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
    
template <class InputIterator>
struct iterator_traits {
    typedef typename InputIterator::difference_type difference_type;
    typedef typename InputIterator::value_type value_type;
    typedef typename InputIterator::pointer pointer;
    typedef typename InputIterator::reference reference;
    typedef typename InputIterator::const_reference const_reference;
    typedef typename InputIterator::iterator_category iterator_category;
};

template <class T>
struct iterator_traits <T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
};

template <class T>
struct iterator_traits <const T*> {
		typedef const std::ptrdiff_t				difference_type;
		typedef const T								value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
};


template <class T>
struct is_iterator {
	typedef char yes[1];
	typedef char no[2];

	template <typename C>
	static yes& test(typename C::iterator_category *);
	template <typename>
	static no& test(...);

	static const bool value = sizeof(test<T>(NULL)) == sizeof(yes);
};

template <class T>
struct is_iterator<T*> {
	static const bool value = true;
};


}; // end of namespace ft

#endif