/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:55:03 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/09 14:54:10 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Terminal color settings for output messages
const std::string GRAY		= "\033[0;90m";
const std::string RED		= "\033[0;91m";
const std::string GREEN		= "\033[0;92m";
const std::string YELLOW	= "\033[0;93m";
const std::string BLUE		= "\033[0;94m";
const std::string MAGENTA	= "\033[0;95m";
const std::string CYAN		= "\033[0;96m";
const std::string WHITE		= "\033[0;97m";
const std::string ENDCOLOR	= "\033[0m";

// Background colors for terminal
const std::string BG_G		= "\033[42m";
const std::string BG_R		= "\033[41m";
const std::string BG_Y		= "\033[43m";
const std::string BG_B		= "\033[44m";
const std::string BG_M		= "\033[45m";
const std::string BG_C		= "\033[46m";
const std::string BG_W		= "\033[47m";

// Text formatting options for output messages
const std::string BOLD		= "\033[1m";
const std::string UNDERLINE	= "\033[4m";
const std::string ITALIC	= "\033[3m";
const std::string INVERTED	= "\033[7m";

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
