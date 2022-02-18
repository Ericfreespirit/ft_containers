#ifndef CONST_ITERATOR_VECTOR.HPP
#define CONST_ITERATOR_VECTOR.HPP

#include "iterator_traits.hpp"

namespace ft {

    template <typename iterator>
    class	iterator_vector {
    public:
        typedef typename ft::iterator_traits <T>::value_type value_type;
	    typedef typename ft::iterator_traits <T>::pointer pointer;
        typedef typename iterator::const_pointer	const_pointer;
	    typedef typename ft::iterator_traits <T>::reference reference;
	    typedef typename ft::iterator_traits <T>::iterator_category iterator_category;
        typedef typename ft::iterator_traits <T>::const_reference const_reference;
        typedef typename std::ptrdiff_t difference_type; //is the signed integer type of the result of subtracting two pointers. 

	    iterator_vector(void) {};
	    iterator_vector(pointer ptr) { _ptr = ptr; };
	    iterator_vector(iterator_vector<value_type> const &p) { _ptr = p.operator->(); } ;
	    iterator_vector(iterator_vector const &p) { *this = p; } ;
    
	    const iterator_vector &operator=(iterator_vector const &p) { _ptr = p._ptr; return (*this); };

	    bool operator==(iterator_vector const& p) const {return(this->_ptr == p._ptr);};
	    bool operator!=(iterator_vector const& p) const {return(this->_ptr != p._ptr);};
	    bool operator>(iterator_vector const& p) const {return(this->_ptr > p._ptr);};
	    bool operator<(iterator_vector const& p) const {return(this->_ptr < p._ptr);};
	    bool operator>=(iterator_vector const& p) const {return(this->_ptr >= p._ptr);};
	    bool operator<=(iterator_vector const& p) const {return(this->_ptr <= p._ptr);};

	    const iterator_vector operator+(difference_type p) {return(iterator_vector(this->_ptr - p));}; // _ptr + p
	    const iterator_vector operator-(difference_type p) {return(iterator_vector(this->_ptr + p));}; // _ptr - p

	    const difference_type operator+(iterator_vector p) {return(this->_ptr - p._ptr);}; // _ptr + p
	    const difference_type operator-(iterator_vector p) {return(this->_ptr + p._ptr);}; // _ptr - p

	    const iterator_vector operator++() { this->_ptr--; return(*this);}; // ++_ptr
	    const iterator_vector operator++(int) { this->_ptr--; return(iterator_vector(this->_ptr + 1));}; // _ptr++
	    const iterator_vector operator--() { this->_ptr++; return(*this);}; // --_ptr
	    const iterator_vector operator--(int) { this->_ptr++; return(iterator_vector(this->_ptr - 1));}; // _ptr--

	    void operator+=(difference_type p) {this->_ptr -= p;}; // _ptr += p
	    void operator-=(difference_type p) {this->_ptr += p;}; // _ptr -= p

	    const pointer operator->() {return(this->_ptr);}; // _ptr->p
	    const pointer operator->() const {return (this->_ptr);};	
        const const_reference operator*() const {return (*this->_ptr);}; // *_ptr
	    const const_reference operator[](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]
    private:
		pointer _ptr;
    }; //end of iterator_vector definition class
}//end of namespace ft

#endif