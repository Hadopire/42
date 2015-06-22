/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:58:28 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 17:19:10 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <string>

class ZombieEvent {

	private:
		std::string _type;
		static const std::string names[];

	public:
		void	setZombieType(std::string type);
		Zombie	*newZombie(std::string name) const;
		Zombie	*randomChump() const;
		ZombieEvent();
};

#endif
