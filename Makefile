NAME=fillit

FLAGS=-Wall -Wextra -Werror

SOURCES=main.c agrandir.c algo.c backtracking.c read.c test.c\
		tetri.c verif.c
OFILES=main.o agrandir.o algo.o backtracking.o read.o test.o\
	   tetri.o verif.o
LIBFT = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)

make_libft:
		cd libft && make && cd ..

libft_clean:
	cd libft && make clean

libft_fclean:
		cd libft && make fclean

obj:
			@gcc $(CFLAGS) -c $(SOURCES)

$(NAME): make_libft obj
		gcc $(OFILES) $(LIBFT) -o $(NAME)

clean: libft_clean
	rm -f $(OFILES)

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
