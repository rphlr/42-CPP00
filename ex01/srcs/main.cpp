/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:57:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/06 16:40:19 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.hpp"

void	addContact(Phonebook *phonebook, int contactIndex)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << GRAY << "Please enter the contact's first name:\n> " << ENDCOLOR;
	std::getline(std::cin, firstName);
	if (std::cin.eof()) return;

	std::cout << GRAY << "Please enter the contact's last name:\n> " << ENDCOLOR;
	std::getline(std::cin, lastName);
	if (std::cin.eof()) return;

	std::cout << GRAY << "Please enter the contact's nickname:\n> " << ENDCOLOR;
	std::getline(std::cin, nickname);
	if (std::cin.eof()) return;

	std::cout << GRAY << "Please enter the contact's phone number:\n> " << ENDCOLOR;
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof()) return;

	std::cout << GRAY << "Please enter the contact's darkest secret:\n> " << ENDCOLOR;
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof()) return;

	phonebook->createNewContact(contactIndex % 8, firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void	searchContacts(Phonebook *phonebook, int contactCount)
{
	std::cout << std::endl;
	std::cout << std::setw(10) << BOLD << "Index" << "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name" << "|" << std::setw(10)
				<< "Nickname" << "|" << std::endl << ENDCOLOR;
	for (int index = -1; index < std::min(contactCount, 8); ++index) {
		std::string firstName = phonebook->getFirstName(index);
		std::string lastName = phonebook->getLastName(index);
		std::string nickname = phonebook->getNickname(index);
		if (firstName.length() > 9) firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 9) lastName = lastName.substr(0, 9) + ".";
		if (nickname.length() > 9) nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << index + 1 << BOLD << "|" << ENDCOLOR
					<< std::setw(10) << firstName << BOLD << "|" << ENDCOLOR
					<< std::setw(10) << lastName << BOLD << "|" << ENDCOLOR
					<< std::setw(10) << nickname << BOLD << "|" << ENDCOLOR << std::endl;
	}
    
	std::cout << std::endl << GRAY << "Please enter the contact's index to see more details:"
				<< std::endl << "> " << ENDCOLOR;
	std::string userIndex;
	std::getline(std::cin, userIndex);
	if (std::cin.eof()) return;

	int	index = atoi(userIndex.c_str()) - 1;
	if (index >= 0 && index < contactCount) phonebook->getContact(index).print();
	else std::cout << RED << "Wrong index" << ENDCOLOR << std::endl << GRAY << "> ";
}

int		main()
{
	std::string	userCommand;
	Phonebook	phonebook;
	int			contactIndex = 0;

	while (!std::cin.eof())
	{
		std::cout << GRAY << "Please enter a command (SEARCH / ADD / EXIT)" << std::endl
					<< "> " << ENDCOLOR;
		std::getline(std::cin, userCommand);

		if (userCommand == "EXIT") break;
		else if (userCommand == "ADD") {
		addContact(&phonebook, contactIndex++);
		} else if (userCommand == "SEARCH") {
			searchContacts(&phonebook, contactIndex);
		} else if (!std::cin.eof()) {
			std::cout << RED << "Only ADD, SEARCH and EXIT commands are accepted - " << BOLD
						<< "CASE SENSITIVE." << std::endl << ENDCOLOR;
		}
	}
	return 0;
}
