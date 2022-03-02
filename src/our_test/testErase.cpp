#include "AllTest.hpp"
#include <vector>

template <typename T>
void print(ft::vector<T> &my_vect, std::vector<T> &vect){

	std::cout << "== Max_size ==" << std::endl;
	std::cout << "our_test : " << my_vect.max_size() << "| std: " << vect.max_size()<< std::endl;
	std::cout << "== Size ==" << std::endl;
	std::cout << "our_test: " << my_vect.size() << "| std: " << vect.size()<< std::endl;
	std::cout << "== Capacity ==" << std::endl;
	std::cout << "our_test : " << my_vect.capacity() << "| std: " << vect.capacity()<< std::endl;
	std::cout << "== Value ==" << std::endl;
	std::cout << "our_test: " << std::endl;
	for(size_t i = 0; i < my_vect.size();i++)
		std::cout <<"#"<<i<<" " <<my_vect[i] <<" |";
	std::cout << std::endl;
	std::cout << "std: " << std::endl;
	for(size_t i = 0; i < vect.size();i++)
		std::cout <<"#"<<i<<" " << vect[i] <<" |";
	std::cout << std::endl;
}


/*
	Compare the function erase of ft::vector and std::vector
*/
template <typename T>
void compErase(ft::vector<T> &my_vect, std::vector<T> &vect){
	if (my_vect.max_size() != vect.max_size())
		std::cout << "[Error max_size] our_test: " << my_vect.size() << "| std: " << vect.size()
		<< std::endl;
	if (my_vect.size() != vect.size())
		std::cout << "[Error size] our_test: " << my_vect.size() << "| std: " << vect.size()
		<< std::endl;
	if (my_vect.capacity() != vect.capacity())
		std::cout << "[Error capacity] our_test: " << my_vect.size() << "| std: " << vect.size()
		<< std::endl;
	for(size_t i = 0; i < vect.size(); i++)
		if (vect[i] != my_vect[i] )
		{
			std::cout << "[Error value] print your vector to see the diff" 
			<< std::endl;
			return;
		}
}

/*
    Put in a main for testing all vector erase unit test
*/
void    testErase(){
	std::cout << "------------------" << std::endl;
	std::cout << "      ERASE       " << std::endl;
	std::cout << "------------------" << std::endl;

	ft::vector<int> my_vect; //my vector
	std::vector<int> vect; //std vector

	for(size_t i = 0;i < 10;i++){
		my_vect.insert(my_vect.begin() +i,i);
		vect.insert(vect.begin() +i,i);
	}

	// std::cout << "TEST 1" << std::endl;
	// my_vect.erase(my_vect.begin());
	// vect.erase(vect.begin());
	// compErase(my_vect, vect);

	// std::cout << "TEST 2" << std::endl;
	// my_vect.erase(my_vect.begin(), my_vect.begin()+3);
	// vect.erase(vect.begin(), vect.begin()+3);
	// compErase(my_vect, vect);
	// print(my_vect, vect);

	// std::cout << "TEST 3" << std::endl;
	// my_vect.erase(my_vect.end(), my_vect.begin());
	// vect.erase(vect.end(), vect.begin());
	// compErase(my_vect, vect);
	// print(my_vect, vect);

}