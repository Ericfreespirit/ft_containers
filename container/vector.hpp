#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "../include/iterator_vector.hpp"
#include "../include/const_iterator_vector.hpp"
#include "../include/reverse_iterator_vector.hpp"
#include "../include/const_reverse_iterator_vector.hpp"
#include "../utils/traits.hpp"
#include <sstream>
#include <memory>

namespace ft {

template <class T, class A = std::allocator<T> >
class vector {
public:
    typedef T value_type;
    typedef A allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    typedef ft::iterator_vector<T> iterator;
    typedef ft::const_iterator_vector<T> const_iterator;
    typedef ft::reverse_iterator_vector<T> reverse_iterator;
    typedef ft::const_reverse_iterator_vector<T> const_reverse_iterator;

private:
    T *_array;
    A _alloc;
    size_type _size;
    size_type  _allocSize;

public:

    /*================
    |   CONSTRUCTOR   |
    ==================*/
    explicit vector (const allocator_type& alloc = allocator_type()):
    _alloc(alloc){
        _array = _alloc.allocate(0);
        _allocSize = 0;
        _size = 0;
    }

    explicit vector (size_type n, const value_type &val = value_type(),
        const allocator_type& alloc = allocator_type()):
    _alloc(alloc),
	_size(n){
        _allocSize = n;
		_array = _alloc.allocate(n);
         for(size_type i = 0;i < n; i++)
        _alloc.construct(&_array[i], val);
    }
            
    // template <class InputIterator>
    // vector(InputIterator first,InputIterator last,
    //     const allocator_type& alloc = allocator_type(),
    //     typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr):
    // _alloc(alloc){
    //     (void)last;
    //     std::cout << typeid(first).name() << std::endl;
    //     std::cout << "here 2" << std::endl;
    // }
    
    vector (const vector& x) : _alloc(){
        _array = NULL;
        _size = 0;
        _allocSize = 0;
        *this = x;
    }
    
    /*================
    |   DESTRUCTOR   |
    ================*/
        ~vector(){
        _alloc.deallocate(_array, size());
        };

    /*============
    |   OPERATOR  |
    ===============*/

    /* operator[] */
    reference operator[] (size_type n){
        return (_array[n]);
    }
    const_reference operator[] (size_type n)const{
        return (_array[n]);
    }


    vector &operator=(const vector& x){
		if (x == *this)
			return (*this);
		this->clear();
		// insert(this->begin(), x.begin(), x.end());
		return (*this);
	}

    /*============
    |   ITERATOR  |
    ===============*/   
    iterator begin() {
        return (_array);
    }

    iterator end() {
        return (_array + _size );}
    
    const_iterator begin() const {
        return (_array);
    }

    const_iterator end() const {
        return (_array + _size);
    }

    reverse_iterator rbegin(){

        return (_array + (_size - 1));
    }
    // const_reverse_iterator rbegin() const{}

    reverse_iterator rend(){
        return (_array - 1);
    }
    // const_reverse_iterator rend() const;

    /*====================
    |   MEMBER FUNCTION   |
    =====================*/
	void reserve(size_t new_cap) {
		if (new_cap > max_size())
			throw std::length_error("vector::reserve");
        size_type y = -1;
        if (_allocSize < new_cap) {
            T *newArr = _alloc.allocate(new_cap + 1);
            while (++y <= new_cap && y < size()) {
                _alloc.construct(&newArr[y], _array[y]);
            }
            _alloc.deallocate(_array, size());
            _allocSize = new_cap;
            _array = newArr;
        }
    }

    size_t size() const {
        return (_size);
    }

    size_t max_size() const {
        return (allocator_type().max_size());
    }

