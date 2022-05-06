#ifndef CONST_ITERATOR_VECTOR_H
#define CONST_ITERATOR_VECTOR_H

#include "../utils/traits.hpp"
#include "iterator_vector.hpp"
#include "iterator.hpp"

namespace ft {

    template <typename T>
    class	const_iterator_vector : public iterator<T> {
    public:
        typedef const_iterator_vector<T> _it;

      	typedef std::ptrdiff_t difference_type;
	    typedef const T value_type;
	    typedef	const T*  pointer;
		typedef const T& reference;
		typedef ft::random_access_iterator_tag iterator_category;


	    const_iterator_vector(void) : iterator<T>(){};
	    const_iterator_vector(T *ptr) {this->_ptr = ptr; };
	    ~const_iterator_vector() {};
			const_iterator_vector(const iterator<T> &src) :  iterator<T>(src) {};

		_it operator=(const const_iterator_vector &rhs) {
			if (this == &rhs)
				return (*this);
			this->_ptr = rhs._ptr;
			return (*this);
		}
	    const _it operator+(difference_type p) {return(_it(this->_ptr + p));}; // _ptr + p
	    const _it operator-(difference_type p) {return(_it(this->_ptr - p));}; // _ptr - p

	    difference_type operator+(_it p) const {return(this->_ptr + p._ptr);}; // _ptr + p
	    difference_type operator-(_it p) const {return(this->_ptr - p._ptr);}; // _ptr - p

	    const _it &operator++() { ++this->_ptr; return(*this);}; // ++_ptr
		const _it operator++(int) {_it tmp(*this); ++this->_ptr; return(tmp);}; // _ptr++
		const _it &operator--() { --this->_ptr; return(*this);}; // --_ptr
		const _it operator--(int) {_it tmp(*this); --this->_ptr; return(tmp);}; // _ptr--

	    _it &operator+=(difference_type p) {this->_ptr += p; return(*this);}; // _ptr += p
	    _it &operator-=(difference_type p) {this->_ptr -= p; return(*this);}; // _ptr -= p

	    pointer operator->() const {return (this->_ptr);};	
     	reference operator*() const {return (*this->_ptr);}; // *_ptr
	    reference operator[](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]

    }; //end of iterator_vector definition class

}//end of namespace ft

#endif