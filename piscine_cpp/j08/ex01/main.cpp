#include "Span.hpp"
#include <stdlib.h>
#include <time.h>

int main() {

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	srand(time(NULL));
	Span msp(10000);
	for (int i = 0; i < 10000; i++) {
		
		msp.addNumber(rand());
	}
	std::cout << msp.shortestSpan() << std::endl;
	std::cout << msp.longestSpan() << std::endl;
	return (0);
}
