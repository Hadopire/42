/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 16:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 17:42:14 by ncharret         ###   ########.fr       */
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

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		float		toFloat( void ) const;
		int			toInt( void ) const;
};

std::ostream &	operator<<( std::ostream & out, Fixed const & rhs );

#endif
