/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 14:55:16 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 15:09:37 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include <iostream>

class Human
{
	typedef	void (Human::*action_ptr)(std::string const &);
	private:
		void meleeAttack(std::string const & target);
		void rangedAttack(std::string const & target);
		void intimidatingShout(std::string const & target);
		action_ptr	ac_ptr[3];
		std::string	ac_name[3];
	public:
		Human();
		void action(std::string const & action_name, std::string const & target);
};

#endif
