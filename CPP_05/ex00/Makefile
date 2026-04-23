# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 12:31:08 by meelma            #+#    #+#              #
#    Updated: 2026/04/23 16:27:08 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bur
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Bureaucrat.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "✅ Succesfully built $(NAME)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): Bureaucrat.hpp

clean:
		rm -f $(OBJ)
		@echo "Objects cleaned"
	
fclean: clean
		rm -f $(NAME)
		@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re