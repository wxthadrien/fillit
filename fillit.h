/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <hmeys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:03:17 by hmeys             #+#    #+#             */
/*   Updated: 2019/03/11 13:08:17 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct		s_stock
{
	int				i;
	int				fd;
	int				ret;
	int				letter;
	int				cote;
	int				noot;
	char			*line;
}					t_stock;

typedef struct		s_coordonnees
{
	char			x;
	char			y;
}					t_coordonnees;

typedef struct		s_tetro
{
	int				p0x;
	int				p0y;
	t_coordonnees	h[4];
}					t_tetro;

typedef struct		s_calcul
{
	int				x;
	int				y;
	int				p;
	int				i;
	int				*cote;
}					t_calcul;

char				**ft_next_tab(t_stock *var, t_tetro *tetro, char **tab);
int					er(int cas, char **tab, int cote, char *line);
char				ft_afficher_tab(char **tab, int cote);
int					main(int argc, char **argv);
char				*ft_tab_to_str(char **tab);
char				**ft_copier_agrandir(char **tab, int cote);
void				ft_clean_struct(t_tetro *tetro, int num);
int					ft_number_of_tetro(int fd);
int					ft_is_valid(char **tetro_read);
int					ft_tetro_read_free(char **tetro_read);
int					ft_read(t_stock v, char *ln, char **tab,\
					char **tetro_r);
int					ft_god(t_stock var, char **tab, t_tetro *tetro,\
					char **tetro_r);
int					ft_test(char *line, char **tetro_read, t_stock *var,\
					char **tab);
void				ft_result(char **tab, t_stock *var);
int					ft_free(char *s);
int					ft_vali_tab(char *line);
char				**ft_tab_converter(char **tab);
char				ft_siri(char **tab, int x, int y);
char				ft_str_to_char(char *str);
int					ft_alexa(char **tab, int c, int x, int y);
int					ft_tetri_valid(char *tab);
char				ft_hashtag_to_letter(char c);
t_tetro				ft_calcul_place(char **tab);
char				**ft_agrandir_cote(char **tab, int cote);
void				ft_free_tab(char **tab, int n);
int					ft_backtraking(char ***tab, t_tetro *new,\
					int *cote, int num);
int					ft_check_place(t_tetro new, char **tab, int cote);
int					ft_back(char **tab, int cote, t_tetro *tetro, int letter);
t_tetro				ft_pos(t_calcul pos, t_tetro position_tetro,\
					t_tetro position_absolue);
void				ft_test_back(char ***tab, t_tetro *new, char **tab2,\
					t_calcul coord);
int					ft_under_back(t_tetro *new, char **tab2, char ***tab,\
					t_calcul coord);
#endif