    size_t capacity() const {
        return (_allocSize);
    }
    iterator erase (iterator pos){
        iterator ret = pos;
        for(;pos != end();pos++){
            _alloc.destroy(&(*pos));
            _alloc.construct(&(*pos), *pos + 1);
        }
        _size--;
        return (ret);
    }
    iterator erase (iterator first, iterator last){
        iterator ret = first;
        for(;first != last ; --last){
            erase(first);
        }
        return (ret);
    }

    void    clear(){
        erase(begin(),end());
    }

    iterator insert(iterator pos, const T &value)
	{
		difference_type delta = pos - begin();
		insert(pos, 1, value);
		return (begin() + delta);
	}

    void  insert(iterator pos, size_t count, const T &value) {
		size_t delta = pos - begin();
        if (size() == 0)
            delta = 0;
		if (_allocSize < _size + count)
		{
			if (_allocSize * 2 < _size + count)
				reserve(_size + count);
            else
				reserve(_allocSize * 2 + !_allocSize);
        }
		pos = begin() + delta;
		_size += count;
        for (iterator it = end() -1 ; it != pos - count; it--)
            *(it + count) = *it;
        for (iterator it = pos; it != pos + count; it++)
			*it = value;
    }

    void push_back (const value_type& val) {
        insert(end(), val);
    }

    void resize (size_type n, T val = value_type()) {
        if (n > size())
        {
            if (_allocSize  < n)
				this->reserve(n);
            for (size_t i = _size; i < n; i++)
                _array[i] = val;
            _size = n;
        }
        else if (n < size())
            erase(begin() + n, end());
    }

    // void assign (InputIterator first, InputIterator last) {

    // }

    void assign (size_type n, const value_type& val) {
        clear();
        resize(n, val);
    }
  
 
    reference at(size_type pos)
	{
		std::stringstream str;
		if (pos > size())
		{
			str << "vector::_M_range_check: __n (which is " << pos << ") >= size() (which is " << size() << ")";
			throw std::out_of_range(str.str());
		}
		else
			return (_array[pos]);
	};

    const_reference at(size_type pos) const
	{
		std::stringstream str;
		if (pos > size())
		{
			str << "vector::_M_range_check: __n (which is " << pos << ") >= size() (which is " << size() << ")";
			throw std::out_of_range(str.str());
		}
		else
			return (_array[pos]);
	};

    //ADD 
    //const_reference front() const {
    //     if (_size != 0)
    //         return &begin();
    // }
    reference front() {
        return (*(begin()));
    }

    const_reference front() const {
         return (*(begin()));
    }

    reference back() {
        return (*(end() - 1));
    }
    //ADD const_reference back() const;
    const_reference back() const {
        return (*(end() - 1));
    }


    bool empty() const {
        return (_size == 0 ? true : false);
    }

    allocator_type get_allocator()const {
        return (_alloc);
    }
    // void swap (vector& x) {
    //     pointer startTmp = _start;
    //     pointer endTmp = _end;
    //     size_t sizeTmp = size();
    //     size_t capacityTmp = _allocSize;

    //     _start = x._start;
    //     _end = x._end;
    //     _size = x.size();
    //     _allocSize = x._allocSize;

    //     x._start = startTmp;
    //     x._end = endTmp;
    //     x._size = sizeTmp;
    //     x._allocSize = capacityTmp;
    // }

        // iterator insert (iterator position, const value_type& val);	
        // void insert (iterator position, size_type n, const value_type& val);
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last);
    // template<class InputIterator>
    // void assign(InputIterator first, InputIterator last);

    }; // end of vector class
}; //end of ft namespace


/*======================
|   NO-MEMBER OPERATOR |
=======================*/



template <class T, class Alloc>
bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
    if (lhs.size() != rhs.size())
        return (false);
    typename ft::vector<T>::const_iterator it_lhs = lhs.begin();
    typename ft::vector<T>::const_iterator it_rhs = rhs.begin();
    for(; it_lhs != lhs.end(); it_lhs++)
        if(*it_lhs != *(it_rhs))
            return (false);
    return (true);
}

#endif