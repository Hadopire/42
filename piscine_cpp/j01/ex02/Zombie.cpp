/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:54:29 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 18:24:40 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name) {
	std::cout << "<" << this->_name << " (" << this->_type << ")> Rise from the deads" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "<" << this->_name << " (" << this->_type << ")> Died" << std::endl;
}

void	Zombie::announce() const {
	
	std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void	Zombie::setName(std::string name) {

	this->_name = name;
}

void	Zombie::setType(std::string type) {

	this->_type = type;
}
