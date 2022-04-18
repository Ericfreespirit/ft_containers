#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	// #include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

#define TESTED_NAMESPACE ft
#define T1 int
#define T2 int
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator iterator;

static int iter = 0;


#define _pair ft::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param, U param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.insert(param, param2);
	printSize(mp);
}

#include <list>
int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i){
		lst.push_back(T3(lst_size - i, i));
	}

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	// for (;it != ite; it++)
	// 	std::cout << it->first << std::endl;
	std::cout << ite->first << std::endl;
	std::cout << &ite->first << std::endl;
	std::cout <<"-------" << std::endl;
	ite = --mp.end();
	std::cout << ite->first << std::endl;
	std::cout << &ite->first << std::endl;
	std::cout <<"-------" << std::endl;
	ite = --(--mp.end());
	std::cout << "loop" << std::endl;
	for (;1; ite--){
		getwchar();
	std::cout << ite->first << std::endl;
	std::cout << &ite->first << std::endl;
	}

	return (0);
}
