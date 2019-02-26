/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:03:17 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/23 17:02:51 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "verif/verif.h"
# include "algo/algo.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct		s_stock
{
    int   i;
    int   fd;
    int   ret;
    int   letter;
    int   cote;
    int   noot;
}					t_stock;

char				ft_afficher_tab(char **tab, int cote);
int					main(int argc, char **argv);
char				*ft_tab_to_str(char **tab);
char				**ft_copier_agrandir(char **tab, int cote);
void				ft_clean_struct(t_tetro *tetro, int num);
int					ft_number_of_tetro(int fd);
int         ft_test(char *line, char **tetro_read, int i);
int         ft_is_valid(char **tetro_read);
int ft_god(t_stock var, char *line, char **tab, t_tetro *tetro, char **tetro_r);
#endif
