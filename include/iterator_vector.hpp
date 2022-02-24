#ifndef ITERATOR_VECTOR_H
#define ITERATOR_VECTOR_H

#include "traits.hpp"

namespace ft{

    template <class T>
    class iterator_vector {
    public:
        typedef iterator_vector<T> _it;
		
        typedef std::ptrdiff_t difference_type; 
	    typedef T value_type;
	    typedef	T*  pointer;
	    typedef T& reference;
        typedef const T& const_reference;
		typedef ft::random_access_iterator_tag iterator_category;

        iterator_vector(pointer ptr) : _ptr(ptr){};
        ~iterator_vector(){};
        // iterator_vector(const _it &ref);

	    _it &operator=(_it const &src) { this->_ptr = src.operator->(); return (*this); };

	    bool operator ==(_it const& p) const {return(this->_ptr == p._ptr);};
	    bool operator !=(_it const& p) const {return(this->_ptr != p._ptr);};
	    bool operator >(_it const& p) const {return(this->_ptr > p._ptr);};
	    bool operator <(_it const& p) const {return(this->_ptr < p._ptr);};
	    bool operator >=(_it const& p) const {return(this->_ptr >= p._ptr);};
	    bool operator <=(_it const& p) const {return(this->_ptr <= p._ptr);};

	    _it operator +(difference_type p) {return(_it(this->_ptr + p));}; // _ptr + p
	    _it operator -(difference_type p) {return(_it(this->_ptr - p));}; // _ptr - p

	    difference_type operator +(_it p) {return(this->_ptr + p._ptr);}; // _ptr + p
	    difference_type operator -(_it p) {return(this->_ptr - p._ptr);}; // _ptr - p

	    _it operator ++() { this->_ptr++; return(*this);}; // ++_ptr
	    _it operator ++(int) { this->_ptr++; return(_it(this->_ptr + 1));}; // _ptr++
	    _it operator --() { this->_ptr--; return(*this);}; // --_ptr
	    _it operator --(int) { this->_ptr--; return(_it(this->_ptr - 1));}; // _ptr--

	    void operator +=(difference_type p) {this->_ptr += p;}; // _ptr += p
	    void operator -=(difference_type p) {this->_ptr -= p;}; // _ptr -= p

	    pointer operator ->() {return(this->_ptr);}; // _ptr->p
	    pointer operator ->() const {return (this->_ptr);};	
        //const_reference operator *() const {return (*this->_ptr);}; // *_ptr
		reference operator *() const {return (*this->_ptr);}; // *_ptr
	    const_reference operator [](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]
    private:
		pointer _ptr;
    }; //end of iterator_vector definition class
}//end of namespace ft

#endif