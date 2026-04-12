# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 13:54:33 by meelma            #+#    #+#              #
#    Updated: 2026/01/26 10:02:35 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= harl

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Harl.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "✅ Successfully built $(NAME)"
		
clean:
		rm -f $(OBJ)
		@echo "All objects cleaned"

fclean: clean
		rm -f $(NAME)
		@echo "All clean done"
		
re: fclean all

.PHONY: all clean fclean re
