/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:36:23 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:50:33 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class	HumanA {

	private:
		std::string _name;
		Weapon		&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack() const;
};

#endif
