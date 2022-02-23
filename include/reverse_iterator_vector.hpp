#ifndef REVERSE_ITERATOR_VECTOR_H
#define REVERSE_ITERATOR_VECTOR_H

#include "traits.hpp"

namespace ft{

    template <typename iterator>
    class	reverse_vector_iterator
    {
    public:
	    typedef typename iterator::value_type		value_type;
	    typedef typename iterator::reference		reference;
	    typedef typename iterator::const_reference	const_reference;
	    typedef typename iterator::pointer			pointer;
	    typedef typename iterator::const_pointer	const_pointer;
	    typedef typename iterator::difference_type	difference_type; //is the signed integer type of the result of subtracting two pointers. 

	    reverse_vector_iterator(void) {};
	    reverse_vector_iterator(pointer ptr) { _ptr = ptr; };
	    reverse_vector_iterator(iterator_vector<value_type> const &p) { _ptr = p.operator->(); } ;
	    reverse_vector_iterator(reverse_vector_iterator const &p) { *this = p; } ;
    
	    vectorReverseIterator &operator=(vectorReverseIterator const &p) { _ptr = p._ptr; return (*this); };

	    bool operator ==(iterator_vector const& p) const {return(this->_ptr == p._ptr);};
	    bool operator !=(iterator_vector const& p) const {return(this->_ptr != p._ptr);};
	    bool operator >(iterator_vector const& p) const {return(this->_ptr > p._ptr);};
	    bool operator <(iterator_vector const& p) const {return(this->_ptr < p._ptr);};
	    bool operator >=(iterator_vector const& p) const {return(this->_ptr >= p._ptr);};
	    bool operator <=(iterator_vector const& p) const {return(this->_ptr <= p._ptr);};

	    iterator_vector operator +(difference_type p) {return(iterator_vector(this->_ptr - p));}; // _ptr + p
	    iterator_vector operator -(difference_type p) {return(iterator_vector(this->_ptr + p));}; // _ptr - p

	    difference_type operator +(iterator_vector p) {return(this->_ptr - p._ptr);}; // _ptr + p
	    difference_type operator -(iterator_vector p) {return(this->_ptr + p._ptr);}; // _ptr - p

	    iterator_vector operator ++() { this->_ptr--; return(*this);}; // ++_ptr
	    iterator_vector operator ++(int) { this->_ptr--; return(iterator_vector(this->_ptr + 1));}; // _ptr++
	    iterator_vector operator --() { this->_ptr++; return(*this);}; // --_ptr
	    iterator_vector operator --(int) { this->_ptr++; return(iterator_vector(this->_ptr - 1));}; // _ptr--

	    void operator +=(difference_type p) {this->_ptr -= p;}; // _ptr += p
	    void operator -=(difference_type p) {this->_ptr += p;}; // _ptr -= p

	    pointer operator ->() {return(this->_ptr);}; // _ptr->p
	    pointer operator ->() const {return (this->_ptr);};	
        const_reference operator *() const {return (*this->_ptr);}; // *_ptr
	    const_reference operator [](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]
    private:
		pointer _ptr;
    }; //end of iterator_vector definition class
}//end of namespace ft

#endif