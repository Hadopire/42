/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 18:34:01 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 18:38:02 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	ZombieHorde *horde = new ZombieHorde(15);
	horde->announce();
	delete horde;
	return (0);
}
