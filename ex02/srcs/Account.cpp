/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:55:03 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/08 19:49:12 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int					Account::_nbAccounts			= 0;
int					Account::_totalAmount			= 0;
int					Account::_totalNbDeposits		= 0;
int					Account::_totalNbWithdrawals	= 0;

static void	display_time() {
	const time_t	now								= time(0);
	tm				*ltm							= localtime(&now);

	std::cout << "[" << GREEN << 1900 + ltm->tm_year << std::setfill('0')
		<< std::setw(2) << 1 + ltm->tm_mon << std::setfill('0') << std::setw(2)
		<< ltm->tm_mday << "_" << std::setfill('0') << std::setw(2)
		<< ltm->tm_hour	<< std::setfill('0') << std::setw(2) << ltm->tm_min
		<< std::setfill('0') << std::setw(2) << ltm->tm_sec << ENDCOLOR
		<< "] ";
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	display_time();
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << GRAY << "index:" << YELLOW << _accountIndex << GRAY
		<< ";amount:" << YELLOW << initial_deposit << GRAY << ";created"
		<< ENDCOLOR << std::endl;
}

Account::~Account() {
	display_time();
	std::cout << BLUE << "index:" << YELLOW << _accountIndex << BLUE
		<< ";amount:" << YELLOW << _amount << BLUE << ";closed" << ENDCOLOR
		<< std::endl;
}

int			Account::getNbAccounts() {return _nbAccounts;}
int			Account::getTotalAmount() {return _totalAmount;}
int			Account::getNbDeposits() {return _totalNbDeposits;}
int			Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void		Account::displayAccountsInfos() {
	display_time();
	std::cout << CYAN << "accounts:" << YELLOW << getNbAccounts() << CYAN
		<< ";total:" << YELLOW << getTotalAmount() << CYAN << ";deposits:"
		<< YELLOW << getNbDeposits() << CYAN << ";withdrawals:" << YELLOW
		<< getNbWithdrawals() << ENDCOLOR << std::endl;
}

void		Account::makeDeposit(int deposit) {
	display_time();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal) {
	display_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int			Account::checkAmount() const {return _amount;}

void		Account::displayStatus() const {
	display_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
