# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 12:58:36 by meelma            #+#    #+#              #
#    Updated: 2026/01/19 11:55:20 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= account
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= Account.cpp tests.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "✅ Successfully built $(NAME)"

clean:
		rm -f $(OBJ)
		@echo "Objects Cleaned"

fclean: clean
		rm -f $(NAME)
		@echo "Full clean done"
		
re: fclean all

.PHONY: all clean fclean re
