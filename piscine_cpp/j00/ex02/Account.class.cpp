/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 21:21:31 by ncharret          #+#    #+#             */
/*   Updated: 2015/06/16 13:32:51 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	++Account::_nbAccounts;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << " index:"<< this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << " index:"<< this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int		Account::getNbAccounts( void ) {
	
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void ) {
	
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void ) {
	
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void ) {
	
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:"
		<< Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	
	this->_amount += deposit;
	++Account::_totalNbDeposits;
	Account::_totalAmount += deposit;
	++this->_nbDeposits;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" <<
		this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	
	if (withdrawal > this->_amount) {
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;
	++this->_nbWithdrawals;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" <<
	this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	
	Account::_displayTimestamp();
	std::cout << " index:"<< this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << 
		this->_nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp( void ) {

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1;
	int year = aTime->tm_year + 1900;
	std::cout << "[" << year << month << day << "_" << aTime->tm_hour << aTime->tm_min << aTime->tm_sec << "]";
}
