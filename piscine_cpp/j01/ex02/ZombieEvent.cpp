/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:58:16 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 17:31:45 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <stdlib.h>
#include <time.h>

const std::string ZombieEvent::names[10] = {
	"Gilbert",
	"Michel",
	"Jean-Louis",
	"Framon",
	"Aduban",
	"Ncharret",
	"Abombard",
	"Jemery",
	"Aaure",
	"Gougou"
}; 

ZombieEvent::ZombieEvent() {
	
	srand(time(NULL));
	this->_type = "null";
}

void	ZombieEvent::setZombieType(std::string type) {

	this->_type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name) const {

	return (new Zombie(this->_type, name));
}

Zombie	*ZombieEvent::randomChump() const{

	int i = rand() % 10;
	Zombie *zomblar = this->newZombie(ZombieEvent::names[i]);
	zomblar->announce();
	return (zomblar);
}
