# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 09:42:40 by meelma            #+#    #+#              #
#    Updated: 2026/01/26 09:42:41 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= megaphone.cpp
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
	@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re
