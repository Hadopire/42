/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 16:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 19:35:29 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <string>
#include <iostream>

class Fixed {

	private:
		int					_value;
		static int const	_fractional_bits;

	public:
		Fixed( void );
		Fixed( Fixed const & src );
		Fixed( int const & val );
		Fixed( float const & val );
		~Fixed( void );

		Fixed &		operator=( Fixed const & rhs );
		Fixed		operator+( Fixed const & rhs );
		Fixed		operator-( Fixed const & rhs );
		Fixed		operator*( Fixed const & rhs );
		Fixed		operator/( Fixed const & rhs );
		bool		operator>( Fixed const & rhs ) const;
		bool		operator<( Fixed const & rhs ) const;
		bool		operator>=( Fixed const & rhs ) const;
		bool		operator<=( Fixed const & rhs ) const;
		bool		operator==( Fixed const & rhs ) const;
		bool		operator!=( Fixed const & rhs ) const;
		Fixed &		operator++( void );
		Fixed		operator++( int );
		Fixed &		operator--( void );
		Fixed		operator--( int );

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;

		static Fixed const &	max( Fixed const & a, Fixed const & b );
		static Fixed const &	min( Fixed const & a, Fixed const & b );
		static Fixed &			max( Fixed & a, Fixed & b );
		static Fixed &			min( Fixed & a, Fixed & b );
};

std::ostream &	operator<<( std::ostream & out, Fixed const & rhs );

#endif
