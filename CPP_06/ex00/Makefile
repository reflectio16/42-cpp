# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/12 14:35:56 by meelma            #+#    #+#              #
#    Updated: 2026/05/12 14:44:57 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= convert
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp ScalarConverter.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "Succesfully built $(NAME)"
		
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): ScalarConverter.hpp

clean:
	rm -f $(OBJ)
	@echo "Objects cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "Full clean done!"

re: fclean all

.PHONY: all clean fclean re
