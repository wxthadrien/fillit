# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 12:27:29 by hmeys             #+#    #+#              #
#    Updated: 2019/01/16 15:23:25 by hmeys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES=ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strcmp.c ft_strncat.c\
 ft_tolower.c ft_isascii.c ft_memchr.c ft_memset.c ft_strcpy.c ft_strncmp.c\
  ft_toupper.c ft_bzero.c ft_isdigit.c ft_memcmp.c ft_strcat.c ft_strdup.c\
	 ft_strncpy.c ft_strstr.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_isalnum.c\
	  ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_memalloc.c\
		 ft_putendl.c ft_putstr.c ft_strequ.c ft_strmap.c ft_strsub.c ft_memdel.c\
		  ft_putendl_fd.c ft_putstr_fd.c ft_striter.c ft_strmapi.c ft_strtrim.c\
			 ft_putchar.c ft_putnbr.c ft_strclr.c ft_striteri.c ft_strnequ.c\
			  ft_putchar_fd.c ft_putnbr_fd.c ft_strdel.c ft_strjoin.c ft_strnew.c\
				 ft_strsplit.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
				  ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_strcut.c
OFILES=ft_isalpha.o ft_memccpy.o ft_memmove.o ft_strcmp.o ft_strncat.o\
 ft_tolower.o ft_isascii.o ft_memchr.o ft_memset.o ft_strcpy.o ft_strncmp.o\
  ft_toupper.o ft_bzero.o ft_isdigit.o ft_memcmp.o ft_strcat.o ft_strdup.o\
	 ft_strncpy.o ft_strstr.o ft_strlcat.o ft_strnstr.o ft_atoi.o ft_isalnum.o\
	  ft_isprint.o ft_memcpy.o ft_strchr.o ft_strlen.o ft_strrchr.o ft_memalloc.o\
		 ft_putendl.o ft_putstr.o ft_strequ.o ft_strmap.o ft_strsub.o ft_memdel.o\
		  ft_putendl_fd.o ft_putstr_fd.o ft_striter.o ft_strmapi.o ft_strtrim.o\
			 ft_putchar.o ft_putnbr.o ft_strclr.o ft_striteri.o ft_strnequ.o\
			  ft_putchar_fd.o ft_putnbr_fd.o ft_strdel.o ft_strjoin.o ft_strnew.o\
				 ft_strsplit.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o\
				  ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_strcut.o
FLAGS=-Wall -Wextra -Werror
NAME=libft.a

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SOURCES) -I libft.h
		ar r libft.a $(OFILES)
		ranlib libft.a

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all
