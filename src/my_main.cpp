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

template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


int main() {

	// ft::vector<int> v1(10,100);
	// std::cout << "vector.size 1: " << v1.size() << " vector capacity: " << v1.capacity() << " vector1.max_size: " << v1.max_size() << std::endl; 
	// ft::vector<int>().swap(v1);
	// std::cout << "vector.size 1: " << v1.size() << " vector capacity: " << v1.capacity() << " vector1.max_size: " << v1.max_size() << std::endl; 
  


	// ft::vector<int> vect;
	// for(size_t i = 0;i < 10;i++)
	// 	vect.insert(vect.begin() +i,i);
	// std::cout <<"size: " << vect.size() << std::endl;
	// // vect.erase(vect.begin(), vect.end());
	// vect.clear();
	// std::cout <<"size: " << vect.size() << std::endl;
	// for(size_t i = 0;i < vect.size();i++)
	// 	std::cout << vect[i] << std::endl;

	ft::vector<int> vct(10);
	ft::vector<int> vct2;
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);
	std::cout << std::endl << "1" << std::endl;

	vct2.insert(vct2.end(), 42);
	std::cout << std::endl << "4" << std::endl;
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);
	std::cout << std::endl << "2" << std::endl;
	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);
	std::cout << std::endl << "3" << std::endl;

	// vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	// vct2.resize(4);
	printSize(vct2);
	
	// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);

	// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	// vct.clear();
	// printSize(vct2);

	// ft::vector<int> vct(10);
	// ft::vector<int> vct2;
	// for (unsigned long int i = 0; i < vct.size(); ++i)
	// 	vct[i] = (vct.size() - i) * 3;
	// std::cout << vct.size() << std::endl;


	// vct2.insert(vct2.end(), 42);
	// vct2.insert(vct2.begin(), 2, 21);
	// std::cout << vct2.size() << vct2.capacity() << std::endl;
	// for (ft::vector<int>::iterator it = vct2.begin(); it != vct2.end(); it++)
	// 	std::cout << *it << std::endl;

	// vct2.insert(vct2.end() - 2, 42);
	// std::cout << vct2.size() << std::endl;
	// std::cout << vct2.size() << vct2.capacity() << std::endl;
	// for (ft::vector<int>::iterator it = vct2.begin(); it != vct2.end(); it++)
	// 	std::cout << *it << std::endl;

	// vct2.insert(vct2.end(), 2, 84);
	// std::cout << vct2.size() << std::endl;
	// std::cout << vct2.size() << vct2.capacity() << std::endl;
	// for (ft::vector<int>::iterator it = vct2.begin(); it != vct2.end(); it++)
	// 	std::cout << *it << std::endl;

	// vct2.resize(4);
	// std::cout << vct2.size() << std::endl;

	// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	// vct.clear();
	// printSize(vct2);

	// printSize(vct);
	return (0);
}