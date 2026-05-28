# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/28 14:36:25 by meelma            #+#    #+#              #
#    Updated: 2026/05/28 16:24:03 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = mutant
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS    = main.cpp 
OBJS    = $(SRCS:.cpp=.o)
HEADERS	= MutantStack.hpp

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