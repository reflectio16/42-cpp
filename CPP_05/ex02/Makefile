# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 16:23:18 by meelma            #+#    #+#              #
#    Updated: 2026/04/28 17:43:25 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= forms
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp Bureaucrat.cpp AForm.cpp \
			ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp
OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "✅ Succesfully built $(NAME)"
	
$(OBJ):	AForm.hpp Bureaucrat.hpp ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp PresidentialPardonForm.hpp

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	@echo "Objects Removed"

fclean:	clean
	rm -f $(NAME)
	rm -f *_shrubbery
	@echo "Full Clean Done"

re:	clean all

.PHONY:	all clean fclean re
