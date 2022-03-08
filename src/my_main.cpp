
// #include "our_test/AllTest.hpp"
#include <iostream>
#include <string>
#include <deque>
#include <vector>
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
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int>::const_iterator c

  return 0;
}