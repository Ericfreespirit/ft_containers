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


    private:
        T *_array;
        A _alloc;
        pointer _start;
        pointer _end;
        size_type _size;

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
			this->_array = this->_alloc.allocate(n);
        for(size_type i = 0;i < n; i++)
            this->_alloc.construct(&this->_array[i], val);
			this->_start = this->_array;
			this->_end = &this->_array[n];
            std::cout << "here 1" << std::endl;
    }

    template <class T, class A>
    template <class InputIterator>
    vector<T, A>::vector(InputIterator first, InputIterator last, const A& alloc,
            typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*): _alloc(alloc)
    {
            (void)first;
            (void)last;
            std::cout << "here 2" << std::endl;
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


}; //end of ft namespace

#endif