/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/17 19:55:50 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/17 20:14:48 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <sstream>


Logger::Logger( std::string const filename ) : _filename(filename) {
	
	this->logptr[0] = &Logger::logToConsole;
	this->logptr[1] = &Logger::logToFile;
	this->logname[0] = "console";
	this->logname[1] = "file";
}

void	Logger::logToConsole( std::string const & msg ) const {

	std::cout << msg << std::endl;
}

void	Logger::logToFile( std::string const & msg ) const {

	std::ofstream ofs(this->_filename, std::ios_base::app);
	if (ofs.fail()) {

		std::cout << "Error opening the file : " << this->_filename << std::endl;
		return ;
	}
	ofs << msg << std::endl;
	ofs.close();
}

std::string	Logger::makeLogEntry( std::string const & msg ) const {

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	
	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1;
	int year = aTime->tm_year + 1900;
	std::stringstream sstream;
	sstream << "[" << year << "/" << month << "/" << day << "_" << aTime->tm_hour << ":" << aTime->tm_min << ":" << aTime->tm_sec << "] " << msg;
	return ( sstream.str() );
}

void		Logger::log( std::string const & dest, std::string const & message ) const {

	for (int i = 0; i < 2; i++) {

		if ( dest.compare( this->logname[i] ) == 0 ) {

			(this->*this->logptr[i])(makeLogEntry(message));
			return ;
		}
	}
	std::cout << "Invalid destination" << std::endl;
}
