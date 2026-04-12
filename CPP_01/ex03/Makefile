# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 16:30:17 by meelma            #+#    #+#              #
#    Updated: 2026/01/26 10:02:11 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= violence
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "✅ Successfully built $(NAME)"
		
clean:
		rm -f $(OBJ)
		@echo "Objects cleaned"

fclean: clean
		rm -f $(NAME)
		@echo "All clean done"

re: fclean all

.PHONY: all clean fclean re

