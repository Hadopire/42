/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:15:24 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 17:29:35 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void	pitiZomb() {

	Zombie piti("petit", "Pony");
	piti.announce();
	piti.announce();
}

int main()
{
	ZombieEvent factory;
	factory.setZombieType("rebelz");
	for (int i = 0; i < 3; i++) {

		Zombie *zomb = factory.randomChump();
		delete zomb;
	}
	factory.setZombieType("pasrebelz");
	for (int i = 0; i < 3; i++) {

		Zombie *zomb = factory.randomChump();
		delete zomb;
	}
	pitiZomb();
	return (0);
}
