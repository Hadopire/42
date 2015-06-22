/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:34:07 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:36:08 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {

}

std::string	Weapon::getType() const {

	return (this->_type);
}

void		Weapon::setType(std::string type) {

	this->_type = type;
}
