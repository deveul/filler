# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/11/09 17:05:17 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

CFLAGS += $(shell sdl2-config --cflags)

LFLAG = $(shell sdl2-config --libs) -l SDL2_ttf

NAME = visu.filler

SRCS = main.c \
	   first_parsing.c \
	   ft_init_env.c \
	   ft_original_draw.c \
	   ft_handle_event.c \
	   ft_get_current_piece.c \
	   useful.c \
	   ft_next_move.c \
	   ft_draw_piece.c \
	   ft_draw_winner.c \
	   ft_free_and_quit.c

OBJ = $(SRCS:.c=.o)

HEAD = -I ./

RM = rm -f

%.o: %.c
	$(CC) $(HEAD) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJ)
	Make -C ../libft
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAG) ../libft/libftprintf.a

clean:
	Make clean -C ../libft
	$(RM) $(OBJ)

fclean: clean
	Make fclean -C ../libft
	$(RM) $(NAME)

re: fclean all
