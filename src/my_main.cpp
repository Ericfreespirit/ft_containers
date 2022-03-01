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
void printSize(ft::vector<T> &vect){
	std::cout << "size: "<< vect.size()<<std::endl;
	for(size_t i = 0; i < vect.size(); i++)
		std::cout << "#" << i << " " << vect[i] << " |";
	std::cout << std::endl;
}

template <typename T>
void checkErase(ft::vector<T> &vect, typename ft::vector<T>::iterator it){
	vect.erase(it);
	printSize(vect);
}

template <typename T>
void checkErase(ft::vector<T> &vect, typename ft::vector<T>::iterator it, typename ft::vector<T>::iterator ite){
	vect.erase(it, ite);
	printSize(vect);
}

int test_erase()
{
	ft::vector<int> vect;

	for(size_t i = 0;i < 10;i++)
		vect.insert(vect.begin() +i,i);
	printSize(vect);
	// checkErase(vect, vect.begin());
	checkErase(vect, vect.begin(), vect.end());
}


int main() {


	return (0);
}