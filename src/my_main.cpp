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


	ft::vector<int> vct(10);
	ft::vector<int> vct2;

	// for (ft::vector<int>::iterator it = vct.begin() ; it != vct.end(); ++it)
	// 	std::cout << "#" << " " << *it << std::endl;
	std::cout << vct.size() << std::endl;
	for(unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct[i] = (vct.size() - i) * 3; 
	}
	int i =0;
	// for (ft::vector<int>::iterator it = vct.begin() ; it != vct.end(); ++it)
	// 	std::cout << "#" << i++ << " " << *it << std::endl;
	std::cout << "-- "<< vct2.size() << std::endl;

	vct2.insert(vct2.end() - 2, 42);
	i = 0;
	for (ft::vector<int>::iterator it = vct2.begin() ; it != vct2.end(); ++it)
		std::cout << "#" << i++ << " " << *it << std::endl;

	vct2.insert(vct2.end(), 2, 84);

	i = 0;
	for (ft::vector<int>::iterator it = vct2.begin() ; it != vct2.end(); ++it)
		std::cout << "#" << i++ << " " << *it << std::endl;

	// ft::vector<int> v1;
	// v1.reserve(10);
	// for (int i = 0; i < 9; i++)
	// 	v1.insert(v1.begin() + i, i);
	// std::cout << "capacity: " << v1.capacity() << std::endl;
	// for (ft::vector<int>::iterator it = v1.begin() ; it != v1.end(); ++it)
	// 	std::cout << "#"<< *it << std::endl;
// 		std::cout << "#" << i++ << " " << *it << std::endl;
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
  


	// int y = 0;
	// ft::vector<int> vec(50, 100);
	// std::cout << vec.size() << std::endl;

	// ft::vector<int> foo (3,100);   // three ints with a value of 100
  	// ft::vector<int> bar (5,200);
	// std::cout << "foo size = " << foo.size() << " " << foo.capacity() << " " << foo.front() << " " << foo.back() << std::endl;
	// std::cout << "bar size = " << bar.size() << " " << bar.capacity() << " " << bar.front() << " " << bar.back() << std::endl;
	// foo.swap(bar);
	// std::cout << "foo size = " << foo.size() << " " << foo.capacity() << " " << foo.front() << " " << foo.back() << std::endl;
	// std::cout << "bar size = " << bar.size() << " " << bar.capacity() << " " << bar.front() << " " << bar.back() << std::endl;

	// for (size_t i = 0; i < 10; i++)
	// 	vec.insert(vec.begin() +i, i);
	// for(size_t i = 0; i < vec.size();i++)
		// std::cout << "#" <<  i << " "<< vec[i] << std::endl;
	// ft::vector<int> vec(10,100);
	// vec.insert(vec.begin(), 200);

	// for(size_t i = 0; i < vec.size();i++)
	// 	std::cout << "#" <<  i << " "<< vec[i] << std::endl;

	// vec.insert(vec.begin() + 4, 4, 350);
	// for(size_t i = 0; i < vec.size();i++)
	// 	std::cout << "#" <<  i << " "<< vec[i] << std::endl;
	// vec.push_back(10);
	// for(size_t i = 0; i < vec.size();i++)
	// 	std::cout << "#" <<  i << " "<< vec[i] << std::endl;
	// ft::vector<int> vec1(0);
	// std::cout << vec.size() << std::endl;
	// std::cout << vec.front() << std::endl;
	// std::cout << vec.back() << std::endl;
	return (0);
}