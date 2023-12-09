/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:57:19 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/09 14:37:07 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.hpp"

bool getInput(const std::string& prompt, std::string& input) {
	while (true) {
		std::cout << GRAY << prompt << "\n> " << ENDCOLOR;
		std::getline(std::cin, input);
		if (std::cin.eof()) return false;
		if (!input.empty()) return true;
	}
}

void addContact(Phonebook *phonebook, int contactIndex)
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	if (!getInput("Please enter the contact's first name:", firstName)) return;
	if (!getInput("Please enter the contact's last name:", lastName)) return;
	if (!getInput("Please enter the contact's nickname:", nickname)) return;
	if (!getInput("Please enter the contact's phone number:", phoneNumber)) return;
	if (!getInput("Please enter the contact's darkest secret:", darkestSecret)) return;

	phonebook->createNewContact(contactIndex % 8, firstName, lastName, nickname,
		phoneNumber, darkestSecret);
}
void	searchContacts(Phonebook *phonebook, int contactCount)
{
	if (contactCount == 0) {
		std::cout << RED << "No contact to display." << ENDCOLOR << std::endl
			<< GRAY << "> ";
		return;
	}
	std::cout << std::endl << std::setw(10) << BOLD << "Index" << "|" << std::setw(10)
		<< "First Name"	<< "|" << std::setw(10) << "Last Name" << "|" << std::setw(10)
		<< "Nickname" << "|" << std::endl << ENDCOLOR;
	for (int index = 0; index < std::min(contactCount, 8); index++) {
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
			if (contactIndex >= 8) contactIndex = 8;
		} else if (userCommand == "SEARCH") {
			searchContacts(&phonebook, contactIndex);
		} else if (!std::cin.eof()) {
			std::cout << RED << "Only ADD, SEARCH and EXIT commands are accepted - " << BOLD
						<< "CASE SENSITIVE." << std::endl << ENDCOLOR;
		}
	}
	return 0;
}
