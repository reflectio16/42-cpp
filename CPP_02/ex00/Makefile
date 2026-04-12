# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 16:40:51 by meelma            #+#    #+#              #
#    Updated: 2026/01/28 09:56:35 by meelma           ###   ########.fr        #
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
		@echo "All Objects Cleaned"

fclean: clean
		rm -f $(NAME)
		@echo "All Clean Done"

re: fclean all

.PHONY: all fclean clean re
