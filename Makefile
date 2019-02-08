# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmeys <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 13:41:34 by hmeys             #+#    #+#              #
#    Updated: 2019/02/02 13:44:23 by hmeys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cd libft && make && cd ..
	gcc fillit.c get_next_line/get_next_line.c libft/libft.a verif/vali_tab.c verif/verif.c algo/algo.c verif/tetri_valid.c
	cd libft && make fclean
