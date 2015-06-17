/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 17:57:54 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/15 20:00:42 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact() {
	return;
}

Contact::~Contact() {
	return;
}

void		Contact::setFirstname(std::string str) {
	this->_firstname = str;
}

std::string	Contact::getFirstname( void ) const {
	return (this->_firstname);
}

void		Contact::setLastname(std::string str) {
	this->_lastname = str;
}

std::string	Contact::getLastname( void ) const {
	return (this->_lastname);
}

void		Contact::setNickname(std::string str) {
	this->_nickname = str;
}

std::string Contact::getNickname( void ) const {
	return (this->_nickname);
}

void		Contact::setLogin(std::string str) {
	this->_login = str;
}

std::string Contact::getLogin( void ) const {
	return (this->_login);
}

void		Contact::setAdress(std::string str) {
	this->_adress = str;
}

std::string	Contact::getAdress( void ) const {
	return (this->_adress);
}

void		Contact::setEmail(std::string str) {
	this->_email = str;
}

std::string	Contact::getEmail( void ) const {
	return (this->_email);
}

void		Contact::setPhone(std::string str) {
	
	if (str.size() != 10) {
		this->_phone = "null";
		return;
	}
	for (int i = 0; i < (int)str.size(); i++) {
		if (!isdigit(str[i])) {
			this->_phone = "null";
			return;
		}
	}
	this->_phone = str;
}

std::string	Contact::getPhone( void ) const {
	return (this->_phone);
}

void		Contact::setBirthday(std::string str) {
	if (str.size() != 10) {
		this->_birthday = "null";
		return;
	}
	if (!isdigit(str[0]) || !isdigit(str[1]) || str[2] != '/' || !isdigit(str[3]) || !isdigit(str[4])
		|| str[5] != '/' || !isdigit(str[6]) || !isdigit(str[7]) || !isdigit(str[8]) || !isdigit(str[9])) {
		this->_birthday = "null";
		return;
	}
	this->_birthday = str;
}

std::string	Contact::getBirthday( void ) const {
	return (this->_birthday);
}

void		Contact::setFavoritemeal(std::string str) {
	this->_favoritemeal = str;
}

std::string	Contact::getFavoritemeal( void ) const {
	return (this->_favoritemeal);
}

void		Contact::setUnderwearcolor(std::string str) {
	this->_underwearcolor = str;
}

std::string	Contact::getUnderwearcolor( void ) const {
	return (this->_underwearcolor);
}

void		Contact::setSecret(std::string str) {
	this->_secret = str;
}

std::string Contact::getSecret( void ) const {
	return (this->_secret);
}
