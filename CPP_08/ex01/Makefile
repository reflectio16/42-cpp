# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meelma <meelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/27 16:05:29 by meelma            #+#    #+#              #
#    Updated: 2026/05/27 16:06:24 by meelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = span
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS    = main.cpp Span.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "Succesfully built $(NAME)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Objects cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "All clean DONE!"

re: fclean all

.PHONY: all clean fclean re