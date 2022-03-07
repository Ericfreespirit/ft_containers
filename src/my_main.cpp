
// #include "our_test/AllTest.hpp"
#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	// #include <map.hpp>
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


int main() {
	ft::vector<int> v1(3, 42);
	ft::vector<int> v2;

	v2.insert(v2.begin(), 10, 42);
	// v2.insert(v1.begin(),v1.begin(), v1.end());

	std::cout << v2[0] << std::endl;
	// for(ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	// std::cout << *it << std::endl;
	return (0);
}