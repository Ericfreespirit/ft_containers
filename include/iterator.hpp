#ifndef ITERATOR_H
#define ITERATOR_H
#include "../utils/traits.hpp"

namespace ft{
    template <class T>
    class iterator {
    public:
        typedef iterator<T> _it;
        typedef std::ptrdiff_t difference_type; 
	    typedef T value_type;
	    typedef	T*  pointer;
		typedef const T* const_pointer;
	    typedef T& reference;
        typedef const T& const_reference;
		typedef ft::random_access_iterator_tag iterator_category;

        iterator(){};
        iterator(pointer ptr){this->_ptr = ptr;};
        ~iterator(){};

    /*================
    |   OP DEFERENCE  |
    ==================*/
    reference operator*() const {return (*this->_ptr);}; // *_ptr	
    pointer operator ->() {return(this->_ptr);}; // _ptr->p

    /*=============
    |   OP BOOL    |
    ================*/
    bool operator!=(const _it &p){return (this->_ptr != p._ptr);}
	bool operator ==(_it const& p) const {return(this->_ptr == p._ptr);};
	bool operator >(_it const& p) const {return(this->_ptr > p._ptr);};
	bool operator <(_it const& p) const {return(this->_ptr < p._ptr);};
	bool operator >=(_it const& p) const {return(this->_ptr >= p._ptr);};
	bool operator <=(_it const& p) const {return(this->_ptr <= p._ptr);};

    /*=============
    |   OP ARITHM   |
    ================*/
    difference_type operator+(_it p) {return(this->_ptr + p._ptr);}; // _ptr + p
	difference_type operator-(_it p) {return(this->_ptr - p._ptr);}; // _ptr - p
    _it operator+=(difference_type p) {this->_ptr += p; return(*this);}; // _ptr += p
	_it operator-=(difference_type p) {this->_ptr -= p; return(*this);}; // _ptr -= p

    /*===================
    |   OP INCRE/DECRE  |
    ===================*/
    _it operator++() { ++this->_ptr; return(*this);}; // ++_ptr
	_it operator++(int) {_it tmp(*this); ++this->_ptr; return(tmp);}; // _ptr++
	_it operator--() { --this->_ptr; return(*this);}; // --_ptr
	_it operator--(int) {_it tmp(*this); --this->_ptr; return(tmp);}; // _ptr--

    protected:
    pointer _ptr;
    
    };// end of iterator class

}; // end of ft 

#endif