# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/15 16:38:48 by meelma            #+#    #+#              #
#    Updated: 2026/05/15 18:02:51 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= serial
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Serializer.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Built Succesfully $(NAME)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ): Serializer.hpp Data.hpp

clean:
	rm -f $(OBJ)
	@echo "Objects Cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "Full Clean Done!"

re: fclean all

.PHONY: all clean fclean re
