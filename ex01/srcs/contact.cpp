/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:56:57 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/06 16:39:28 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void		Contact::print() const {
	std::cout << GREEN << "First Name: " << WHITE << _firstName << std::endl;
	std::cout << GREEN << "Last Name: " << WHITE << _lastName << std::endl;
	std::cout << GREEN << "Nickname: " << WHITE << _nickname << std::endl;
	std::cout << GREEN << "Phone Number: " << WHITE << _phoneNumber << std::endl;
	std::cout << BLUE << "Darkest Secret: " << WHITE << _darkestSecret << ENDCOLOR << std::endl;
}

void		Contact::setValues(const std::string firstName, const std::string lastName, 
						const std::string nickname, const std::string phoneNumber, 
						const std::string darkestSecret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() const {
	return _firstName;
}

std::string	Contact::getLastName() const {
	return _lastName;
}

std::string	Contact::getNickname() const {
	return _nickname;
}

std::string	Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return _darkestSecret;
}
