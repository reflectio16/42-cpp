# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 11:49:08 by meelma            #+#    #+#              #
#    Updated: 2026/01/26 10:02:21 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= sed 
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= main.cpp sed.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "✅ Successfully built $(NAME)"

clean:
		rm -f $(OBJ)
		@echo "All Objects cleaned"
		
fclean: clean
		rm -f $(NAME)
		@echo "All clean done"

re: fclean all

.PHONY: all fclean clean re

