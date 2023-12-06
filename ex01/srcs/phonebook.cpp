/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:57:22 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/06 16:38:16 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.hpp"

Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {
}

Contact	Phonebook::getContact(int index) {
	return phonebook[index];
}

std::string	Phonebook::getFirstName(int index) {
	return phonebook[index].getFirstName();
}

std::string	Phonebook::getLastName(int index) {
	return phonebook[index].getLastName();
}

std::string	Phonebook::getNickname(int index) {
	return phonebook[index].getNickname();
}

std::string	Phonebook::getPhoneNumber(int index) {
	return phonebook[index].getPhoneNumber();
}

std::string	Phonebook::getDarkestSecret(int index) {
	return phonebook[index].getDarkestSecret();
}

void	Phonebook::createNewContact(int index, std::string firstName, std::string lastName, 
									std::string nickname, std::string phoneNumber, std::string darkestSecret) {
	phonebook[index].setValues(firstName, lastName, nickname, phoneNumber, darkestSecret);
}
