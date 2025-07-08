/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:14:31 by Oukhiar           #+#    #+#             */
/*   Updated: 2025/07/08 17:26:43 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
    << ";amount:" << checkAmount()
    << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
    << ";amount:" << this->checkAmount()
    << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = std::time(NULL);
	struct tm timenow = *std::localtime(&now);

	std::cout << "[" << timenow.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << timenow.tm_hour <<
	std::setfill('0') << std::setw(2) << timenow.tm_min <<
	std::setfill('0') << std::setw(2) << timenow.tm_sec <<
	"] ";
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl; 
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
    << ";p_amount:" << this->_amount 
    << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout << ";amount:" << checkAmount()
    << ";nb_deposits:" << this->_nbDeposits
    << std::endl;
    _totalNbDeposits++;
    _totalAmount += deposit;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();

    if (withdrawal > this->checkAmount())
    {
        std::cout << "index:" << this->_accountIndex 
        << ";p_amount:" << checkAmount()
        << ";withdrawal:refused"
        << std::endl;
        return (false);
    }
    std::cout << "index:" << this->_accountIndex 
    << ";p_amount:" << checkAmount()
    << ";withdrawal:" << withdrawal;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    std::cout << ";amount:" << checkAmount()
    << ";nb_withdrawals:" << this->_nbWithdrawals
    << std::endl;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return (true);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();

    std::cout << "index:" << this->_accountIndex 
    << ";amount:" << checkAmount()
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals
    << std::endl;
}