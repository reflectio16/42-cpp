# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 16:23:18 by meelma            #+#    #+#              #
#    Updated: 2026/04/27 18:24:32 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= forms
CC		= cpp
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Bureaucrat.cpp AForm.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Succesfully built $(NAME)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "Objects Removed"

fclean: clean
	rm -f $(NAME)
	@echo "Full Clean Done"

re: fclean all

.PHONY: all clean fclean re
