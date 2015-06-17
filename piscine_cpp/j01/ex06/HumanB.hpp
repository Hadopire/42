/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:36:23 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:47:47 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class	HumanB {

	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanB(std::string name);
		void	attack() const;
		void	setWeapon(Weapon &weapon);
};

#endif
