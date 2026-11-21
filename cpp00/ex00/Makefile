# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcosta <hcosta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 20:52:49 by hcosta            #+#    #+#              #
#    Updated: 2026/11/13 20:19:07 by hcosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
CXX	= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRC 	= megaphone.cpp
OBJ	= megaphone.o

all: $(NAME)


$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
