#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "iterator_vector.hpp"
#include "const_iterator_vector.hpp"
#include <type_traits>
#include "traits.hpp"
#include <sstream>

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
    // typedef reverse_iterator reverse_iterator;
    // typedef const_reverse_iterator const_reverse_iterator;
private:
    T *_array;
    A _alloc;
    pointer _start;
    pointer _end;
    size_type _size;
    size_type  _allocSize;

public:

    /*================
    |   CONSTRUCTOR   |
    ==================*/
    explicit vector (const allocator_type& alloc = allocator_type()):
    _alloc(alloc){
        this->_array = this->_alloc.allocate(0);
        this->_start = NULL;
        this->_end = NULL;
        _allocSize = 0;
        _size = 0;
    }

    explicit vector (size_type n, const value_type &val = value_type(),
        const allocator_type& alloc = allocator_type()):
    _alloc(alloc),
	_size(n){
        _allocSize = 0;
		this->_array = this->_alloc.allocate(n);
         for(size_type i = 0;i < n; i++)
        this->_alloc.construct(&this->_array[i], val);
		this->_start = this->_array;
		this->_end = &this->_array[n];
        
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
    
    vector (const vector& x);
    
    /*================
    |   DESTRUCTOR   |
    ================*/
        ~vector(){
            
        };

    /*============
    |   OPERATOR  |
    ===============*/

    /* operator[] */
    reference operator[] (size_type n){
        return (this->_array[n]);
    }
    const_reference operator[] (size_type n)const{
        return (this->_array[n]);
    }

    /* operator= */
    // vector& operator= (const vector& x){

    // }

    /*============
    |   ITERATOR  |
    ===============*/
    iterator begin() {
        return (this->_start);
    }

    iterator end() {
        return (this->_start + _size);}


    /*====================
    |   MEMBER FUNCTION   |
    =====================*/
	void reserve(size_t new_cap) {
		if (new_cap > this->max_size())
			throw std::length_error("vector::reserve");
        size_type y = -1;
        if (this->_allocSize < new_cap) {
            T *newArr = _alloc.allocate(new_cap);
            while (++y <= new_cap && y < _size) {
                this->_alloc.construct(&newArr[y], this->_array[y]);
            }
            this->_allocSize = new_cap;
            delete [] this->_array;
            this->_array = newArr;
            this->_start = this->_array;
            this->_end = &this->_array[y];
        }
    }

    size_t size() const {
        return (this->_size);
    }

    size_t max_size() const {
        return (allocator_type().max_size());
    }

    size_t capacity() const {
        return (this->_allocSize);
    }
    // iterator erase (iterator pos){
    //     /*
    //         destroy(pos)
    //         if (pos != end)
    //          construct
    //         init_all value
    //     */
    //     for(size_type i = 0; i < _size;i++){
    //         _alloc.destroy(pos + i);
    //         _alloc.construct(&_array[pos+i], _array[pos+i+1]);
    //     }
    //     _start = _array;
    //     _end = &_array[i];
    //     _size--;
    // }
    iterator insert(iterator pos, const T &value)
	{
		difference_type delta = pos - this->begin();

		this->insert(pos, 1, value);
		return (this->begin() + delta);
	}

    void  insert(iterator pos, size_t count, const T &value) {
		size_t delta = pos - this->begin();
		if (this->_allocSize < this->_size + count)
		{
			if (this->_allocSize * 2 < this->_size + count)
				this->reserve(this->_size + count);
			else
				this->reserve(this->_allocSize * 2 + !this->_allocSize);
		}
		pos = this->begin() + delta;
		_size += count;
        		for (iterator it = this->end() - 1; it != pos - count - 1; it--)
            *(it + count) = *it;
        for (iterator it = pos; it != pos + count; it++)
			*it = value;
    }

    void push_back (const value_type& val) {
        this->insert(this->end(), val);
    }

    reference at(size_type pos)
	{
		std::stringstream str;
		if (pos > size())
		{
			str << "vector::_M_range_check: __n (which is " << pos << ") >= this->size() (which is " << this->size() << ")";
			throw std::out_of_range(str.str());
		}
		else
			return (this->_array[pos]);
	};

	// const_reference at(size_type pos) const
	// {
	// 	std::stringstream str;
	// 	if (pos > size())
	// 	{
	// 		str << "vector::_M_range_check: __n (which is " << pos << ") >= this->size() (which is " << this->size() << ")";
	// 		throw std::out_of_range(str.str());
	// 	}
	// 	else
	// 		return (this->_array[pos]);
	// };

    reference front() {
         return (*(this->begin()));
    }

    reference back() {
        return (*(this->end() - 1));
    }

    // const_reference back() const {

    // }

    // const_reference front() const {
    //     if (_size != 0)
    //         return &begin();
    // }
        // iterator insert (iterator position, const value_type& val);	
        // void insert (iterator position, size_type n, const value_type& val);
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last);
    // template<class InputIterator>
    // void assign(InputIterator first, InputIterator last);
    void assign (size_type n, const value_type &val){
        /*
            if (old value)
            {
                destroy;
                realloca allocate
            }
        
        */

        this->_array = this->_alloc.allocate(n);
                 for(size_type i = 0;i < n; i++)
        this->_alloc.construct(&this->_array[i], val);
		this->_start = this->_array;
		this->_end = &this->_array[n];
        this->_size = n;
        this->_allocSize = n;
    }

    // void resize (size_type n, value_type val = value_type()){
    // }
    
    // allocator_type get_allocator()const{
    //     return (this->_alloc);
    // }
        

        


    }; // end of vector class
}; //end of ft namespace

#endif