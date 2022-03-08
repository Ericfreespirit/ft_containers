#ifndef CONST_ITERATOR_VECTOR_H
#define CONST_ITERATOR_VECTOR_H

#include "../utils/traits.hpp"
#include "iterator_vector.hpp"
#include "iterator.hpp"


namespace ft {

    template <class T>
    class	const_iterator_vector : public random_iterator<T> {
	protected:
		// const_iterator_vector(T *src) : random_iterator<T>(src) {}
    public:
        typedef const_iterator_vector<T> _it;

        typedef std::ptrdiff_t difference_type;
	    typedef T value_type;
	    typedef	T*  pointer;
		typedef T& reference;
        typedef const T& const_reference;
        typedef const T* const_pointer;
		typedef ft::random_access_iterator_tag iterator_category;
		const_iterator_vector(T *src) : random_iterator<T>(src) {}
		const_iterator_vector(void) : random_iterator<T>() {};
		const_iterator_vector(const random_iterator<T> &src) : random_iterator<T>(src) {};
        virtual ~const_iterator_vector(){};

	/* OLD CONSTRUCTOR
	    const_iterator_vector(void) {};
	    virtual ~const_iterator_vector(void) {};
	    const_iterator_vector(pointer ptr) { this->_ptr = ptr; };
		const_iterator_vector(iterator_vector<T> const &src) { this->_ptr = src.operator->();};
		const_iterator_vector(const_iterator_vector const &src) { *this = src; } ;

	*/
	    // const_iterator_vector(_it const &p) { *this = p; } ;
    
	    // const _it &operator=(_it const &p) { this->_ptr = p._ptr; return (*this); };
		// using iterator::operator==();
	    // bool operator==(_it const& p) const {return(this->_ptr == p._ptr);};
	    // bool operator!=(_it const& p) const {return(this->_ptr != p._ptr);};
	    // bool operator>(_it const& p) const {return(this->_ptr > p._ptr);};
	    // bool operator<(_it const& p) const {return(this->_ptr < p._ptr);};
	    // bool operator>=(_it const& p) const {return(this->_ptr >= p._ptr);};
	    // bool operator<=(_it const& p) const {return(this->_ptr <= p._ptr);};

	    // const _it operator+(difference_type p) {return(_it(this->_ptr + p));}; // _ptr + p
	    // const _it operator-(difference_type p) {return(_it(this->_ptr - p));}; // _ptr - p

	    // difference_type operator+(_it p) {return(this->_ptr + p._ptr);}; // _ptr + p
	    // difference_type operator-(_it p) {return(this->_ptr - p._ptr);}; // _ptr - p

		const _it &operator ++(void) { random_iterator<T>::operator++(); return(*this);}; // ++_ptr
		const _it operator++(int) {return random_iterator<T>::operator++(0);};
		const _it &operator--(void) { random_iterator<T>::operator--(); return (*this);};
		const _it operator--(int) {return random_iterator<T>::operator--(0);};
		/*OLD*
	    // const _it operator++() { this->_ptr++; return(*this);}; // ++_ptr
	    // const _it operator++(int) { this->_ptr++; return(_it(this->_ptr + 1));}; // _ptr++
	    // const _it operator--() { this->_ptr--; return(*this);}; // --_ptr
	    // const _it operator--(int) { this->_ptr--; return(_it(this->_ptr - 1));}; // _ptr--*/

	    _it operator+=(difference_type p) {this->_ptr += p; return(*this);}; // _ptr += p
	    _it operator-=(difference_type p) {this->_ptr -= p; return(*this);}; // _ptr -= p

	    pointer operator->() {return(this->_ptr);}; // _ptr->p
	    pointer operator->() const {return (this->_ptr);};	
        const_reference operator*() const {return (*this->_ptr);}; // *_ptr
	    const_reference operator[](difference_type p) const {return (*(this->_ptr + p));}; // _ptr[]
    // private:
	// 	pointer _ptr;
    }; //end of iterator_vector definition class
	// template<class T>
	
	// bool operator!=(const_iterator_vector<T> &ite, iterator_vector<T> const &it) {
	// 	if (ite == it)
	// 		return 0;
	// 	else
	// 		return 1;
	// }
}//end of namespace ft

#endif