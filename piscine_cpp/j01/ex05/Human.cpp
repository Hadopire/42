/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:43:10 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 20:17:22 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : _brain(Brain()) {

}

std::string	Human::identify() const {

	return this->_brain.identify();
}

Brain const	&Human::getBrain() const {

	Brain const &brain = this->_brain;
	return brain;
}
