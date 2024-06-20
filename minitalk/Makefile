# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:31:27 by asomanah          #+#    #+#              #
#    Updated: 2024/06/18 12:15:23 by asomanah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT = Libft/libft.a
SOURCES = src/client.c src/server.c
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	cc $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJECTS)
	cc $(FLAGS) -o server src/server.o -L./Libft -lft
	cc $(FLAGS) -o client src/client.o -L./Libft -lft

$(LIBFT):
	$(MAKE) -C Libft -f Makefile all
	$(MAKE) -C Libft -f Makefile clean

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f Libft/libft.a
	rm -f server
	rm -f client

re:	fclean all

bonus: all

.PHONY: all clean fclean re bonus