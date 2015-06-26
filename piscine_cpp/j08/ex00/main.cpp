#include "easyfind.hpp"
#include <vector>
#include <algorithm>

int main( void ) {

	std::vector<int> container;

	container.push_back(-10);
	container.push_back(10);
	container.push_back(-45);
	container.push_back(2356);
	container.push_back(42);


	try {
		
		std::cout << "searching element 42" << std::endl;
		easyfind(container, 42);
		std::cout << "searching element 24" << std::endl;
		easyfind(container, 24);
	}
	catch( std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
