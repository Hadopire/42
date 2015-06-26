#include "Span.hpp"
#include <stdexcept>

Span::Span( size_t n ) : _size(n) {

}

Span::Span( Span const & src ) : 
	_size(src._size), _container(src._container) {
}

Span::~Span( void ) {
}

Span &	Span::operator=( Span const & rhs ) {

	this->_size = rhs._size;
	this->_container = rhs._container;
	return *this;
}

void	Span::addNumber( int n ){

	if (this->_container.size() == this->_size)
		throw std::out_of_range("Error: container full");
	this->_container.push_back(n);
}

int		Span::shortestSpan( void ) {

	if (this->_container.size() < 2)
		throw std::exception();
	sort(this->_container.begin(), this->_container.end());
	int	span = this->_container[1] - this->_container[0];
	for (size_t i = 0; i < this->_container.size(); i++) {

		if (i < this->_container.size() - 1 && this->_container[i + 1] - this->_container[i] < span) 
			span = this->_container[i + 1] - this->_container[i];
	}
	return span;
}

int		Span::longestSpan( void ) {

	if (this->_container.size() < 2)
		throw std::exception();
	sort(this->_container.begin(), this->_container.end());
	int	span = *--this->_container.end() - *this->_container.begin();
	return span;
}
