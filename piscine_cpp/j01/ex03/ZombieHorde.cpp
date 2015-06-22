/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:45:13 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 18:46:16 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <time.h>
#include <stdlib.h>

const std::string ZombieHorde::names[10] = {
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

ZombieHorde::ZombieHorde(int n) : _nbZombie(n){

	this->_zombies = new Zombie[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int a = rand() % 10;
		_zombies[i].setType("Hordeux");
		_zombies[i].setName(ZombieHorde::names[a]);
	}
}

ZombieHorde::~ZombieHorde() {

	delete [] this->_zombies;
}

void	ZombieHorde::announce() const{

	for (int i = 0; i < this->_nbZombie; i++) {

		this->_zombies[i].announce();
	}
}
