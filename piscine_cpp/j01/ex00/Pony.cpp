/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 15:06:17 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 16:01:47 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

int Pony::_nbPony = 0;

Pony::Pony(std::string color, std::string name) : _color(color), _name(name) {
	
	++Pony::_nbPony;
	std::cout << "A " << color << " pony named " << name << " is born." << std::endl;
}

Pony::~Pony() {
	
	--Pony::_nbPony;
	std::cout << this->_name << " the " << this->_color << " is dead." << std::endl;
}

int Pony::getNbPony() {
	
	return (Pony::_nbPony);
}
