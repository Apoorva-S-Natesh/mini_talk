# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by asomanah          #+#    #+#              #
#    Updated: 2024/06/17 16:55:03 by asomanah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_isprint.c ft_putendl_fd.c ft_strjoin.c \
	ft_strrchr.c ft_bzero.c ft_itoa.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c \
	ft_strtrim.c ft_calloc.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
	ft_isalnum.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c ft_isalpha.c \
	ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c ft_isascii.c ft_memset.c \
	ft_strdup.c ft_strncmp.c ft_isdigit.c ft_putchar_fd.c ft_striteri.c \
	ft_strnstr.c ft_isint.c ft_printf.c ft_printf_helper.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
	ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstdelone_bonus.c 

OBJ = $(SRC:%.c=%.o)

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean remake
