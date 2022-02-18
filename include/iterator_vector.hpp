#ifndef ITERATOR_VECTOR_H
#define ITERATOR_VECTOR_H

#include "iterator_traits.hpp"

namespace ft{

    template <class T>
    class iterator_vector : public ft::iterator_traits <T> {
    public:
	    typedef typename ft::iterator_traits <T>::value_type value_type;
	    typedef typename ft::iterator_traits <T>::pointer pointer;
	    typedef typename ft::iterator_traits <T>::reference reference;
	    typedef typename ft::iterator_traits <T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits <T>::const_reference const_reference;
        typedef typename std::ptrdiff_t difference_type; //is the signed integer type of the result of subtracting two pointers. 

        typedef iterator_vector<T> _it;
        iterator_vector(pointer ptr) : _ptr(ptr){};
        ~iterator_vector(){};
        iterator_vector(const _it &ref);

	    iterator_vector &operator=(iterator_vector const &src) { this->_ptr = src.operator->(); return (*this); };

	    bool operator ==(iterator_vector const& p) const {return(this->_ptr == p._ptr);};
	    bool operator !=(iterator_vector const& p) const {return(this->_ptr != p._ptr);};
	    bool operator >(iterator_vector const& p) const {return(this->_ptr > p._ptr);};
	    bool operator <(iterator_vector const& p) const {return(this->_ptr < p._ptr);};
	    bool operator >=(iterator_vector const& p) const {return(this->_ptr >= p._ptr);};
	    bool operator <=(iterator_vector const& p) const {return(this->_ptr <= p._ptr);};

	    iterator_vector operator +(difference_type p) {return(iterator_vector(this->_ptr + p));}; // _ptr + p
	    iterator_vector operator -(difference_type p) {return(iterator_vector(this->_ptr - p));}; // _ptr - p

	    difference_type operator +(iterator_vector p) {return(this->_ptr + p._ptr);}; // _ptr + p
	    difference_type operator -(iterator_vector p) {return(this->_ptr - p._ptr);}; // _ptr - p

	    iterator_vector operator ++() { this->_ptr++; return(*this);}; // ++_ptr
	    iterator_vector operator ++(int) { this->_ptr++; return(iterator_vector(this->_ptr - 1));}; // _ptr++
	    iterator_vector operator --() { this->_ptr--; return(*this);}; // --_ptr
	    iterator_vector operator --(int) { this->_ptr--; return(iterator_vector(this->_ptr + 1));}; // _ptr--

	    void operator +=(difference_type p) {this->_ptr += p;}; // _ptr += p
	    void operator -=(difference_type p) {this->_ptr -= p;}; // _ptr -= p

	    pointer operator ->() {return(this->_ptr);}; // _ptr->p
	    pointer operator ->() const {return (this->_ptr);};	
        const_reference operator *() const {return (*this->_ptr);}; // *_ptr
	    const_reference operator [](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]
    private:
		pointer _ptr;
    }; //end of iterator_vector definition class
}//end of namespace ft

#endif