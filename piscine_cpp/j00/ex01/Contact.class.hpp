/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 17:35:37 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/15 20:00:52 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>
#include <iostream>
#include <ctype.h>
class	Contact {

	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string _nickname;
		std::string _login;
		std::string _adress;
		std::string _email;
		std::string _phone;
		std::string	_birthday;
		std::string _favoritemeal;
		std::string _underwearcolor;
		std::string _secret;

	public:
		Contact( void );
		~Contact( void );
		void		setFirstname(std::string str);
		std::string	getFirstname( void ) const;
		void		setLastname(std::string str);
		std::string	getLastname( void ) const;
		void		setNickname(std::string str);
		std::string getNickname( void ) const;
		void		setLogin(std::string str);
		std::string getLogin( void ) const;
		void		setAdress(std::string str);
		std::string	getAdress( void ) const;
		void		setEmail(std::string str);
		std::string	getEmail( void ) const;
		void		setPhone(std::string str);
		std::string	getPhone( void ) const;
		void		setBirthday(std::string str);
		std::string	getBirthday( void ) const;
		void		setFavoritemeal(std::string str);
		std::string	getFavoritemeal( void ) const;
		void		setUnderwearcolor(std::string str);
		std::string	getUnderwearcolor( void ) const;
		void		setSecret(std::string str);
		std::string getSecret( void ) const;
};

#endif
