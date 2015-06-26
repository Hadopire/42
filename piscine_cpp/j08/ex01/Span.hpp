#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>

class Span {

	public:
		Span( size_t n);
		Span( Span const & );
		~Span( void );

		Span &	operator=( Span const & );

		void	addNumber( int n );
		int		shortestSpan( void );
		int		longestSpan( void );
		
	private:
		Span( void );
		size_t				_size;
		std::vector<int>	_container;
};

#endif
