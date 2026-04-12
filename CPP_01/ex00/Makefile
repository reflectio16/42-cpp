# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 12:57:08 by meelma            #+#    #+#              #
#    Updated: 2026/01/26 10:01:20 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= zombie
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "✅ Succesfully built $(NAME)"

clean:
		rm -f $(OBJ)
		@echo "Objects cleaned"
	
fclean: clean
		rm -f $(NAME)
		@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re
