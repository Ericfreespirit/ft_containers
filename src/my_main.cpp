
// #include "our_test/AllTest.hpp"
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#if 1 //CREATE A REAL STL EXAMPLE
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
    int i = 0;
		for (; it != ite; ++it) {
      // if (i == 10)
      //   break;
      // i++;
			std::cout << "- " << *it << std::endl; }
	}
	std::cout << "###############################################" << std::endl;
}


int		main(void)
{
	ft::vector<int> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		std::cout << "vct.at(): " << vct.at(i) << " | ";
		std::cout << "vct[]: " << vct[i] << std::endl;
	}
	printSize(vct);

	ft::vector<int> const vct_c(vct);

	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	try {
		vct.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	return (0);
}


// int		main(void)
// {
// 	ft::vector<int> vct(10);
// 	ft::vector<int> vct2;

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = (vct.size() - i) * 3;
// 	printSize(vct);

// 	vct2.insert(vct2.end(), 42);
// 	vct2.insert(vct2.begin(), 2, 21);
// 	printSize(vct2);

// 	vct2.insert(vct2.end() - 2, 42);
// 	printSize(vct2);

// 	vct2.insert(vct2.end(), 2, 84);
// 	printSize(vct2);

// 	vct2.resize(4);
// 	printSize(vct2);
//   std::cout << "AHAHHAHAHAHAH" << std::endl;
// 	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
//   std::cout << "PFKGJWOJGZGJOG" << std::endl;
// 	// vct.clear();
// 	printSize(vct2);
//   std::cout << "PFKGJWOJGZGJOG" << std::endl;
// 	// printSize(vct);
// 	return (0);
// }

// int main ()
// {
//   ft::vector<int> myvector (3,100);
//   ft::vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   ft::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// int main() {
// 	ft::vector<int> v1(10, 42);
// 	ft::vector<int> v2;

  
// 	v2.insert(v2.begin(), 10, 12);
// 	// v2.insert(v1.begin(),v1.begin(), v1.end());

// 	// std::cout << v2[0] << std::endl;
// 	for(ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
// 	  std::cout << *it << std::endl;
// 	return (0);
// }