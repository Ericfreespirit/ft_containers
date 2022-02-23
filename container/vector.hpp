#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "iterator_vector.hpp"
// #include "const_iterator_vector.hpp"
#include <type_traits>
#include "traits.hpp"


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
    // typedef ft::const_iterator_vector<T> const_iterator;
    // typedef reverse_iterator reverse_iterator;
    // typedef const_reverse_iterator const_reverse_iterator;
private:
    T *_array;
    A _alloc;
    pointer _start;
    pointer _end;
    size_type _size;
    size_t  _allocSize;

public:

    /*================
    |   CONSTRUCTOR   |
    ==================*/
    explicit vector (const allocator_type& alloc = allocator_type()):
    _alloc(alloc){
        this->_array = this->_alloc.allocate(0);
        this->_start = NULL;
        this->_end = NULL;
    }

    explicit vector (size_type n, const value_type &val = value_type(),
        const allocator_type& alloc = allocator_type()):
    _alloc(alloc),
	_size(n){
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
        return (this->_end);}


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

    iterator insert(iterator pos, const T &value)
	{
		difference_type delta = pos - this->begin();

		this->insert(pos, 1, value);
		return (this->begin() + delta);
	}

    void  insert(iterator pos, size_t count, const T &value)
	{
		if (this->_allocSize < this->_size + count)
				this->reserve(this->_size + count);
		_size += count;
		for (iterator it = pos; it != pos + count; ++it)
			*it = value;
	}
        // iterator insert (iterator position, const value_type& val);	
        // void insert (iterator position, size_type n, const value_type& val);
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last);
        
    }; // end of vector class
}; //end of ft namespace

#endif