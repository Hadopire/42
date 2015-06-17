/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 16:44:18 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 17:01:21 by ncharret         ###   ########.fr       */
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
		~Fixed( void );

		Fixed &		operator=( Fixed const & rhs );

		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

#endif
