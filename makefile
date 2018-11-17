# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/11/17 11:31:06 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = vrenaudi.filler

SRCS = main.c \
	   ft_get_piece.c \
	   ft_get_map.c \
	   ft_put_piece.c \
	   ft_estimate_value.c \
	   ft_get_oppocpt.c \
	   ft_free_and_return.c \
	   ft_get_extreme.c

OBJ = $(SRCS:.c=.o)

HEAD = -I ./

RM = rm -f

%.o: %.c
	$(CC) $(HEAD) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJ)
	Make -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) ./libft/libftprintf.a

clean:
	Make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: clean, re, fclean
