# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 15:24:31 by meelma            #+#    #+#              #
#    Updated: 2026/04/23 16:26:47 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= form
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Bureaucrat.cpp Form.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Succesfully built $(NAME)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): Bureaucrat.hpp Form.hpp

clean:
	rm -f $(OBJ)
	@echo "Objects cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "Full clean done"
	
re: fclean all

.PHONY: all clean fclean re
