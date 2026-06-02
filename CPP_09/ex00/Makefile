# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/02 14:04:21 by meelma            #+#    #+#              #
#    Updated: 2026/06/02 14:06:44 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = btc
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp BitcoinExchange.cpp
OBJS    = $(SRCS:.cpp=.o)
HEADERS = BitcoinExchange.hpp

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
