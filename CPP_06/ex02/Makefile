# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/18 11:28:24 by meelma            #+#    #+#              #
#    Updated: 2026/05/18 12:50:03 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= real
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Base.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Built Succesfully $(NAME)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ): Base.hpp

clean:
	rm -f $(OBJ)
	@echo "Objects Cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "All clean done!"

re: fclean all

.PHONY: all clean fclean re

	