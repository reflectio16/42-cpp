# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 15:07:18 by meelma            #+#    #+#              #
#    Updated: 2026/02/11 16:09:42 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= repetitive

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Succsessfully built $(NAME)"
		
clean:
		rm -f $(OBJ)
		@echo "Objects cleaned"

fclean: clean
		rm -f $(NAME)
		@echo "All clean done"
		
re: fclean all

.PHONY: all fclean clean re
