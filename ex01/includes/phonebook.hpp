/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:57:24 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/06 16:32:16 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "macros.hpp"

class	Phonebook {
	public:
		Phonebook();
		~Phonebook();
		void	createNewContact(int index, std::string firstName, std::string lastName,
							std::string nickname, std::string phoneNumber,
							std::string darkestSecret);
		Contact getContact(int index);
		std::string getFirstName(int index);
		std::string getLastName(int index);
		std::string getNickname(int index);
		std::string getPhoneNumber(int index);
		std::string getDarkestSecret(int index);

	private:
		Contact phonebook[8];
};

#endif
