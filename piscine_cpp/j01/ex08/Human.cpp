/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 14:56:00 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 15:21:05 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() {

	this->ac_ptr[0] = &Human::meleeAttack;
	this->ac_ptr[1] = &Human::rangedAttack;
	this->ac_ptr[2] = &Human::intimidatingShout;
	this->ac_name[0] = "meleeAttack";
	this->ac_name[1] = "rangedAttack";
	this->ac_name[2] = "intimidatingShout";
}

void	Human::meleeAttack(std::string const & target) {

	std::cout << "Melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {

	std::cout << "Ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {

	std::cout << "Intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {
	
	for (int i = 0; i < 3; i++) {

		if (this->ac_name[i].compare(action_name) == 0) {
			action_ptr ac = this->ac_ptr[i];
			(this->*ac)(target);
			return ;
		}
	}
	std::cout << "No action found" << std::endl;
}
