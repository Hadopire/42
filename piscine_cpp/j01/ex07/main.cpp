/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 20:58:05 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 14:52:14 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{

	if (ac != 4) {
		
		std::cout << "wrong number of arguments" << std::endl;
		return (-1);
	}

	std::ifstream ifs(av[1]);
	if (ifs.fail()) {

		std::cout << "Error opening the file" << std::endl;
		return (-1);
	}
	std::string			fstring;
	std::stringstream	buf;
	buf << ifs.rdbuf();
	ifs.close();
	fstring = buf.str();

	std::size_t pos = 0;
	while ( (pos = fstring.find(std::string(av[2]), pos)) != std::string::npos ) {

		fstring.replace(pos, std::string(av[2]).size(), av[3]);
		pos += std::string(av[3]).size();
	}
	std::ofstream ofs(std::string(av[1]) + ".replace", std::ios::out);
	if (ofs.fail()) {
	
		std::cout << "Error opening the file" << std::endl;
	}
	ofs << fstring;
	ofs.close();
	return (0);
}
