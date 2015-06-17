/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 15:06:37 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 15:07:32 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main() {

	Human human;
	human.action("meleeAttack", "tamere");
	human.action("rangedAttack", "tonpere");
	human.action("intimidatingShout", "tasoeur");
	return (0);
}
