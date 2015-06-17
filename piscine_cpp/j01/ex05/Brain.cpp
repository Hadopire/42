/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:27:08 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:07:14 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

std::string	Brain::identify() const{
	
	std::stringstream ss;
	ss << this;
	return (ss.str());
}
