#ifndef ITERATOR_VECTOR_H
#define ITERATOR_VECTOR_H

#include "iterator_traits.hpp"

namespace ft{

template <class T>
class iterator_vector : ft::random_access_iterator_tag{

public:
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef ft::random_access_iterator_tag iterator_category;

    typedef iterator_vector<T> _it;
    iterator_vector(pointer ptr):_ptr(ptr){};
    ~iterator_vector(){};
    iterator_vector(const _it &ref);


	iterator_vector &operator=(iterator_vector const &p) { _ptr = p.operator->(); return (*this); };
    bool operator ==(iterator_vector const& p) const { return (_ptr == p._ptr); };
    bool operator !=(iterator_vector const& p) const { return (_ptr != p._ptr); };
    iterator_vector operator ++(int) { _ptr++; return (iterator_vector(_ptr - 1)); };
    reference operator *() { return (*_ptr); };
    pointer operator->() { return (_ptr); }; 

private:
		pointer _ptr;
}; //end of iterator_vector definition class



}//end of namespace ft


#endif