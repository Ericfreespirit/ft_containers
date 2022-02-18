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
    typedef const Iter& const_reference;
    typedef random_access_iterator_tag iterator_category;
    /*
    typedef const T					value_type;
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef value_type*				pointer;
	typedef typename std::ptrdiff_t difference_type; //is the signed integer type of the result of subtracting
    */
};
}


/*typedef Iter::difference_type difference_type;
    typedef Iter::value_type value_type;
    typedef Iter::pointer pointer;
    typedef Iter::reference reference;
    typedef const Iter& const_reference;
    typedef random_access_iterator_tag iterator_category;
*/


#endif