/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 14:44:37 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/15 15:05:48 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int ac, char **av) {

	if (ac > 1)
	{
		int a = 1;
		while (a < ac)
		{
			int i = 0;
			while (av[a][i])
			{
				av[a][i] = toupper(av[a][i]);
				++i;
			}
			std::cout << av[a];
			++a;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
