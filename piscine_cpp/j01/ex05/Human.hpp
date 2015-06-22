/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:40:46 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:12:18 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>
#include "Brain.hpp"

class Human {

	private:
		const Brain	_brain;
	
	public:
		std::string	identify() const;
		Brain const	&getBrain() const;
		Human();
};

#endif
