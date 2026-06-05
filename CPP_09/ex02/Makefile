# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/05 13:57:35 by meelma            #+#    #+#              #
#    Updated: 2026/06/05 13:58:45 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = PmergeMe
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp PmergeMe.cpp
OBJS    = $(SRCS:.cpp=.o)
HEADERS = PmergeMe.hpp

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