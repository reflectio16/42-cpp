/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:27:28 by meelma            #+#    #+#             */
/*   Updated: 2026/01/19 12:52:19 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

void	Account::_displayTimestamp( void ) {
	char buffer[20];
	std::time_t now = std::time(NULL);
	std::strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", std::localtime(&now));
	std::cout << buffer;
}

void	Account::makeDeposit( int deposit ) {
	int p_amount = _amount;
	
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << p_amount;
    std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex;
		std:: cout << ";p_amount:" << _amount;
        std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	int p_amount = _amount;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << p_amount;
    std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int	Account::checkAmount( void ) const {
	return _amount;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	 std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl; 
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}
