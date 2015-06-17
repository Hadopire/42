/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 16:54:31 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 17:49:21 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <math.h>

int const	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _value(src.getRawBits()) {

	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed( int const & val ) : _value(val << Fixed::_fractional_bits) {
	
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const & val ) : _value(roundf(val * pow(2, Fixed::_fractional_bits))) {
	
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {

	this->_value = raw;
}

int		Fixed::toInt( void ) const {

	return (this->_value >> Fixed::_fractional_bits);
}

float	Fixed::toFloat( void ) const {

	return ((float)(this->_value) / pow(2, Fixed::_fractional_bits));
}

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs) {

	out << rhs.toFloat();
	return (out);
}
