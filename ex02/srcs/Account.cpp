/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:55:03 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/09 11:39:44 by rrouille         ###   ########.fr       */
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

	std::cout << GRAY << "[" << WHITE << BOLD << 1900 + ltm->tm_year
		<< std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
		<< std::setfill('0') << std::setw(2) << ltm->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << ltm->tm_hour
		<< std::setfill('0') << std::setw(2) << ltm->tm_min
		<< std::setfill('0') << std::setw(2) << ltm->tm_sec << GRAY << "] ";
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	display_time();
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	std::cout << "index:" << WHITE << BOLD << _accountIndex << GRAY
		<< ";amount:" << WHITE << BOLD << initial_deposit << GRAY << ";"
		<< GREEN << "created" << ENDCOLOR << std::endl;
}

Account::~Account() {
	display_time();
	std::cout << "index:" << WHITE << BOLD << _accountIndex << GRAY
		<< ";amount:" << WHITE << BOLD << _amount << GRAY << ";" << RED
		<< "closed" << ENDCOLOR << std::endl;
}

int			Account::getNbAccounts() {return _nbAccounts;}
int			Account::getTotalAmount() {return _totalAmount;}
int			Account::getNbDeposits() {return _totalNbDeposits;}
int			Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void		Account::displayAccountsInfos() {
	display_time();
	std::cout << "accounts:" << WHITE << BOLD << getNbAccounts() << GRAY
		<< ";total:" << WHITE << BOLD << getTotalAmount() << GRAY << ";deposits:"
		<< WHITE << BOLD << getNbDeposits() << GRAY << ";withdrawals:" << WHITE
		<< BOLD << getNbWithdrawals() << ENDCOLOR << std::endl;
}

void		Account::makeDeposit(int deposit) {
	display_time();
	std::cout << "index:" << WHITE << BOLD << _accountIndex << GRAY
		<< ";p_amount:" << WHITE << BOLD << _amount << GRAY << ";deposit:"
		<< WHITE << BOLD << deposit << GRAY << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << GRAY << "amount:" << WHITE << BOLD << _amount << GRAY << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << GRAY << "nb_deposits:" << WHITE << BOLD << _nbDeposits << GRAY
		<< std::endl << ENDCOLOR;
}

bool		Account::makeWithdrawal(int withdrawal) {
	display_time();
	std::cout << "index:" << WHITE << BOLD << _accountIndex << GRAY
		<< ";p_amount:" << WHITE << BOLD << _amount << GRAY << ";withdrawal:";
	if (_amount < withdrawal) {
		std::cout << RED << "refused" << ENDCOLOR << std::endl;
		return false;
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << ENDCOLOR << std::endl;
	return true;
}

int			Account::checkAmount() const {return _amount;}

void		Account::displayStatus() const {
	display_time();
	std::cout << "index:" << WHITE << BOLD << _accountIndex << GRAY
		<< ";amount:" << WHITE << BOLD << _amount << GRAY << ";deposits:"
		<< WHITE << BOLD << _nbDeposits << GRAY << ";withdrawals:" << WHITE
		<< BOLD << _nbWithdrawals << ENDCOLOR  << std::endl;
}
