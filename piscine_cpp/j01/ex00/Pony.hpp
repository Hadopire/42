/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 15:01:13 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 16:01:25 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <string>

class Pony {

	private:
		std::string	_color;
		std::string	_name;
		static int	_nbPony;

	public:
		Pony(std::string color, std::string name);
		~Pony();
		static int getNbPony();
};

#endif
