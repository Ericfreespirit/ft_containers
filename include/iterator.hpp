#ifndef random_iterator_H
#define random_iterator_H

#include "../utils/traits.hpp"

namespace ft{

    template <class T>
    class random_iterator {
    public:
        typedef random_iterator<T> _it;
		
        typedef std::ptrdiff_t difference_type; 
	    typedef T value_type;
	    typedef	T*  pointer;
		typedef const T* const_pointer;
	    typedef T& reference;
        typedef const T& const_reference;
		typedef ft::random_access_iterator_tag iterator_category;

        random_iterator();
		random_iterator(value_type *x);
		random_iterator(const random_iterator &x);
		// random_iterator	&operator=(random_iterator const &rhs);
		virtual ~random_iterator();

        /* OLD CONSTRUCTOR
		random_iterator(void) {};
        random_iterator(pointer ptr) : _ptr(ptr){};
        ~random_iterator(){};
        // random_iterator(const _it &ref);
		random_iterator(random_iterator const &src) { *this = src; } ;
        */
	    // random_iterator &operator=(_it const &src) { this->_ptr = src._ptr; return (*this); };

	    random_iterator &operator=(const random_iterator &rhs) {
		if (this == &rhs)
			return (*this);
		this->_ptr = rhs._ptr;
		return (*this);
	}

	    bool operator ==(_it const& p) const {return(this->_ptr == p._ptr);};
	    bool operator !=(_it const& p) const {return(this->_ptr != p._ptr);};
	    bool operator >(_it const& p) const {return(this->_ptr > p._ptr);};
	    bool operator <(_it const& p) const {return(this->_ptr < p._ptr);};
	    bool operator >=(_it const& p) const {return(this->_ptr >= p._ptr);};
	    bool operator <=(_it const& p) const {return(this->_ptr <= p._ptr);};

		_it operator +(difference_type p) {return _ptr + p;};
	    _it operator +(difference_type p) const {return(_it(this->_ptr + p));}; // _ptr + p
	    _it operator -(difference_type p) const {return(_it(this->_ptr - p));}; // _ptr - p

	    difference_type operator +(_it p) {return(this->_ptr + p._ptr);}; // _ptr + p
	    difference_type operator -(_it p) {return(this->_ptr - p._ptr);}; // _ptr - p

	    _it &operator ++() { this->_ptr++; return(*this);}; // ++_ptr
	    _it operator ++(int) { this->_ptr++; return(_it(this->_ptr + 1));}; // _ptr++
	    _it &operator --() { this->_ptr--; return(*this);}; // --_ptr
	    _it operator --(int) { this->_ptr--; return(_it(this->_ptr - 1));}; // _ptr--

	    _it operator +=(difference_type p) {this->_ptr += p; return(*this);}; // _ptr += p
	    _it operator -=(difference_type p) {this->_ptr -= p; return(*this);}; // _ptr -= p

	    // pointer operator ->() {return(this->_ptr);}; // _ptr->p
	    // pointer operator ->() const {return (this->_ptr);};	
		// reference operator *() {return (*(this->_ptr));}; // *_ptr
        // const_reference operator *() const {return (*(this->_ptr));}; // *_ptr
	    // const_reference operator [](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]
		// reference operator [](difference_type p) { return (*(this->_ptr + p)); };	
    protected:
		pointer _ptr;
    }; //end of random_iterator definition class

    // template <class T>
	// random_iterator<T> operator+(std::ptrdiff_t i, random_iterator<T> &it) {
	// 	return (it + i);
	// }
	// template <class T>
	// random_iterator<T> operator+(std::ptrdiff_t i, random_iterator<T> &it) {
	// 	return (it + i);
	// }
}//end of namespace ft

#endif
