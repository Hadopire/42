/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 19:50:33 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 20:07:00 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <string>

class Logger {

	typedef	void	(Logger::*log_ptr)(std::string const &) const;
	private:
		std::string const _filename;
		
		void		logToConsole( std::string const & msg ) const;
		void		logToFile( std::string const & msg ) const;
		std::string	makeLogEntry( std::string const & msg ) const;

		log_ptr		logptr[2];
		std::string	logname[2];
		
	public:
		Logger( std::string const filename );
		void	log( std::string const & dest, std::string const & message ) const;
};

#endif
