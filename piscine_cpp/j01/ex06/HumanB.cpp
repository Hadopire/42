/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:38:15 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:51:23 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {

}

void	HumanB::attack() const {

	std::cout << this->_name << " attack with " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {

	this->_weapon = &weapon;
}
