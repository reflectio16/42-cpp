# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 14:05:04 by meelma            #+#    #+#              #
#    Updated: 2026/02/12 16:54:24 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= weird

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wno-shadow
SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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
 