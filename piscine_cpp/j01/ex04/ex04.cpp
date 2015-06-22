/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 19:09:41 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 19:12:40 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*str_ptr = &str;
	std::string		&str_ref = str;	
	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;
	return (0);
}
