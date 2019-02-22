/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:03:17 by hmeys             #+#    #+#             */
/*   Updated: 2019/02/22 19:45:26 by losuna-b         ###   ########.fr       */
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
	int				fd;
	int				i;
	int				letter;
	int				ret;
	int				cote;
	int				no;
}					t_stock;

char				ft_afficher_tab(char **tab, int cote);
int					main(int argc, char **argv);
char				*ft_tab_to_str(char **tab);
char				**ft_copier_agrandir(char **tab, int cote);
void				ft_clean_struct(t_tetro *tetro, int num);
int					ft_number_of_tetro(int fd);
#endif
