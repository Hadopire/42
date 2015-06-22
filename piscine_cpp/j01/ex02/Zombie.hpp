/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:49:01 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 18:24:29 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

	private:
		std::string	_type;
		std::string _name;

	public:
		Zombie(std::string type, std::string name);
		~Zombie();
		void	announce() const;
		void	setName(std::string name);
		void	setType(std::string type);
};

#endif
