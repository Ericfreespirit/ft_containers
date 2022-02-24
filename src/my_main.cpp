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

<<<<<<< HEAD
  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(std::to_string(i));

//   for(int i = 0;i <10;i++)
// 	std::cout <<"#" <<i<<" "<<&myvector[i] <<std::endl;
	// myvector.erase(myvector.begin(), myvector.end()-2);
	myvector.erase(myvector.begin());
	// std::cout << "-----------"<< std::endl;
//   for(int i = 0;i <10;i++)
// 	std::cout <<"#" <<i<<" "<<&myvector[i] <<std::endl;
//   myvector.resize(5);
//   myvector.resize(8,100);
//   myvector.resize(12);

  std::cout << "myvector contains:";
  for (int i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
=======
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
  


	int y = 0;
	ft::vector<int> vector2(10,100);
	ft::vector<int>::iterator it2 = vector2.begin();
	it2++;
	it2++;
	it2++;
	for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
	it2 = vector2.insert(it2, 200);
y = 0;
	std::cout << "======================" << std::endl;
	for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
	std::cout << "vector.size 1: " << vector2.size() << " vector capacity: " << vector2.capacity() << " vector1.max_size: " << vector2.max_size() << std::endl; 
y = 0;
std::cout << "======================" << std::endl;
	vector2.insert(it2, 5, 200);
	for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
y = 0;
std::cout << "======================" << std::endl;
	vector2.erase(vector2.begin()+4, vector2.begin()+9);

for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
			std::cout << "======================" << std::endl;
			for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
			std::cout << "======================" << std::endl;

	vector2.insert(it2, 5, 350);
	std::cout << "======================" << std::endl;
	for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
	std::cout << "======================" << std::endl;
	y = 0;
	for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
	
	vector2.erase(vector2.begin()+3, vector2.begin()+5);
	std::cout << "======================" << std::endl;
	for (ft::vector<int>::iterator abc = vector2.begin(); abc != vector2.end(); abc++)
		std::cout << "#" << y++ << " " << *abc << std::endl;
>>>>>>> 0bee07f72357563d92691be966bc577d8b1a19ea
	return (0);
}