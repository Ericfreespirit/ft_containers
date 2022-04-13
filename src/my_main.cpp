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
int main() {

	ft::map<char, int> mymap;
	mymap['a'] = 200;
 	mymap['b'] = 100;
	mymap['c'] = 300;
	mymap['d'] = 400;
	mymap['e'] = 500;
	mymap['f'] = 600;
	mymap['g'] = 700;



	ft::map<char, int>::iterator it = mymap.begin();
	ft::map<char, int>::iterator ite = mymap.end();
	std::cout << "begin: " << it->first << std::endl;
	std::cout << "end: " << ite->first << std::endl;
	mymap.erase(mymap.find('b'));
	// mymap.print();
	for (; it!=ite; it++){
    	std::cout << it->first << " => " << it->second << '\n';
	}

}
