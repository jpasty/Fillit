# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpasty <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 13:13:44 by jpasty            #+#    #+#              #
#    Updated: 2019/08/20 16:10:11 by jpasty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

SRCS := main.c make_map.c make_tetrimino_list.c solver.c valid_or_not.c error.c
OBJ := $(SRCS:.c=.o)
HEADERS := fillit.h
FLAGS := -Wall -Wextra -Werror -I libft/
LIB := -I libft/ -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o $@ $(OBJ) $(LIB)

$(OBJ):%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft/ fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all
