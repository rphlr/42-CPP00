# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrouille <rrouille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 13:26:15 by rrouille          #+#    #+#              #
#    Updated: 2023/12/06 16:55:09 by rrouille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                             Makefile Configuration                           #
#                                                                              #
# **************************************************************************** #

# Arguments passed to the executable
ARGS			= $(filter-out $@,${MAKECMDGOALS})

# Terminal color settings for output messages
GRAY            = \033[0;90m
RED             = \033[0;91m
GREEN           = \033[0;92m
YELLOW          = \033[0;93m
BLUE            = \033[0;94m
MAGENTA         = \033[0;95m
CYAN            = \033[0;96m
WHITE           = \033[0;97m
ENDCOLOR        = \033[0m

# Background colors for terminal
BG_G            = \033[42m
BG_R            = \033[41m
BG_Y            = \033[43m
BG_B            = \033[44m
BG_M            = \033[45m
BG_C            = \033[46m
BG_W            = \033[47m

# Text formatting options for output messages
BOLD            = \033[1m
UNDERLINE       = \033[4m
ITALIC          = \033[3m
INVERTED        = \033[7m

# Command to clear the screen
CLEAR           = \033c

# Source and object files
MAKE			= make

# **************************************************************************** #
#                           Compilation Rules                                  #
# **************************************************************************** #

# Rule to compile the entire program
all:
			@${MAKE} -C ex00
			@${MAKE} -C ex01
			@${MAKE} -C ex02

# Rebuild the entire project
re:		fclean .WAIT all

################################################################################
#                                 Github                                       #
################################################################################

# Rule to push changes to Git
push:
			@git add .
			@if [ -z "${ARGS}" ]; then \
				echo "${RED}❌ Please provide a commit message! ✨${ENDCOLOR}"; \
				exit 1; \
			fi
			@git commit -m "${ARGS}"
			@git push

# Rule to pull changes from Git
pull:
			@git pull

################################################################################
#                       Cleaning and Maintenance                               #
################################################################################

# Clean object files and executable
clean:
			@${MAKE} clean -C ex00
			@${MAKE} clean -C ex01
			@${MAKE} clean -C ex02

# Clean everything including the executable
fclean: clean
			@${MAKE} fclean -C ex00
			@${MAKE} fclean -C ex01
			@${MAKE} fclean -C ex02

################################################################################
#                             Utility Rules                                    #
################################################################################

# Rule to clear the screen
clear:
			@echo "${CLEAR}\c"

.PHONY: all clean fclean re test push pull leaks l lldb git clear