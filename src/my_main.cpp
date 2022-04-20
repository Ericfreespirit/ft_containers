#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
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
#define T2 std::string
typedef ft::pair<const T1, T2> T3;
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
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

#include <list>
int		main(void)
{
	ft::map<int,int>mp;

	mp[1] = 1;
	mp[2] = 1;
	mp[3] = 1;
	mp[4] = 1;

	// mp.erase(mp.begin(), mp.end());
	// mp.erase(++mp.begin());
	mp.erase(mp.find(3));
	// mp.erase(mp.begin());
	ft::map<int,int>::iterator it = mp.begin();
	for(;it != mp.end(); it++){
		std::cout << it->first << std::endl;
	}

	return (0);
}


/*
	//INSTER TEST
	ft::map<char, int> mp;
	mp['a'] = 1;
	mp['b'] = 1;
	mp['c'] = 1;
	mp['d'] = 1;

	ft::map<char, int >::iterator it = mp.begin();
	std::cout << "Adress: " << &(--mp.begin()) << " ";
	std::cout << (--mp.begin())->first << std ::endl;
	std::cout << "============" << std::endl;
	for(; it != mp.end(); it++){
		std::cout << "Adress: "<< &(*it) << " ";
		std::cout << it->first << std ::endl;
	}
	std::cout << "============" << std::endl;
		std::cout << "Adress: "<< &(*it) << " ";
		std::cout << it->first << std ::endl;

*/