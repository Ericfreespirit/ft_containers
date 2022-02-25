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

	// ft::vector<int> v1(10,100);
	// std::cout << "vector.size 1: " << v1.size() << " vector capacity: " << v1.capacity() << " vector1.max_size: " << v1.max_size() << std::endl; 
	// ft::vector<int>().swap(v1);
	// std::cout << "vector.size 1: " << v1.size() << " vector capacity: " << v1.capacity() << " vector1.max_size: " << v1.max_size() << std::endl; 
  


	ft::vector<int> vect;

	for(size_t i = 0;i < 10;i++)
		vect.insert(vect.begin() +i,i);
	std::cout <<"size: " << vect.size() << std::endl;
	// vect.erase(vect.begin(), vect.end());
	vect.clear();
	std::cout <<"size: " << vect.size() << std::endl;
	for(size_t i = 0;i < vect.size();i++)
		std::cout << vect[i] << std::endl;
	return (0);
}