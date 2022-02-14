#ifndef VECTOR_H
#define VECTOR_H
#include "iterator.hpp"

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

        typedef iterator::<std::random_access_iterator_tag, T> iterator;
        // typedef const_iterator const_iterator;
        // typedef reverse_iterator reverse_iterator;
        // typedef const_reverse_iterator const_reverse_iterator;

        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;


        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
        template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());
        // vector (const vector& x);
        ~vector();

    private:
        T *_array;
        A _alloc;

    }; //end of vector class


    /*================
    |   CONSTRUCTOR   |
    ==================*/
    template <class T, class A>
    vector<T, A>::vector(const A &alloc):
    _alloc(alloc){
        this->array = this->_alloc.allocate(0);
    }

    template <class T, class A>
    vector<T, A>::vector (size_type n, const value_type& val,
        const allocator_type& alloc):
    _alloc(alloc){
        this->_array = this->_alloc.allocate(n);
        for(size_type i = 0; i < n; i++)
            this->_alloc.construct(&this->_array[i], val);
    }

    // template <class T, class A>
    // template <class InputIterator>
    // vector<T, A>::vector (InputIterator first, 
    //     InputIterator last, const allocator_type& alloc):
    // _alloc(alloc){

    // }

    /*================
    |   DESTRUCTOR   |
    ==================*/
    template <class T, class A>
    vector<T, A>::~vector(){
        // this->*clear();
    }

    /*=============
    |   ITERATOR  |
    ===============*/




    /*====================
    |   MEMBER FUNCTION   |
    ======================*/
                                                                                    

} //end of ft namespace

#endif