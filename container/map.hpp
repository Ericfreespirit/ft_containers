#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <limits>
#include "../utils/Pair.hpp"
#include "../utils/AVL.hpp"
#include "../include/tree_iterator.hpp"
#include "../include/iterator_map.hpp"
#include "../include/const_iterator_map.hpp"
#include "../utils/traits.hpp"
#include "../utils/algorithm.hpp"


namespace ft{

template < class Key,                                   			 	  // map::key_type
           class T,                                       				// map::mapped_type
           class Compare = std::less<Key>,                   		 	// map::key_compare
           class Allocator = std::allocator<ft::pair <const Key,T> > // map::allocator_type  
					 >    
class map{
public:

	/*==========
  	|   TYPES   |
	===========*/
	typedef Key key_type;
	typedef T mapped_type;
	typedef ft::pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename Allocator::reference reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
  typedef std::ptrdiff_t difference_type;
 	typedef size_t size_type;

	typedef ft::iterator_map<value_type, key_compare> iterator;
	typedef ft::const_iterator_map<value_type, key_compare> const_iterator;
	// typedef std::reverse_iterator<iterator> reverse_iterator;
	// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;



	/*=========================
  	|   CLASS VALUE_COMPARE	   |
  	===========================*/
	class value_compare
	: public std::binary_function<value_type,value_type,bool> {
	friend class map;
	protected:
		Compare comp;
		value_compare(Compare c = Compare()) : comp(c) {}
	public:
		bool operator()(const value_type& x, const value_type& y) const {
		return comp(x.first, y.first);
	}
	}; //end of class value_compare

	/*=============================
  	|   CONSTRUCT/ COPY/ DESTROY   |
  	==============================*/
	public:
		explicit map(const Compare& comp = Compare(),
		const Allocator& alloc = Allocator()){
			_avl._alloc = alloc;
			_avl._key_compare = comp;
			_avl._dummyNode = _avl._alloc.allocate(1);
      _avl._alloc.construct(_avl._dummyNode, Node<value_type>());
		};


		template <class InputIterator>
		map(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Allocator& alloc = Allocator(),
        typename ft::enable_if<ft::is_iterator<InputIterator>::value, InputIterator>::type* = 0){
			_avl._alloc = alloc;
			_avl._key_compare = comp;
			_avl._dummyNode = _avl._alloc.allocate(1);
      _avl._alloc.construct(_avl._dummyNode, Node<value_type>());
			insert(first, last);
		}

		// map(const map<Key,T,Compare,Allocator>& x);

		~map(){
			_avl.freeAVL(_avl._head);
			_avl.freeDummyNode();
		};

		// map<Key,T,Compare,Allocator>&
		// operator=(const map<Key,T,Compare,Allocator>& x);

	private:
		typedef	Node<value_type> _node;
		typedef typename allocator_type::template rebind<_node>::other		_avl_allocator;

		AVL<value_type, key_compare> _avl;


	/*=============
  |   ITERATOR   |
  ===============*/
	public:
	iterator begin(){
		if (!_avl._head)
			return (_avl._dummyNode);
		return (_avl.minValNode(_avl._head));
	}
	iterator end(){
		return (_avl._dummyNode);
	}
	const_iterator begin() const{
		if (!_avl._head)
			return (_avl._dummyNode);
		return (_avl.minValNode(_avl._head));
	}
	const_iterator end() const{
		return (_avl._dummyNode);
	}
	// reverse_iterator rbegin();
	// const_reverse_iterator rbegin() const;
	// reverse_iterator rend();
	// const_reverse_iterator rend() const;

	/*=============
  |   CAPACITY   |
  ===============*/
	// bool empty() const;
	size_type size() const{
		return (_avl.getSize());
	}
	size_type max_size() const{
		return (_avl_allocator().max_size());
	}
	// allocator_type get_allocator() const;

	/*================
  	|   ELMT ACCESS   |
 	==================*/
	T& operator[](const key_type& x){
		ft::pair<iterator, bool> tmp;

		tmp = insert(value_type(x, mapped_type()));
		return (tmp.first->second);
	}

	/*================
  	|   MODIFIERS     |
 	==================*/

	ft::pair<iterator, bool> insert(const value_type& x){
		size_t sz = _avl.getSize();
		_avl._head = _avl.insert(_avl._head, x);

		Node<value_type> *node = _avl.find(_avl._head, x.first);
		ft::pair<iterator, bool> p(node, false);
		if (_avl.getSize() != sz)
			p = ft::pair<iterator, bool> (node, true);
		return (p);
	}

	iterator insert(iterator , const value_type& x){
		_avl._head = _avl.insert(_avl._head, x);
		return (_avl.find(_avl._head, x.first));
	}
  
	template <class InputIterator>
	typename ft::enable_if<ft::is_iterator<InputIterator>::value, InputIterator>::void_t 
	insert(InputIterator first,InputIterator last){
		for(;first != last; first++)
			insert(*first);
	}

	void erase(iterator position){
		_avl._head = _avl.deleteNode(_avl._head, (*position).first);
	}

	size_type erase(const key_type& x){
		size_t sz = _avl.getSize();
		_avl._head = _avl.deleteNode(_avl._head, x.first);
		if (_avl.getSize() != sz)
			return(1);
		return (0);
	}
	// void erase(iterator first, iterator last);
	// void swap(map<Key,T,Compare,Allocator>&);
	void clear(){
		iterator it = begin();

		for(;it != end(); it++)
			erase(it);
		_avl._head = _avl._dummyNode;
	}

	/*==============
	|   OBSERVERS   |
	===============*/
	// key_compare key_comp() const;
	value_compare value_comp() const{
		return (value_compare());
	}

	/*==================
  	|   MAP OPERATION   |
	===================*/
	iterator find(const key_type& x){
			Node<value_type> *node = _avl.find(_avl._head, x);
			if (node == NULL)
				return (end());
			return (node);
	}
	const_iterator find(const key_type& x) const{
			Node<value_type> *node = _avl.find(_avl._head, x);
			if (node == NULL)
				return (end());
			return (node);
	}
	size_type count(const key_type& x) const{
		if (_avl.find(_avl._head, x) != NULL)
			return (1);
		return (0);
	}
	// iterator lower_bound(const key_type& x);
	// const_iterator lower_bound(const key_type& x) const;
	// iterator upper_bound(const key_type& x);
	// const_iterator upper_bound(const key_type& x) const;

	// pair<iterator,iterator>
	// equal_range(const key_type& x);

	// pair<const_iterator,const_iterator>
	// equal_range(const key_type& x) const;


};// end of class map


/*=========================
|   NON-MEMBER OVERLOADS   |
==========================*/
// template <class Key, class T, class Compare, class Allocator>
// bool operator==(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator< (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator!=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator> (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator>=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator<=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// void swap(map<Key,T,Compare,Allocator>& x,
// map<Key,T,Compare,Allocator>& y);

}; // end of namespace
#endif