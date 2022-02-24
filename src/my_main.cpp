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

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
int main() {
 ft::vector<int> myvector;

//   ft::vector<int> vector1(10,100);
//   ft::vector<int>::iterator it = vector1.begin();
//   ft::vector<int>::iterator ite = vector1.end();
//   int i = 1;
//   for (ft::vector<int>::iterator it = vector1.begin() ; it != vector1.end(); ++it)
// 		std::cout << "#" << i++ << " " << *it << std::endl;
//   vector1.reserve(15);
//   i = 1;
//   for (ft::vector<int>::iterator it3 = vector1.begin() ; it3 != vector1.end(); ++it3)
// 		std::cout << "#" << i++ << " " << *it3 << std::endl;
//   std::cout << "vector.size 1: " << vector1.size() << " vector capacity: " << vector1.capacity() << " vector1.max_size: " << vector1.max_size() << std::endl; 
//   ft::vector<int>vector2(it, ite);
  


	ft::vector<int> vec;
	for(size_t i = 0; i < 10;i++)
		vec.insert(vec.begin() + i, i);

	for(size_t i = 0; i < vec.size();i++)
		std::cout << "#" << i << " "<< vec[i] << std::endl;
	std::cout << "--------" << std::endl;
	// vec.erase(vec.begin());
		for(size_t i = 0; i < vec.size();i++)
		std::cout << "#" << i << " "<< vec[i] << std::endl;
	return (0);
}