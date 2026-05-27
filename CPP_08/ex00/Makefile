# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 10:52:14 by meelma            #+#    #+#              #
#    Updated: 2026/05/27 12:02:07 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = easyfind
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp
OBJS    = $(SRCS:.cpp=.o)
HEADERS = easyfind.hpp easyfind.tpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "Succesfully built $(NAME)"

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Objects cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "All clean DONE!"

re: fclean all

.PHONY: all clean fclean re
