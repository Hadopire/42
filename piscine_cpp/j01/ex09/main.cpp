/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 20:10:59 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 20:13:26 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main() {

	Logger log("test.log");
	log.log( "console", "j'ecris dans la console" );
	log.log( "file", "j'ecris dans un fichier" );
	return (0);
}
