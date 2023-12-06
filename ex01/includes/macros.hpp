/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:57:21 by rrouille          #+#    #+#             */
/*   Updated: 2023/12/06 16:33:06 by rrouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_HPP
# define MACROS_HPP

# include <iostream>
# include <iomanip>
# include "contact.hpp"
# include "phonebook.hpp"

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

#endif