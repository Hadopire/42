/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:35:53 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 18:33:02 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

	private:
		static const std::string	names[];
		Zombie						*_zombies;
		int							_nbZombie;
	public:
		ZombieHorde(int n);
		~ZombieHorde();
		void	announce() const;
};

#endif
