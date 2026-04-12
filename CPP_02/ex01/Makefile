# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 09:59:19 by meelma            #+#    #+#              #
#    Updated: 2026/01/28 10:04:09 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fixed

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Fixed.cpp
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

re: fclean all

.PHONY: all fclean clean re


