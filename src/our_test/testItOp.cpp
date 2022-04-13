#include "AllTest.hpp"

/*
    Put in a main for testing all iterator operator
*/
void    testItOp(){
	ft::vector<int> vct(10);
	ft::vector<int>::iterator it(vct.begin());
	ft::vector<int>::const_iterator ite(vct.end());

	std::cout << "==deference=="<< std::endl;
	std::cout << "*it" << *it << std::endl;
	std::cout << "it[index]" << it[3] << std::endl;

	std::cout << "==bool comparison=="<< std::endl;
	if (it != ite)
   		std::cout << "1)" << std::endl;
	if (it == ite)
   		std::cout << "2)" << std::endl;
	if (it < ite)
   		std::cout << "3)" << std::endl;
	if (it > ite)
    	std::cout << "4)" << std::endl;
	if (it <= ite)
  	  std::cout << "5)" << std::endl;
	if (it >= ite)
  	  std::cout << "6)" << std::endl;

	
	std::cout << "==arithmetic=="<< std::endl;
	//// std::cout << "it + ite: " << it + ite << std::endl; // Invalid in std
	//// std::cout << "it + ite " << it + ite << std::endl;
	//// std::cout << "it + 1: " << it + 1 << std::endl; 
	
	std::cout << "it - ite: " << it - ite << std::endl;
	std::cout << "*ite + 1: " << *ite + 1 << std::endl;
	std::cout << "*it - 1: " << *it + 1 << std::endl; 
	std::cout << "*ite - 1: " << *ite + 1 << std::endl;

	*it += *ite;
	*it -= *ite;
	//  *ite += *it;
	//// *ite -= *it;

	std::cout << "==incrementation / decrementation=="<< std::endl;
	std::cout << "*it++" << *it++ << std::endl;
	std::cout << "*it--" << *it-- << std::endl;
	std::cout << "++(*it)" << ++(*it) << std::endl;
	std::cout << "--(*it)" << --(*it) << std::endl;


  std::cout << "==END==" << std::endl;

  //*note switch it and ite if is can be in biderection
}

/*
	== Note ==
	
*/