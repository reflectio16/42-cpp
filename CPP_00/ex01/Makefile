# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 13:18:40 by meelma            #+#    #+#              #
#    Updated: 2026/01/26 09:55:05 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98
SRC		= Contact.cpp PhoneBook.cpp main.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAG) $(OBJ) -o $(NAME)
		@echo "✅ Successfully built $(NAME)"

clean:
		rm -f $(OBJ)
		@echo "Objects cleaned"

fclean: clean
		rm -f $(NAME)
		@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re
