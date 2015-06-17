/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 16:54:31 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 19:36:23 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <math.h>

int const	Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) {

}

Fixed::Fixed( Fixed const & src ) : _value(src.getRawBits()) {

}

Fixed::Fixed( int const & val ) : _value(val << Fixed::_fractional_bits) {
	
}

Fixed::Fixed( float const & val ) : _value(roundf(val * pow(2, Fixed::_fractional_bits))) {
	
}

Fixed::~Fixed( void ) {

}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( Fixed const & rhs ) {

	return ( Fixed( this->toFloat() + rhs.toFloat() ) );
}

Fixed	Fixed::operator-( Fixed const & rhs ) {

	return ( Fixed( this->toFloat() - rhs.toFloat() ) );
}

Fixed	Fixed::operator*( Fixed const & rhs ) {

	return ( Fixed( this->toFloat() * rhs.toFloat() ) );
}

Fixed	Fixed::operator/( Fixed const & rhs ) {

	return ( Fixed( this->toFloat() / rhs.toFloat() ) );
}

bool	Fixed::operator>( Fixed const & rhs ) const {

	return ( this->_value > rhs.getRawBits() );
}

bool	Fixed::operator<( Fixed const & rhs ) const {

	return ( this->_value < rhs.getRawBits() );
}

bool	Fixed::operator>=( Fixed const & rhs ) const {

	return ( this->_value >= rhs.getRawBits() );
}

bool	Fixed::operator<=( Fixed const & rhs ) const {

	return ( this->_value <= rhs.getRawBits() );
}

bool	Fixed::operator==( Fixed const & rhs ) const {

	return ( this->_value == rhs.getRawBits() );
}

bool	Fixed::operator!=( Fixed const & rhs ) const {

	return ( this->_value != rhs.getRawBits() );
}

Fixed &	Fixed::operator++( void ) {

	++this->_value;
	return ( *this );
}

Fixed	Fixed::operator++( int ) {

	Fixed copy(*this);
	++this->_value;
	return ( copy );
}

Fixed &	Fixed::operator--( void ) {

	--this->_value;
	return ( *this );
}

Fixed	Fixed::operator--( int ) {

	Fixed copy(*this);
	--this->_value;
	return ( copy );
}

int		Fixed::getRawBits( void ) const {

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

Fixed const &	Fixed::max( Fixed const & a, Fixed const & b) {
	
	return ( (a > b) ? a : b );
}

Fixed &			Fixed::max( Fixed & a, Fixed & b) {
	
	return ( (a > b) ? a : b );
}

Fixed const &	Fixed::min( Fixed const & a, Fixed const & b) {
	
	return ( (a < b) ? a : b );
}

Fixed &			Fixed::min( Fixed & a, Fixed & b) {
	
	return ( (a < b) ? a : b );
}

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs) {

	out << rhs.toFloat();
	return (out);
}
