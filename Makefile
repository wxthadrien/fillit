# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 13:41:34 by hmeys             #+#    #+#              #
#    Updated: 2019/03/11 11:24:48 by hmeys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

FLAGS += -Wall -Wextra -Werror
FLAGS += -I libft/

SOURCES=main.c agrandir.c algo.c backtracking.c read.c test.c\
		tetri.c verif.c
OFILES=main.o agrandir.o algo.o backtracking.o read.o test.o\
	   tetri.o verif.o
LIBFT = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OFILE)
	gcc $(SOURCES) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OFILES)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all
