/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:32:39 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:36:06 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {

	private:
		std::string	_type;
	
	public:
		Weapon(std::string type);
		std::string	getType() const;
		void		setType(std::string type);
};

#endif
