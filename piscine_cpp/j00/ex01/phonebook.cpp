/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 17:28:33 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/15 20:43:34 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include <iomanip>

void	create_contact(Contact *contacts, int *nbcontact) {	
	
	if (*nbcontact < 8)
	{
		Contact contact;
		std::string	str;
		std::cout << "Firstname : ";
		getline(std::cin, str);
		contact.setFirstname(str);
		std::cout << "Lastname : ";
		getline(std::cin, str);
		contact.setLastname(str);
		std::cout << "Nickname : ";
		getline(std::cin, str);
		contact.setNickname(str);
		std::cout << "Login : ";
		getline(std::cin, str);
		contact.setLogin(str);
		std::cout << "Postal address : ";
		getline(std::cin, str);
		contact.setAdress(str);
		std::cout << "Email address : ";
		getline(std::cin, str);
		contact.setEmail(str);

		int verify = 0;
		while (!verify) {
			std::cout << "Phone number (10 digits) : ";
			getline(std::cin, str);
			contact.setPhone(str);
			if (contact.getPhone().compare("null") == 0) {
				std::cout << "Incorrect format" << std::endl;
			}
			else
				verify = 1;
		}

		verify = 0;
		while (!verify) {
			std::cout << "Birthday date (dd/mm/yyyy) : ";
			getline(std::cin, str);
			contact.setBirthday(str);
			if (contact.getBirthday().compare("null") == 0) {
				std::cout << "Incorrect format" << std::endl;
			}
			else
				verify = 1;
		}

		std::cout << "Favorite meal : ";
		getline(std::cin, str);
		contact.setFavoritemeal(str);
		std::cout << "Underwear color : ";
		getline(std::cin, str);
		contact.setUnderwearcolor(str);
		std::cout << "Darkest secret : ";
		getline(std::cin, str);
		contact.setSecret(str);
		contacts[*nbcontact] = contact;
		++*nbcontact;
	}
	else
		std::cout << "Too many contact" << std::endl;
}

void	search_contact(Contact *contacts, int nbcontact) {
	
	std::cout << "  index   |  fname   |  lname   | nickname " << std::endl;   	
	for (int i = 0; i < nbcontact; i++) {
		std::string firstname = contacts[i].getFirstname();
		std::string lastname = contacts[i].getLastname();
		std::string nickname = contacts[i].getNickname();
		if (contacts[i].getFirstname().size() > 10) {
			std::string str = contacts[i].getFirstname().substr(0, 10);
			str[9] = '.';
			firstname = str;
		}
		if (contacts[i].getLastname().size() > 10) {
			std::string str = contacts[i].getLastname().substr(0, 10);
			str[9] = '.';
			lastname = str;
		}
		if (contacts[i].getNickname().size() > 10) {
			std::string str = contacts[i].getNickname().substr(0, 10);
			str[9] = '.';
			nickname = str;
		}
		std::cout << std::setw(10) << i << "|" << std::setw(10) << firstname << "|";
		std::cout << std::setw(10) << lastname << "|" << std::setw(10) << nickname << std::endl;
	}

	int choice, valid_choice;
	valid_choice = 0;
	while (!valid_choice && nbcontact > 0) {
		
		std::cout << "Desired entry : ";
		std::cin >> choice;
		if (!std::cin) {
			choice = -1;
		}
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		if (choice >= 0 && choice < nbcontact)
			valid_choice = 1;
		else
			std::cout << "Error, try again" << std::endl;
	}
	if (valid_choice) {
		
		std::cout << "First name : " << contacts[choice].getFirstname() << std::endl << "Last name : " << contacts[choice].getLastname() << std::endl;
		std::cout << "Nickname : " << contacts[choice].getNickname() << std::endl << "Login : " << contacts[choice].getLogin() << std::endl;
		std::cout << "Postal address : " << contacts[choice].getAdress() << std::endl << "Email address : " << contacts[choice].getEmail() << std::endl;
		std::cout << "Phone number : " << contacts[choice].getPhone() << std::endl << "Birthday : " << contacts[choice].getBirthday() << std::endl;
		std::cout << "Favorite meal : " << contacts[choice].getFavoritemeal() << std::endl << "Underwear Color : " << contacts[choice].getUnderwearcolor() << std::endl;

		std::cout << "Darkest secret : " << contacts[choice].getSecret() << std::endl;
	}
}

int main() {
	
	Contact	contacts[8];
	int		nbcontact = 0;
	while (1)
	{

		std::string command;
		std::cout << "PhoneBook v12.1 : ";
		getline(std::cin, command);
		if (command.compare("EXIT") == 0)
			break ;
		else if (command.compare("ADD") == 0)
			create_contact(contacts, &nbcontact);
		else if (command.compare("SEARCH") == 0 && nbcontact > 0)
			search_contact(contacts, nbcontact);
		
	}
	return (0);
}
