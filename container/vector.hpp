#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "iterator_traits.hpp"
#include "iterator_vector.hpp"
#include "const_iterator_vector.hpp"
#include <type_traits>
#include "is_.hpp"


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

        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type &val = value_type(),
            const allocator_type& alloc = allocator_type());
        template <class InputIterator>
        vector(InputIterator first,InputIterator last,
            const allocator_type& alloc = allocator_type(),
            typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr);
        vector (const vector& x);
        ~vector();
        /*==============================
        |   MEMBER FUNCTION PROTOTYPE  |
        ==============================*/
        void reserve (size_type n);
        size_type max_size() const;
        size_type size() const;
        size_type capacity() const;
        iterator insert (iterator position, const value_type& val);
        void insert (iterator position, size_type n, const value_type& val);
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last);

        // iterator insert (iterator position, const value_type& val);	
        // void insert (iterator position, size_type n, const value_type& val);
        // template <class InputIterator>
        // void insert (iterator position, InputIterator first, InputIterator last);



    private:
        T *_array;
        A _alloc;
        pointer _start;
        pointer _end;
        size_type _size;
        size_t  _allocSize;

    public:
    /*============
    |   ITERATOR  |
    ===============*/
    iterator begin() {
        return (this->_start);
    }

    iterator end() {
        return (this->_end);}

    };

    /*================
    |   CONSTRUCTOR   |
    ==================*/
    template <class T, class A>
    vector<T, A>::vector(const A &alloc):
    _alloc(alloc){
        this->_array = this->_alloc.allocate(0);
        this->_start = NULL;
        this->_end = NULL;
    }

    template <class T, class A>
    vector<T, A>::vector (size_type n, const T &val,
        const A &alloc):
    _alloc(alloc),
		_size(n)
		{
            _allocSize = val;
			this->_array = this->_alloc.allocate(n);
        for(size_type i = 0;i < n; i++)
            this->_alloc.construct(&this->_array[i], val);
			this->_start = this->_array;
			this->_end = &this->_array[n];
    }

    template <class T, class A>
    template <class InputIterator>
    vector<T, A>::vector(InputIterator first, InputIterator last, const A& alloc,
            typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*): _alloc(alloc)
    {
            (void)first;
            (void)last;
    }

    /*================
    |   DESTRUCTOR   |
    ================*/
    template <class T, class A>
    vector<T, A>::~vector(){
        // this->*clear();
    }

    /*====================
    |   MEMBER FUNCTION   |
    =====================*/
    template <class T, class A>
	void vector<T, A>::reserve(size_t new_cap) {
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

    template <class T, class A>
    size_t ft::vector<T, A>::size() const {
        return (this->_size);
    }

    template <class T, class A>
    size_t ft::vector<T, A>::max_size() const {
        return (allocator_type().max_size());
    }

    template <class T, class A>
    size_t ft::vector<T, A>::capacity() const {
        return (this->_allocSize);
    }

    template <class T, class A>
    ft::iterator_vector<T> ft::vector<T, A>::insert(ft::iterator_vector<T> pos, const T &value)
	{
		difference_type delta = pos - this->begin();

		this->insert(pos, 1, value);
		return (this->begin() + delta);
	}

	template <class T, class A>
    void ft::vector<T, A>::insert(ft::iterator_vector<T> pos, size_t count, const T &value)
	{
		if (this->_allocSize < this->_size + count)
				this->reserve(this->_size + count);
		_size += count;
		for (iterator it = pos; it != pos + count; ++it)
			*it = value;
	}

}; //end of ft namespace

#endif