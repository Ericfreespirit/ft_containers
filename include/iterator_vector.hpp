#ifndef ITERATOR_VECTOR_H
#define ITERATOR_VECTOR_H


namespace ft{

template <class T>
class iterator_vector : public ft::random_access_iterator_tag{
public:
    typedef iterator_vector<T> _it;
    iterator_vector(){};
    ~iterator_vector(){};
    iterator_vector(const _it &ref);


    _it &operator=(const _it &ref){
        return (*ref);
    }
}; //end of iterator_vector definition class



}//end of namespace ft


#endif